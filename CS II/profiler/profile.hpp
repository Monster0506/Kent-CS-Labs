//
//  profile.hpp
//
//  Created by Jonathan Maletic.
//  Copyright 2024 Kent State University. All rights reserved.
//  Spring 2024
//  Modified by:
//

#ifndef INCLUDES_PROFILE_H_
#define INCLUDES_PROFILE_H_

#include <iostream>
#include <cassert>
#include <string>
#include <map>

std::string intToString(long);


//  A map of:
//   line number OR line number & function name
//   X
//   the number of times each is called
//
//  Line&Name    Count
//  10           5
//  20 bar       2
//  5 main       1
//  11           5
// 
class profile {
public:
           profile (std::string fn="") : filename(fn)      {};
    void   count   (int line, const std::string& function) { stmt[intToString(line) + " " + function] += 1; }
    void   count   (int line)                              { stmt[intToString(line)] += 1; }
    
    friend std::ostream& operator<< (std::ostream&, const profile&);
private:
    std::string                 filename;
    std::map<std::string, int>  stmt;      // (line# X times called)
};


#endif
