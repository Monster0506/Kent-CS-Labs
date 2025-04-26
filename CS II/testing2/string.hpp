#ifndef JM_NEWSTR_H_
#define JM_NEWSTR_H_

//File:        string.h   
//       
//Version:     1.0
//Date:        10/9/2023 - Current Version Kent State University

//Author:      Dr. J. Maletic
//
//Description: Class definition for a String.
//
//
//  Class: String 
//
//  Simple version with fixed sized array of char.  
//
//  Defines a character String data type with associated operators.
//  Examples:  String a;              //of capacity DEFAULT_STRING_CAPACITY
//
//  - Strings are indexed from 0 to capacity-1 of char.
//  - a = ""; assigns a to the empty String.


#include <iostream>
#include <cassert>

const int DEFAULT_STRING_CAPACITY = 256;

//
// CLASS INV: 0 <= length() < DEFAULT_STRING_CAPACITY  && 
//            str[length()] == 0
//            
class String {
public: 
            String        ();               
            String        (const char[]); 
            String        (const char);
            String        (const String &rhs);
            ~String       ();
    bool    operator<     (const String&)           const;
    bool    operator==    (const String&)           const;
    int     length()                                const;
    int     capacity()                              const;
    String&  operator=    (String);
    String&  operator+=   (const String&);


  friend  std::ostream& operator<<(std::ostream&, const String &);

private:  
    char    str[DEFAULT_STRING_CAPACITY];  
};

bool    operator<=     (const String&, const String&);
bool    operator<      (const char*,   const String&);
bool    operator<      (const char,    const String&);
String  operator+      (String, const String&);


#endif
