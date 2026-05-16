#include <cctype>
#include <fstream>
#include <iostream>

#include "WordList.hpp"

std::string getNextWord(std::ifstream &in) {
    std::string word;
    char c;
    while (in.get(c)) {
        if (isalnum(c)) {
            c = tolower(c);
            word += c;
        } else if (!word.empty()) {
            break;
        }
    }

    // hey, this is for case sensitivity/insensitivity, so comment this out to
    // switch the mode

    return word;
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    WordList wl;
    std::string word;
    while (!(word = getNextWord(infile)).empty()) {
        wl.addWord(word);
    }

    wl.print();
    return 0;
}
