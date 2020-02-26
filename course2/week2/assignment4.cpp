#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(string input) {
  int size = input.size();
  int middle = size / 2; 
  while (middle--) {
    if (input[middle] != input[size-middle-1]) {
      return false;
    }
  }
  return true;
}

void testCorrect() {
  AssertEqual(IsPalindrom(""), true, "empty");
  AssertEqual(IsPalindrom("a"), true, "one symbol");
  AssertEqual(IsPalindrom("madam"), true, "madam");
  AssertEqual(IsPalindrom("maddam"), true, "maddam");
  AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "wasitacaroracatisaw");
  AssertEqual(IsPalindrom("wasitaca ror acatisaw"), true, "wasitaca ror acatisaw");
}


void testFail() {
  AssertEqual(IsPalindrom("aab"), false, "3 symbol");
  AssertEqual(IsPalindrom("ab"), false, "2 symbol");
  AssertEqual(IsPalindrom("aab "), false, "space end");
  AssertEqual(IsPalindrom("aaa "), false, "space end");
  AssertEqual(IsPalindrom("aa a"), false, "space middle correct");
  AssertEqual(IsPalindrom("a ab"), false, "space");
  AssertEqual(IsPalindrom("babgab"), false, "middle wrong");
}

int main() {
  TestRunner runner;
  runner.RunTest(testFail, "testFail");
  runner.RunTest(testCorrect, "testCorrect");
  // добавьте сюда свои тесты
  return 0;
}
