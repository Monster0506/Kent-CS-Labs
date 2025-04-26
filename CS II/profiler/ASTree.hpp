//
//  ASTree.hpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2025 Kent State University. All rights reserved.
//  Spring 2025
//  Using srcML 1.0
//
//  Modified by:
//
//

#ifndef INCLUDES_ASTree_H_
#define INCLUDES_ASTree_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <list>
#include <vector>
#include <string>
#include <algorithm>


bool                     isStopTag (std::string);
std::string              readUntil (std::istream&, char);
std::string              unEscape  (std::string);
std::vector<std::string> tokenize  (const std::string& s);

class AST;

// srcML the data structure for a srcML input file
//
// CLASS INV: Assigned(tree)
//
class srcML {
public:
            srcML     () : tree(0) {};
            ~srcML    ();
            srcML     (const srcML&);
    void    swap      (srcML&);
    srcML&  operator= (srcML);

    void    insertMainHeader    (const std::vector<std::string>&, const std::vector<std::string>&);
    void    insertFileHeader    (const std::string&);
    void    insertMainReport    (const std::vector<std::string>&);
    void    insertFunctionCount (const std::string&);
    void    insertLineCount     (const std::string&);

    friend  std::istream& operator>>(std::istream&, srcML&);
    friend  std::ostream& operator<<(std::ostream&, const srcML&);

private:
    std::string header;
    AST*        tree;
};


// AST nodes can be one of three things.
// category   - internal node of some syntactic category
// token      - a source code token
// whitespace - blanks, tabs, line returns, etc.
//
enum nodes {category, token, whitespace};

// An AST is either a:
//     -Syntactic category node
//     -Token node
//     -Whitespace node
//
// CLASS INV: if (nodeType == category)
//            than (child != 0) && (text == "")
//            if ((nodeType == token) || (nodeType == whitespace))
//            then (child == 0) && (text != "")
//
class AST {
public:
                  AST       () {};
                  AST       (nodes t) : nodeType(t) {};
                  AST       (nodes t, const std::string&);
                  ~AST      ();
                  AST       (const AST&);
    void          swap      (AST&);
    AST&          operator= (AST);

    AST*          getChild            (std::string);
    std::string   getName             () const;
    void          insertMainHeader    (const std::vector<std::string>&, const std::vector<std::string>&);
    void          insertFileHeader    (const std::string&);
    void          insertMainReport    (const std::vector<std::string>&);
    void          insertFunctionCount (const std::string&);
    void          insertLineCount     (const std::string&);
    std::ostream& print               (std::ostream&) const;
    std::istream& read                (std::istream&);

    nodes           nodeType;       //Category, Token, or Whitespace
    std::string     tag;            //Category: the tag name and
    std::string     closeTag;       //          closing tag.
    std::list<AST*> child;          //Category: A list of subtrees.
    std::string     text;           //Token/Whitespace: the text.
};




#endif
