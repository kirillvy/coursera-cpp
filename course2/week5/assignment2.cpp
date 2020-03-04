#include <vector>
#include <memory>
#include <ios>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт shared_ptr<Rect>, shared_ptr<Triangle> или shared_ptr<Circle>.
 */

class Figure {
public:
  Figure(const string& name)
    : name_(name) {}
  virtual string Name() const = 0;
  virtual double Perimeter() const = 0;
  virtual double Area() const = 0;
protected:
  double perimeter_;
  double area_;
  const string name_;
};

class Triangle : public Figure {
public:
  Triangle(const int& a, const int& b, const int& c)
    : Figure("TRIANGLE") {
      double p = a+b+c;
      perimeter_ = p;
      p /= 2;
      area_ = sqrt(p * (p-a) * (p-b) * (p-c));
    }
  string Name() const {
    return name_;
  }
  double Perimeter() const {
    return perimeter_;
  }
  double Area() const {
    return area_;
  }
};

class Rect : public Figure {
public:
  Rect(const int& a, const int& b)
  : Figure("RECT") {
    perimeter_ = (a + b) * 2;
    area_ = a * b;
  }
  string Name() const {
    return name_;
  }
  double Perimeter() const {
    return perimeter_;
  }
  double Area() const {
    return area_;
  }
};
class Circle : public Figure {
public:
  Circle(const int& a)
    : Figure("CIRCLE") {
      perimeter_ = 2 * 3.14 * a;
      area_ = 3.14 * pow(a, 2);
    }
  string Name() const {
    return name_;
  }
  double Perimeter() const {
    return perimeter_;
  }
  double Area() const {
    return area_;
  }
};

shared_ptr<Figure> CreateFigure(istringstream& is){
  string type;
  int a, b, c;
  shared_ptr<Figure> x;

  is >> type;

  if (type == "CIRCLE") {
    is >> a;
    x = make_shared<Circle>(a);
  } else if (type == "RECT") {
    is >> a >> b;
    x = make_shared<Rect>(a, b);
  } else if (type == "TRIANGLE") {
    is >> a >> b >> c;
    x = make_shared<Triangle>(a, b, c);
  }

  return x;
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}