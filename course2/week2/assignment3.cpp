
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


int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

class Rational {
public:
  Rational() {
      // Реализуйте конструктор по умолчанию
      numerator_val = 0;
      denominator_val = 1;
  }

  Rational(int numerator, int denominator) {
      // Реализуйте конструктор
      if (numerator == 0) {
        denominator = 1;
      }
      if (denominator < 0) {
          numerator *= -1;
          denominator *= -1;
      }
      int divider = gcd(numerator, denominator);

      numerator_val = numerator / divider;
      denominator_val = denominator / divider;
  }

  int Numerator() const {
      // Реализуйте этот метод
      return numerator_val;
  }

  int Denominator() const {
      // Реализуйте этот метод
      return denominator_val;
  }

private:
  // Добавьте поля
  int numerator_val;
  int denominator_val;
};

void TestEmpty() {
  Rational a;
  AssertEqual(a.Numerator(), 0, "empty test num");
  AssertEqual(a.Denominator(), 1, "empty test den");
}

void TestZero() {
  Rational a(0, 42);
  AssertEqual(a.Numerator(), 0, "empty test num");
  AssertEqual(a.Denominator(), 1, "empty test den");
}


void TestNegative() {
  Rational a(1, -1);
  AssertEqual(a.Numerator(), -1, "negative test num");
  AssertEqual(a.Denominator(), 1, "negative test den");

  Rational b(-1, -1);
  AssertEqual(b.Numerator(), 1, "negative test 2 num");
  AssertEqual(b.Denominator(), 1, "negative test 2 den");
}


void TestGcd() {
  Rational a(12, 6);
  AssertEqual(a.Numerator(), 2, "negative test num");
  AssertEqual(a.Denominator(), 1, "negative test den");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestZero, "TestZero");
  runner.RunTest(TestNegative, "TestNegative");
  runner.RunTest(TestGcd, "TestGcd");
  // добавьте сюда свои тесты
  return 0;
}
