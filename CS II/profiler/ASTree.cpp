//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2025 Kent State University. All rights reserved.
//  Spring 2025
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Destructor for srcML
//
srcML::~srcML() {
    delete tree;
}


// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::insertMainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->insertMainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::insertFileHeader(const std::string& profileName) {
    tree->insertFileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::insertMainReport(const std::vector<std::string>& profileName) {
        tree->insertMainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::insertFunctionCount(const std::string& profileName) {
    tree->insertFunctionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::insertLineCount(const std::string& profileName) {
    tree->insertLineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    for (std::list<AST*>::iterator it = child.begin(); it != child.end(); ++it) {
        delete *it;
    }
    child.clear();
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    nodeType  = actual.nodeType;
    tag       = actual.tag;
    closeTag  = actual.closeTag;
    text      = actual.text;

    for (std::list<AST*>::const_iterator it = actual.child.begin(); it != actual.child.end(); ++it) {
        child.push_back(new AST(**it));
    }
}



// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    nodes tempNodeType = nodeType;
    nodeType = rhs.nodeType;
    rhs.nodeType = tempNodeType;

    std::string tempTag = tag;
    tag = rhs.tag;
    rhs.tag = tempTag;

    std::string tempCloseTag = closeTag;
    closeTag = rhs.closeTag;
    rhs.closeTag = tempCloseTag;

    std::string tempText = text;
    text = rhs.text;
    rhs.text = tempText;

    std::list<AST*> tempChild = child;
    child = rhs.child;
    rhs.child = tempChild;
}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}

static AST* makeStmt(const std::string & tagName,
    const std::string & line) {
AST* node = new AST(category, tagName);
std::vector<std::string> toks = tokenize(line);
for (auto & t : toks) {
AST* piece;
if (isspace(t[0])) piece = new AST(whitespace, t);
else              piece = new AST(token,      t);
node->child.push_back(piece);
}
return node;
}
//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::insertMainHeader(const std::vector<std::string>& profileName,
    const std::vector<std::string>& fileName) {
// 1) Find insertion point: before first function
auto it = child.begin();
while (it != child.end() && (*it)->tag != "function")
++it;

// 2) Build a list of new nodes: include + each profile declaration
std::list<AST*> headerNodes;
headerNodes.push_back(
makeStmt("cpp:include", "#include \"profile.hpp\"\n")
);
for (size_t i = 0; i < profileName.size() && i < fileName.size(); ++i) {
std::string decl = "profile " + profileName[i] +
    "(\"" + fileName[i] + "\");\n";
headerNodes.push_back(makeStmt("decl_stmt", decl));
}

// 3) Splice them into our AST children
child.splice(it, headerNodes);
}





//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::insertFileHeader(const std::string& profileName) {
    // 1) Find insertion point: before first function
    auto it = child.begin();
    while (it != child.end() && (*it)->tag != "function")
        ++it;

    // 2) Build nodes
    std::list<AST*> headerNodes;
    headerNodes.push_back(
        makeStmt("cpp:include", "#include \"profile.hpp\"\n")
    );
    std::string ext = "extern profile " + profileName + ";\n";
    headerNodes.push_back(makeStmt("decl_stmt", ext));

    // 3) Splice into AST
    child.splice(it, headerNodes);
}




// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::insertMainReport(const std::vector<std::string>& profileName) {
    // 1) Find the main function
    for (auto& node : child) {
        if (node->tag == "function") {
            AST* nameNode = node->getChild("name");
            if (!nameNode || nameNode->getName() != "main") continue;

            // 2) Navigate to <block> -> <block_content>
            AST* block = node->getChild("block");
            if (!block) return;
            AST* content = block->getChild("block_content");
            if (!content) return;

            // 3) Find <return> in content, moving backward
            auto it = content->child.end();
            if (it == content->child.begin()) return;
            --it;

            while (it != content->child.begin() && (*it)->tag != "return") {
                --it;
            }

            if ((*it)->tag != "return") return;  // Didn't find return

            // 4) Construct the cout AST line
            for (const std::string& name : profileName) {
                std::string line = "std::cout << " + name + " << std::endl;";
                AST* stmt = new AST(category, "expr_stmt");
                std::vector<std::string> tokens = tokenize(line);
                for (const std::string& t : tokens) {
                    AST* part = isspace(t[0]) ? new AST(whitespace, t)
                                              : new AST(token, t);
                    stmt->child.push_back(part);
                }

                // 5) Insert before the return statement
                content->child.insert(it, stmt);
            }
            break;  // Only one main
        }
    }
}



// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::insertFunctionCount(const std::string& profileName) {
    for (std::list<AST*>::iterator it = child.begin(); it != child.end(); ++it) {
        AST* node = *it;
        if (node->tag == "function" || node->tag == "constructor" || node->tag == "destructor") {
            std::string funcName = node->getChild("name")->getName();

            AST* block = node->getChild("block");
            if (!block) continue;
            AST* content = block->getChild("block_content");
            if (!content) continue;

            // Create new <expr_stmt> node
            AST* stmt = new AST(category, "expr_stmt");

            std::string code = profileName + ".count(__LINE__, \"" + funcName + "\");";
            std::vector<std::string> tokens = tokenize(code);

            for (const std::string& tok : tokens) {
                AST* piece;
                if (isspace(tok[0])) piece = new AST(whitespace, tok);
                else piece = new AST(token, tok);
                stmt->child.push_back(piece);
            }

            content->child.push_front(stmt);
        }
    }

    // Recurse into children (if there are nested units, e.g. namespaces or classes)
    for (std::list<AST*>::iterator it = child.begin(); it != child.end(); ++it) {
        if ((*it)->nodeType == category) {
            (*it)->insertFunctionCount(profileName);
        }
    }
}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::insertLineCount(const std::string& profileName) {

    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing
    
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST         *subtree;
    std::string temp;
    char        ch;
    
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

