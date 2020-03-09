#include "condition_parser.h"

using namespace std;

template <class It> shared_ptr<Node> ParseComparison(It& current, It end) {
  if (current == end) {
    throw logic_error("Expected column name: date or event");
  }

  Token& column = *current;
  if (column.type != TokenType::COLUMN) {
    throw logic_error("Expected column name: date or event");
  }
  ++current;

  if (current == end) {
    throw logic_error("Expected comparison operation");
  }

  Token& op = *current;
  if (op.type != TokenType::COMPARE_OP) {
    throw logic_error("Expected comparison operation");
  }
  ++current;

  if (current == end) {
    throw logic_error("Expected right value of comparison");
  }

  Comparison cmp;
  if (op.value == "<") {
    cmp = Comparison::Less;
  } else if (op.value == "<=") {
    cmp = Comparison::LessOrEqual;
  } else if (op.value == ">") {
    cmp = Comparison::Greater;
  } else if (op.value == ">=") {
    cmp = Comparison::GreaterOrEqual;
  } else if (op.value == "==") {
    cmp = Comparison::Equal;
  } else if (op.value == "!=") {
    cmp = Comparison::NotEqual;
  } else {
    throw logic_error("Unknown comparison token: " + op.value);
  }

  const string& value = current->value;
  ++current;

  if (column.value == "date") {
    istringstream is(value);
    return make_shared<DateComparisonNode>(cmp, ParseDate(is));
  } else {
    return make_shared<EventComparisonNode>(cmp, value);
  }
}

template <class It>
shared_ptr<Node> ParseExpression(It& current, It end, unsigned precedence) {
  if (current == end) {
    return shared_ptr<Node>();
  }

  shared_ptr<Node> left;

  if (current->type == TokenType::PAREN_LEFT) {
    ++current; // consume '('
    left = ParseExpression(current, end, 0u);
    if (current == end || current->type != TokenType::PAREN_RIGHT) {
      throw logic_error("Missing right paren");
    }
    ++current; // consume ')'
  } else {
    left = ParseComparison(current, end);
  }

  const map<LogicalOperation, unsigned> precedences = {
      {LogicalOperation::Or, 1}, {LogicalOperation::And, 2}
  };

  while (current != end && current->type != TokenType::PAREN_RIGHT) {
    if (current->type != TokenType::LOGICAL_OP) {
      throw logic_error("Expected logic operation");
    }

    const auto logical_operation = current->value == "AND" ? LogicalOperation::And
                                                           : LogicalOperation::Or;
    const auto current_precedence = precedences.at(logical_operation);
    if (current_precedence <= precedence) {
      break;
    }

    ++current; // consume op

    left = make_shared<LogicalOperationNode>(
        logical_operation, left, ParseExpression(current, end, current_precedence)
    );
  }

  return left;
}

shared_ptr<Node> ParseCondition(istream& is) {
  auto tokens = Tokenize(is);
  auto current = tokens.begin();
  auto top_node = ParseExpression(current, tokens.end(), 0u);

  if (!top_node) {
    top_node = make_shared<EmptyNode>();
  }

  if (current != tokens.end()) {
    throw logic_error("Unexpected tokens after condition");
  }

  return top_node;
}


void TestParseCondition() {
  {
    istringstream is("date != 2017-11-18");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition 1");
    Assert(!root->Evaluate({2017, 11, 18}, ""), "Parse condition 2");
  }
  {
    istringstream is(R"(event == "sport event")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 3");
    Assert(!root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 4");
  }
  {
    istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition 5");
    Assert(root->Evaluate({2017, 3, 1}, ""), "Parse condition 6");
    Assert(root->Evaluate({2017, 6, 30}, ""), "Parse condition 7");
    Assert(!root->Evaluate({2017, 7, 1}, ""), "Parse condition 8");
    Assert(!root->Evaluate({2016, 12, 31}, ""), "Parse condition 9");
  }
  {
    istringstream is(R"(event != "sport event" AND event != "Wednesday")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 10");
    Assert(!root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 11");
    Assert(!root->Evaluate({2017, 1, 1}, "Wednesday"), "Parse condition 12");
  }
  {
    istringstream is(R"(event == "holiday AND date == 2017-11-18")");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(!root->Evaluate({2017, 11, 18}, "holiday"), "Parse condition 13");
    Assert(!root->Evaluate({2017, 11, 18}, "work day"), "Parse condition 14");
    Assert(root->Evaluate({1, 1, 1}, "holiday AND date == 2017-11-18"), "Parse condition 15");
  }
  {
    istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 16");
    Assert(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 17");
  }
  {
    istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(!root->Evaluate({2016, 1, 1}, "holiday"), "Parse condition 18");
    Assert(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 19");
    Assert(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 20");
    Assert(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 21");
  }
  {
    istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2016, 1, 1}, "event"), "Parse condition 22");
    Assert(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 23");
    Assert(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 24");
    Assert(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 25");
  }
  {
    istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 26");
    Assert(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 27");
  }
  {
    istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
    shared_ptr<Node> root = ParseCondition(is);
    Assert(root->Evaluate({1, 1, 1}, "2017-01-01"), "Parse condition 28");
    Assert(!root->Evaluate({2016, 1, 1}, "event"), "Parse condition 29");
    Assert(root->Evaluate({2016, 1, 2}, "event"), "Parse condition 30");
  }
}
