#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::list;
using std::move;
using std::set;
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

void readRoster(set<Student>& roster, string fileName) {
    ifstream course(fileName);
    if (!course) {
        cout << "Cannot open file: " << fileName << endl;
        exit(1);
    }

    string courseName = fileName.substr(0, fileName.find('.'));
    string first, last;

    while (course >> first >> last) {
        Student s(first, last);
        roster.insert(s);
    }
    course.close();
}

void printRoster(const set<Student>& roster) {
    for (const auto& student : roster) {
        cout << student.print();
        cout << endl;
    }
}
int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "usage: " << argv[0] << " list of courses, dropouts last"
             << endl;
        exit(1);
    }

    set<Student> allStudents;

    for (int i = 1; i < argc - 1; ++i) {
        readRoster(allStudents, argv[i]);
    }

    set<Student> dropouts;
    readRoster(dropouts, argv[argc - 1]);

    for (const auto& d : dropouts) {
        allStudents.erase(d);
    }

    cout << "Currently Enrolled Students\n";
    printRoster(allStudents);
}
