#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
  Person(const string& name, const string& type)
      : name_(name), type_(type) {}

  virtual void Walk(const string& destination) const {
    doAction("walks to", destination);
  }
  void doAction(const string& action) const {
    cout << type_ << ": " << name_ << ' ' << action << endl;
  }
  void doAction(const string& action, const string& destination) const {
    cout << type_ << ": " << name_ << ' ' << action << ": " << destination << endl;
  }
  string Name() const {
    return name_;
  }
  string Type() const {
    return type_;
  }

private:
  const string name_;
  const string type_;
};

class Student : public Person {
public:
  Student(const string& name, const string& favouriteSong)
      : Person(name, "Student"), FavouriteSong(favouriteSong) {}

  void Learn() const {
    doAction("learns");
  }

  void Walk(const string &destination) const override {
    Person::Walk(destination);
    SingSong();
  }

  void SingSong() const {
    doAction("sings a song", FavouriteSong);
  }

private:
  const string FavouriteSong;
};

class Teacher : public Person {
public:
  Teacher(const string& name, const string& subject)
      : Person(name, "Teacher"), Subject(subject) {}

  void Teach() const {
    doAction("teaches", Subject);
  }

private:
  const string Subject;
};

class Policeman : public Person {
public:
  Policeman(const string& name)
      : Person(name, "Policeman") {}

  void Check(const Person& p) const {
    cout << Type() << ": " << Name() << " checks "
         << p.Type() << ". " << p.Type() << "'s name is: "
         << p.Name() << endl;
  }
};

void VisitPlaces(const Person &t, const vector<string>& places) {
  for (auto p : places) {
    t.Walk(p);
  }
}

int main() {
  Teacher t("Jim", "Math");
  Student s("Ann", "We will rock you");
  Policeman p("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
