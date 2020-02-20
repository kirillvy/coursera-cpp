#include <iostream>
#include <exception>
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
        if (denominator == 0) {
            throw invalid_argument("0");
        }
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
    if (second.Numerator() == 0) {
        throw domain_error("0");
    }
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
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
bool operator<(const Rational& first, const Rational& second) {
    return first.Numerator() * second.Denominator() < second.Numerator() * first.Denominator();
}

bool operator>(const Rational& first, const Rational& second) {
    return first.Numerator() * second.Denominator() > second.Numerator() * first.Denominator();
}

// Вставьте сюда реализацию operator / для класса Rational

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
