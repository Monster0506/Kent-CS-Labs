#include "../string/string.hpp"
#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: assembler <input_file> [output_file]\n";
        return EXIT_FAILURE;
    }

    std::ifstream in(argv[1]);
    if (!in.is_open())
    {
        std::cerr << "Error: Cannot open input file " << argv[1] << "\n";
        return EXIT_FAILURE;
    }

    std::ofstream outFile;
    std::ostream *out = &std::cout;

    if (argc > 2)
    {
        outFile.open(argv[2]);
        if (!outFile.is_open())
        {
            std::cerr << "Error: Cannot open output file " << argv[2] << "\n";
            return EXIT_FAILURE;
        }
        out = &outFile;
    }

    char buffer[1024];
    String line;
    while (in.getline(buffer, sizeof(buffer)))
    {
        line = String(buffer);
        *out << "\nInfix Expression:   " << line << "\n";

        String postfix = infixToPostfix(line);
        *out << "Postfix Expression: " << postfix << "\n\n";

        postfixToAssembly(postfix, *out);


        // Slightly more complicated, as you have to iterate backwards through the expression, but not much more difficult.
        String prefix = infixToPrefix(line);
        *out << "prefix Expression: " << prefix << "\n\n";

        // Resulting ASM is exactly the same
        prefixToAssembly(prefix, *out);

    }

    if (argc > 2)
        outFile.close();
    return EXIT_SUCCESS;
}
