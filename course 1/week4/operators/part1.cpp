
#include <iostream>
#include <cmath>
using namespace std;

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

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
