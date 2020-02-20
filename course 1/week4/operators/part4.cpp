#include <iostream>
#include <sstream>
#include <ios>
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
// Реализуйте для класса Rational операторы << и >>

ostream& operator<<(ostream& os, const Rational& output) {
    os << output.Numerator() << '/' << output.Denominator();
    return os;
}

istream& operator>>(istream& istr, Rational& input) {
    int numerator, denominator;
    char drob;
    istr >> numerator >> drob >> denominator;
    if (istr && drob == '/') {
        input = {numerator, denominator};
    }

    return istr;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
