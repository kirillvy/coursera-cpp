#pragma once

#include <iostream>
#include <stdexcept>
#include <sstream>

using namespace std;


template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {});

void Assert(bool b, const string& hint);

class TestRunner {
public:
  ~TestRunner();
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name);
private:
  int fail_count = 0;
};
