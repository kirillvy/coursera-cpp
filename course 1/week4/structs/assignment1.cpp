#include <string>
using namespace std;

struct Specialization {
    string value;
    explicit Specialization(const string& newValue) {
        value = newValue;
    }
};

struct Course {
    string value;
    explicit Course(const string& newValue) {
        value = newValue;
    }
};

struct Week {
    string value;
    explicit Week(const string& newValue) {
        value = newValue;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  explicit LectureTitle(
    const Specialization& newSpec,
    const Course& newCourse,
    const Week& newWeek
  ) {
    specialization = newSpec.value;
    course = newCourse.value;
    week = newWeek.value;
  }
};

int main() {
  LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
  );

  return 0;
}
