#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::ifstream;
using std::list;
using std::string;
using std::vector;

auto readRoster(vector<list<string>> &allStudents, string fileName) {
    ifstream course(fileName);
    if (!course) {
        std::cout << "Cannot open file: " << fileName << std::endl;
        exit(1);
    }

    string courseName = fileName.substr(0, fileName.find('.'));
    string first, last;

    while (course >> first >> last) {
        string fullName = first + " " + last;

        auto it = allStudents.begin();

        while (it != allStudents.end()) {
            if (it->front() == fullName) break;
            ++it;
        }

        if (it != allStudents.end()) {
            it->push_back(courseName);
        } else {
            list<string> newStudent;
            newStudent.push_back(fullName);
            newStudent.push_back(courseName);
            allStudents.push_back(std::move(newStudent));
        }
    }
    course.close();
}

auto readDropouts(list<string> &dropouts, string fileName) -> void {
    ifstream in(fileName);
    string first, last;
    while (in >> first >> last) {
        dropouts.push_back(first + " " + last);
    }
    in.close();
}

auto removeDropouts(vector<list<string>> &allStudents,
                    const list<string> &dropouts) -> void {
    for (auto it = allStudents.begin(); it != allStudents.end();) {
        string fullName = it->front();
        size_t spacePos = fullName.find(' ');
        string firstName = fullName.substr(0, spacePos);
        string lastName = fullName.substr(spacePos + 1);

        bool isDropout = false;
        for (const auto &dropout : dropouts) {
            size_t dropoutSpace = dropout.find(' ');
            string dropoutFirst = dropout.substr(0, dropoutSpace);
            string dropoutLast = dropout.substr(dropoutSpace + 1);

            if (firstName == dropoutFirst && lastName == dropoutLast) {
                isDropout = true;
                break;
            }
        }
        if (isDropout) {
            it = allStudents.erase(it);
        } else {
            ++it;
        }
    }
}
auto sort(const list<string> &a, const list<string> &b) -> bool {
    return a.front() < b.front();
}

auto sortStudents(vector<list<string>> &allStudents) -> void {
    std::sort(allStudents.begin(), allStudents.end(), sort);
}

auto printRoster(const vector<list<string>> &allStudents) -> void {
    std::cout << "all students, dropouts removed and sorted\n"
              << "first name last name: courses enrolled\n";
    for (const auto &student : allStudents) {
        for (auto it = student.begin(); it != student.end(); ++it) {
            std::cout << *it << "\t";
        }
        std::cout << std::endl;
    }
}

auto main(int argc, char *argv[]) -> int {
    if (argc <= 2) {
        std::cout << "usage: " << argv[0] << " list of courses, dropouts last"
                  << std::endl;
        exit(1);
    }

    vector<list<string>> allStudents;

    for (int i = 1; i < argc - 1; ++i) readRoster(allStudents, argv[i]);

    list<string> dropouts;
    readDropouts(dropouts, argv[argc - 1]);

    removeDropouts(allStudents, dropouts);

    sortStudents(allStudents);

    printRoster(allStudents);
}
