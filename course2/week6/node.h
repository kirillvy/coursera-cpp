#pragma once

#include "date.h"
#include <string>

using namespace std;

class Node {
public:
  bool Evaluate(const Date& date, const string& event);
};

class EmptyNode : public Node {
public:

};

class DateComparisonNode : public Node {
public:

};

class EventComparisonNode : public Node {
public:

};

class LogicalOperationNode : public Node {
public:

};
