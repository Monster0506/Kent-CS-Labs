#include "string.hpp"
#include <cassert>
#include <vector>
#include <new>

String::String() {
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

String::String(char ch) {
    stringSize = (ch == '\0') ? 1 : 2;
    str = new char[stringSize];
    str[0] = ch;
    if (ch != '\0') str[1] = '\0';
}

String::String(const char ch[]) {
    int len = 0;
    while (ch[len] != '\0') {
        len++;
    }

    stringSize = len + 1;
    str = new char[stringSize];

    for (int i = 0; i < len; i++) {
        str[i] = ch[i];
    }

    str[len] = '\0'; 
}


String::String(const String& other) {
    stringSize = other.stringSize;
    str = new char[stringSize];

    int i = 0;
    while (other.str[i] != '\0') {
        str[i] = other.str[i];
        i++;
    }
    str[i] = '\0'; 
}


String::~String() {
    delete[] str;
}

void String::swap(String& other) {
    char* tempStr = str;
    int tempSize = stringSize;

    str = other.str;
    stringSize = other.stringSize;

    other.str = tempStr;
    other.stringSize = tempSize;
}


String& String::operator=(String other) {
    swap(other);
    return *this;
}

int String::capacity() const {
    return length();
}

int String::length() const {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}


char& String::operator[](int index) {
    assert(index >= 0 && index < length());
    return str[index];
}

char String::operator[](int index) const {
    assert(index >= 0 && index < length());
    return str[index];
}

String& String::operator+=(const String& rhs) {
    int rhsLength = rhs.length();
    int newSize = length() + rhsLength + 1;
    char* newStr = new char[newSize];

    int i = 0;
    while (str[i] != '\0') {
        newStr[i] = str[i];
        i++;
    }

    int j = 0;
    while (rhs.str[j] != '\0') {
        newStr[i + j] = rhs.str[j];
        j++;
    }

    newStr[i + j] = '\0'; 
    delete[] str;
    str = newStr;
    stringSize = newSize;
    return *this;
}


bool String::operator==(const String& rhs) const {
    int i = 0;
    while (str[i] != '\0' && rhs.str[i] != '\0') {
        if (str[i] != rhs.str[i]) {
            return false;
        }
        i++;
    }
    return str[i] == rhs.str[i];
}


bool String::operator<(const String& rhs) const {
    int i = 0;
    while (str[i] != '\0' && rhs.str[i] != '\0') {
        if (str[i] < rhs.str[i]) {
            return true;
        }
        if (str[i] > rhs.str[i]) {
            return false;
        }
        i++;
    }
    return str[i] == '\0' && rhs.str[i] != '\0';
}


String String::substr(int start, int end) const {
    String result;
    for (int i = start; i <= end; i++) {
        result += str[i];
    }
    return result;
}


int String::findch(int start, char ch) const {
    for (int i = start; i < length(); i++) {
        if (str[i] == ch) return i;
    }
    return -1;
}

int String::findstr(int start, const String& s) const {
    int len = s.length();
    for (int i = start; i <= length() - len; i++) {
        if (substr(i, i + len - 1) == s) return i;
    }
    return -1;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
    out << rhs.str;
    return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
    char buffer[256];
    in >> buffer;
    rhs = String(buffer);
    return in;
}

String operator+(String lhs, const String& rhs) {
    return lhs += rhs;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

bool operator==(const char lhs[], const String& rhs) {
    int i = 0;
    while (lhs[i] && rhs[i]) {
        if (lhs[i] != rhs[i]) return false;
        ++i;
    }
    return lhs[i] == rhs[i];
}

bool operator==(char lhs, const String& rhs) {
    return (rhs.length() == 1 && rhs[0] == lhs);
}

bool operator<(const char lhs[], const String& rhs) {
    int i = 0;
    while (lhs[i] && rhs[i]) {
        if (lhs[i] < rhs[i]) return true;
        if (lhs[i] > rhs[i]) return false;
        ++i;
    }
    return lhs[i] < rhs[i];
}

bool operator<(char lhs, const String& rhs) {
    return (rhs.length() > 0 && lhs < rhs[0]);
}

bool operator<=(const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}


bool operator>=(const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}

bool operator>(const String& lhs, const String& rhs) {
    return rhs < lhs;
}

std::vector<String> String::split(char delimiter) const {
    std::vector<String> result;
    int start = 0;
    int pos;
    
    while ((pos = findch(start, delimiter)) != -1) {
        result.push_back(substr(start, pos - 1));
        start = pos + 1;
    }
    
    result.push_back(substr(start, length() - 1));
    return result;
}
