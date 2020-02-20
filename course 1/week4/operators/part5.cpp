#include <iostream>
#include <map>
#include <set>
#include <vector>
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

istream& operator>>(istream& is, Rational& input) {
    int numerator, denominator;
    if (is) {
        is >> numerator;
        is.ignore(1);
        is >> denominator;
        is.ignore(1);
        input = {numerator, denominator};
    }
    return is;
}
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator<(const Rational& first, const Rational& second) {
    return first.Numerator() * second.Denominator() < second.Numerator() * first.Denominator();
}

bool operator>(const Rational& first, const Rational& second) {
    return first.Numerator() * second.Denominator() > second.Numerator() * first.Denominator();
}


int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}