#pragma once

#include "node.h"
#include "token.h"
#include "test_runner.h"

#include <memory>
#include <iostream>
#include <map>

using namespace std;

shared_ptr<Node> ParseCondition(istream& is);

void TestParseCondition();
