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
	string line;
	string output="";
	cout << "Enter the line to justify: ";
	getline(cin, line);

		if (line.length() < 40)
		{
			output = line;
		}
		else
		{
			addSpacesAfterPunctuation(line);
			while (line.length() < MAX_LENGTH)
			{
				addRandomSpace(line);
			}
			output = line;
		}
	



	cout << "Done.  " << endl;
	cout<<line;
	return 0;
}

void addSpacesAfterPunctuation(string &line)
{
	string punctuation = ".,!?;";
	for (int i = 0; i < line.size(); i++)
	{
		if (
			punctuation.find(line[i]) != string::npos &&
			(
				i + 1 < line.size() &&
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
