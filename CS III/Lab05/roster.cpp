#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::map;
using std::move;
using std::string;
using std::vector;

class Student {
   public:
    Student(string firstName, string lastName)
        : firstName_(std::move(firstName)), lastName_(std::move(lastName)) {}

    void addCourse(const string& course) { courses_.push_back(course); }

    string print() const {
        string result = firstName_ + " " + lastName_;
        return result;
    }

    const string& firstName() const { return firstName_; }
    const string& lastName() const { return lastName_; }

    friend bool operator==(Student left, Student right) {
        return left.lastName_ == right.lastName_ &&
               left.firstName_ == right.firstName_;
    }

    friend bool operator<(const Student& left, const Student& right) {
        string leftFull = left.firstName_ + " " + left.lastName_;
        string rightFull = right.firstName_ + " " + right.lastName_;
        return leftFull < rightFull;
    }

    list<string> courses_;

   private:
    string firstName_;
    string lastName_;
};

void readRoster(map<Student, list<string>>& roster, string fileName) {
    ifstream course(fileName);
    if (!course) {
        cout << "Cannot open file: " << fileName << endl;
        exit(1);
    }

    string courseName = fileName.substr(0, fileName.find('.'));
    string first, last;

    while (course >> first >> last) {
        Student s(first, last);
        roster[s].push_back(courseName);
    }
    course.close();
}

void printRoster(const map<Student, list<string>>& roster) {
    for (const auto& student : roster) {
        cout << student.first.print() << ":";
        for (const auto& c : student.second) {
            cout << c << " ";
        }
        cout << endl;
    }
}
int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "usage: " << argv[0] << " list of courses, dropouts last"
             << endl;
        exit(1);
    }

    map<Student, list<string>> allStudents;

    for (int i = 1; i < argc - 1; ++i) {
        readRoster(allStudents, argv[i]);
    }

    map<Student, list<string>> dropouts;
    readRoster(dropouts, argv[argc - 1]);

   for (const auto& d : dropouts) {
      allStudents.erase(d.first);
   }

    cout << "all students, dropouts removed and sorted\n"
         << "first name last name: courses enrolled\n";
    printRoster(allStudents);
}
