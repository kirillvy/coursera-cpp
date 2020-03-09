#include "node.h"
#include "date.h"

DateComparisonNode::DateComparisonNode(
  const Comparison& cmp,
  const Date& value) : c(cmp), v(value){}

EventComparisonNode::EventComparisonNode(
  const Comparison& cmp,
  const string& value) : c(cmp), v(value){}

LogicalOperationNode::LogicalOperationNode(
    const LogicalOperation& operation,
    const shared_ptr<Node> left,
    const shared_ptr<Node> right) : 
    lo(operation), l(left), r(right){}


bool EmptyNode::Evaluate(const Date date, const string event){
  return true;
}

template<class T>
bool compare(Comparison c, T lhs, T rhs) {
  switch (c)
  {
  case Comparison::Equal:
    return lhs == rhs;
    break;
  case Comparison::Greater:
    return lhs > rhs;
    break;
  case Comparison::GreaterOrEqual:
    return lhs >= rhs;
    break;
  case Comparison::Less:
    return lhs < rhs;
    break;
  case Comparison::LessOrEqual:
    return lhs <= rhs;
    break;
  case Comparison::NotEqual:
    return lhs != rhs;
    break;
  default:
    return false;
    break;
  }
}

bool DateComparisonNode::Evaluate(const Date date, const string event){
  return compare(c, date, v);
}

bool EventComparisonNode::Evaluate(const Date date, const string event){
  return compare(c, event, v);
}

bool LogicalOperationNode::Evaluate(const Date date, const string event) {
  auto lhs = l->Evaluate(date, event);
  auto rhs = r->Evaluate(date, event);
  switch (lo)
  {
  case LogicalOperation::And:
    return lhs && rhs;
    break;
  case LogicalOperation::Or:
    return lhs || rhs;
    break;
  default:
    return false;
    break;
  }
}