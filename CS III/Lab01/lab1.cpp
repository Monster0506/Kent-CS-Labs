#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " file1 file2" << std::endl;
        return 1;
    }

    char* filename1 = argv[1];
    char* filename2 = argv[2];

    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    if (!file1.is_open() || !file2.is_open()) {
        std::cerr << "Error: Could not open one of the files." << std::endl;
        return 1;
    }

    std::string line1, line2;
    int lineNumber = 0;

    while (true) {
        const bool f1 = (bool)(getline(file1, line1));
        const bool f2 = (bool)(getline(file2, line2));
        lineNumber++;

        if (!f1 && !f2) break;

        if (!f1) line1 = "";
        if (!f2) line2 = "";

        if (line1 != line2) {
            std::cout << filename1 << ": " << lineNumber << ": " << line1
                      << std::endl;
            std::cout << filename2 << ": " << lineNumber << ": " << line2
                      << std::endl;

            const int minLen =
                (int)(line1.size() < line2.size() ? line1.size()
                                                  : line2.size());
            int diffIndex = 0;
            while (diffIndex < minLen && line1[diffIndex] == line2[diffIndex]) {
                diffIndex++;
            }

            const std::string out = std::string(filename1) + ": " +
                                    std::to_string(lineNumber) + ": ";

            const std::string spaces(out.length() + diffIndex, ' ');
            std::cout << spaces << "^" << std::endl;
        }
    }

    file1.close();
    file2.close();
    return 0;
}
