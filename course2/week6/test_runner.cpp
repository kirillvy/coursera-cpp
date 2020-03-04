#include "test_runner.h"

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint)
{
  if (t != u)
  {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty())
    {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string &hint)
{
  AssertEqual(b, true, hint);
}

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name)
{
  try
  {
    func();
    cerr << test_name << " OK" << endl;
  }
  catch (exception &e)
  {
    ++fail_count;
    cerr << test_name << " fail: " << e.what() << endl;
  }
  catch (...)
  {
    ++fail_count;
    cerr << "Unknown exception caught" << endl;
  }
}

TestRunner::~TestRunner()
{
  if (fail_count > 0)
  {
    cerr << fail_count << " unit tests failed. Terminate" << endl;
    exit(1);
  }
}

bool IsPalindrom(string input)
{
  int size = input.size();
  int middle = size / 2;
  while (middle--)
  {
    if (input[middle] != input[size - middle - 1])
    {
      return false;
    }
  }
  return true;
}