#include <vector>
#include <fstream>
#include <iostream>
#include "../assembler/stack.hpp"
#include "../string/string.hpp"

String infix2prefix(const String& expr) {
    if (expr.length() == 0 || expr[expr.length() - 2] != ';') {
        return String("Error: Expression must end with semicolon");
    }

    stack<String> S;
    std::vector<String> tokens = expr.split(' ');
    for (int i = tokens.size() - 1; i >= 0; --i) {
        String t = tokens[i];
        
        if (t == ")") {
            S.push(t);
        } else if (t == "(") {
            String rhs = S.pop();
            String op = S.pop();
            String lhs = S.pop();
            S.pop();
            
            String result = op + " " + lhs + " " + rhs;
            S.push(result);
        } else if (t != ";") {
            S.push(t);
        }
    }
    
    return S.pop();
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        std::cout << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    String line;
    char buffer[1024];
    while (inFile.getline(buffer, sizeof(buffer))) {
        line = String(buffer);
        String result = infix2prefix(line);
        std::cout << result << std::endl;
    }

    inFile.close();
    return 0;
}

