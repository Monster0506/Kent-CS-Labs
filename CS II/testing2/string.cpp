//File:				string.cpp	 
//			 
//Version:		 1.0
//Date:				10/9/2023 - Current Version Kent State University
//
//Author:			Dr. J. Maletic
//
//Description: -Implementation of simple String class member functions. 
//						 


#include "string.hpp"


//
// Default Constructor
// ENSURES: str[0] == 0 
//
String::String() { 
			str[0] = 0;
} 


//
// ENSURES: str == s
// Example:	String("abcd")
//
String::String(const char s[]) {
		int i = 0;
		while (s[i] != 0) {
				str[i] = s[i];
				i++;
				if (i >= DEFAULT_STRING_CAPACITY-1) break;
		}
		str[i] = 0;
} 

//
// String('x')
//
String::String(char ch) {
		str[0] = ch;
		str[1] = 0;
}

String::~String() { }
//
//Less Than
//
bool String::operator<(const String& rhs)	const {
		int	i = 0;
		//Find first non equal characters
		while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]))	++i;
		
		/* if (str[i] == 0) return true;													 //"aa" < "aaaaa" */
		if (str[i] < rhs.str[i]) return true;									 //"aa" < "ab"
		return false;
}

bool operator<=(const String& lhs, const String& rhs) { return !(rhs < lhs);			 }

bool operator<(const char *lhs, const String& rhs) {
		return String(lhs) < rhs;
}

bool operator<(const char lhs, const String& rhs) {
		return String(lhs) < rhs;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
		out << rhs.str;
		return out;
}

int String::length() const{
		int size = 0;
		while(str[size]!=0)
				size++;
		
		return size;
}

int String::capacity() const {
		return length();
}



bool String::operator==(const String &rhs) const {
		int i = 0;
		while (str[i] != 0 && rhs.str[i] != 0){
				if (str[i]!=rhs.str[i]) return false;
				i++;
		}
		return str[i]==rhs.str[i];
}

String::String (const String &rhs){
int i = 0;
while (rhs.str[i] != '\0' && i < DEFAULT_STRING_CAPACITY - 1) {
		str[i] = rhs.str[i];
		++i;
}
str[i] = '\0'; 
}

String& String::operator= (String rhs)
{
		char temp[DEFAULT_STRING_CAPACITY];

		
				int i = 0;
				while (rhs.str[i]!=0 && i<DEFAULT_STRING_CAPACITY-1){
						temp[i]=rhs.str[i];
						i++;
				}
				temp[i] = 0;
		i = 0;
		while(temp[i] != 0){
				str[i]=temp[i];
				i++;
		}
		str[i]=0;

		return *this;
}


String& String::operator+=(const String& rhs) {
		int current_length = length();
		int rhs_length = rhs.length();

		int i = 0;
		while (rhs.str[i] != '\0' && (current_length + i) < DEFAULT_STRING_CAPACITY - 1) {
				str[current_length + i] = rhs.str[i];
				++i;
		}

		str[current_length + i] = '\0';

		return *this;
}



String	operator+	(String lhs, const String &rhs){
		lhs += rhs;
		return lhs;
}
