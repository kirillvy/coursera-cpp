#pragma once

#include "date.h"
#include <string>
#include <memory>

using namespace std;



enum class Comparison {
  Less,
  LessOrEqual,
  Greater,
  GreaterOrEqual,
  Equal,
  NotEqual
};

enum class LogicalOperation{
  And,
  Or
};

class Node {
public:
  virtual bool Evaluate(const Date date, const string event) = 0;
};

class EmptyNode : public Node {
public:
  bool Evaluate (const Date date, const string event) override;
};

class DateComparisonNode : public Node {
public:
  DateComparisonNode(const Comparison& cmp, const Date& value);
  bool Evaluate (const Date date, const string event) override;
private:
  const Comparison c;
  const Date v;
};

class EventComparisonNode : public Node {
public:
  EventComparisonNode(const Comparison& cmp, const string& value);
  bool Evaluate (const Date date, const string event) override;
private:
  const Comparison c;
  const string v;
};

class LogicalOperationNode : public Node {
public:
  LogicalOperationNode(const LogicalOperation& operation,
    const shared_ptr<Node> left,
    const shared_ptr<Node> right);
  bool Evaluate (const Date date, const string event) override;
private:
  const LogicalOperation lo;
  const shared_ptr<Node> l;
  const shared_ptr<Node> r;
};
