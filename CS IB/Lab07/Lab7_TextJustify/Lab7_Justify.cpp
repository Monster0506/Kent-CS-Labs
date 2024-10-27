#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_LENGTH = 90;

void addSpacesAfterPunctuation(string &line);
void addRandomSpace(string &line);

int main()
{
	srand(time(nullptr));
	string inputFilePath, outputFilePath;
	string line;
	cout << "Enter the input file path: ";
	getline(cin, inputFilePath);
	cout << "Enter the output file path: ";
	getline(cin, outputFilePath);
	ifstream inputFile(inputFilePath);
	ofstream outputFile(outputFilePath);

	while (getline(inputFile, line))
	{
		if (line.length() < 40)
		{
			outputFile << line << endl;
		}
		else
		{
			addSpacesAfterPunctuation(line);
			while (line.length() < MAX_LENGTH)
			{
				addRandomSpace(line);
			}
			outputFile << line << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	cout << "Done.  " << endl;
	return 0;
}

void addSpacesAfterPunctuation(string &line)
{
	string punctuation = ".,!?;";
	for (int i = 0; i < line.length(); i++)
	{
		if (
			punctuation.find(line[i]) != string::npos &&
			(
				i + 1 < line.length() &&
			 	line[i + 1] != ' '
				))
		{
			line.insert(i + 1, "  ");
			i += 2;
		}
	}
}

void addRandomSpace(string &line)
{
	int spacePos = rand() % line.length();
	spacePos = line.find(' ', spacePos);
	if (spacePos != string::npos && spacePos != line.length() - 1)
	{
		line.insert(spacePos, " ");
	}
}
