//Project 2
//Kristian Tokos and Jakob Soukthavong

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

//Constants
const int SCREEN_WIDTH = 80;
const char SYMBOL = '*';

//Prototypes
void OutputDivider(char symbol, int width);
void RemoveDuplicates(const string& inputFileName);

int main(void)
{
	string inputFileName = "test.txt";

	RemoveDuplicates(inputFileName);

	return 0;
}

/******************************************************************************
Function #1
OutputDivider: This function will print a divider line to the stream passed
				into the function.
******************************************************************************/
void OutputDivider(char symbol, int width)
{
	cout << setfill(SYMBOL) << setw(SCREEN_WIDTH) << SYMBOL
		<< setfill(' ') << endl;
}

/******************************************************************************
Function #2
RemoveDuplicates: This function will remove the duplicate words from an input
text file.
******************************************************************************/
void RemoveDuplicates(const string& inputFileName)
{
	ifstream inFile;

	set<string> foundWords;
	string line;
	string word;

	inFile.open(inputFileName);

	if (!inFile)
	{
		cout << "Error: Could not open input file." << endl;
		return;
	}

	while (getline(inFile, line))
	{
		istringstream iss(line);

		while (iss >> word)
		{
			word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

			transform(word.begin(), word.end(), word.begin(), ::tolower);

			foundWords.insert(word);

		}
	}

	for (const auto& w : foundWords)
	{
		cout << w << endl;
	}

	inFile.close();

	cout << endl << "Duplicate words have been removed and these are the results. " << endl;

}