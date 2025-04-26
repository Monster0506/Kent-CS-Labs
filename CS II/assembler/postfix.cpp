//
// File: postfix.cpp
//
// Description: Main program for infix to postfix conversion
//

#include "../string/string.hpp"
#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {
  // Check command line arguments
  if (argc < 2) {
    std::cerr << "Usage: postfix <input_file> [output_file]\n";
    return EXIT_FAILURE;
  }

  // Open input file
  std::ifstream in(argv[1]);
  if (!in.is_open()) {
    std::cerr << "Error: Cannot open input file " << argv[1] << "\n";
    return EXIT_FAILURE;
  }

  // Open output file or use cout
  std::ofstream out;
  std::ostream *output = &std::cout;
  if (argc > 2) {
    out.open(argv[2]);
    if (!out.is_open()) {
      std::cerr << "Error: Cannot open output file " << argv[2] << "\n";
      return EXIT_FAILURE;
    }
    output = &out;
  }

  // Read and process each line from the input file
  String line;
  char buffer[1024];
  
  while (in.getline(buffer, sizeof(buffer))) {
    line = String(buffer);
    
    // Output the infix expression
    *output << "Infix:   " << line << "\n";
    
    // Convert to postfix and output
    String postfix = infixToPostfix(line);
    *output << "Postfix: " << postfix << "\n\n";
  }

  // Close files
  in.close();
  if (argc > 2) {
    out.close();
  }

  return EXIT_SUCCESS;
}