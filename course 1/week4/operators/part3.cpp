#include <iostream>
using namespace std;


class Rational
{
public:
    Rational()
    {
        // Реализуйте конструктор по умолчанию
        numerator_val = 0;
        denominator_val = 1;
    }

    Rational(int numerator, int denominator)
    {
        // Реализуйте конструктор
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        int divider = gcd(numerator, denominator);

        numerator_val = numerator / divider;
        denominator_val = denominator / divider;
    }
    int Numerator() const
    {
        // Реализуйте этот метод
        return numerator_val;
    }

    int Denominator() const
    {
        // Реализуйте этот метод
        return denominator_val;
    }

private:
    // Добавьте поля
    int numerator_val;
    int denominator_val;
    int gcd(int a, int b) const
    {
        a = abs(a);
        b = abs(b);
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        return a + b;
    }
};

Rational operator+(const Rational& first, const Rational& second) {
    int denominator = first.Denominator() * second.Denominator();
    int numerator = first.Numerator() * second.Denominator() + second.Numerator() * first.Denominator();

    return Rational{numerator, denominator};
}

Rational operator-(const Rational& first, const Rational& second) {
    int denominator = first.Denominator() * second.Denominator();
    int numerator = first.Numerator() * second.Denominator() - second.Numerator() * first.Denominator();

    return Rational{numerator, denominator};
}
bool operator==(const Rational& first, const Rational& second) {
    return first.Numerator() == second.Numerator() && first.Denominator() == second.Denominator();
}
// Реализуйте для класса Rational операторы * и /

Rational operator*(const Rational& first, const Rational& second) {
    int denominator = first.Denominator() * second.Denominator();
    int numerator = first.Numerator() * second.Numerator();

    return Rational{numerator, denominator};
}
Rational operator/(const Rational& first, const Rational& second) {
    int denominator = first.Denominator() * second.Numerator();
    int numerator = first.Numerator() * second.Denominator();

    return Rational{numerator, denominator};
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
