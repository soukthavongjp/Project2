//Project 2
//Kristian Tokos and Jakob Soukthavong

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_set>


using namespace std;

//Constants
const int SCREEN_WIDTH = 80;
const char SYMBOL = '*';

//Prototypes
void OutputDivider(char symbol, int width);
void RemoveDuplicates(const string& inputFileName);
bool isOneLetterDifferent(const string& a, const string& b);
vector<string> loadWordsFromFile(const string& filename);
pair<vector<string>, int> findTransformationPath(string start, string target, 
	vector<string>& wordList);



int main(void)
{
	string inputFileName = "dictionary345.txt";
	string start;
	string target;

	RemoveDuplicates(inputFileName);

	vector<string> wordList = loadWordsFromFile(inputFileName);

	if (wordList.empty())
	{
		cout << "Error: No words found in the file . \n";
		return 1;
	}

	cout << "Enter starting word: "
	cin >> start;
	cout << "Enter target word: ";
	cin >> target;

	auto [path, stepCount] = findTransformationPath(start, target, wordList);

	if (!path.empty())
	{
		cout << "Transformation Path using Stack: ";
		for (const string& word : path)
		{
			cout << word << " -> ";
		}

		cout << "\b\b \n";
		cout << "Total transformations required: " << stepCount << endl;
	}
	else
	{
		cout << "No valid transformation found. \n";
	}

	inFile.close();

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
Function #2 Made by Jakob Soukthavong
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


	cout << endl << "Duplicate words have been removed and these are the results. " << endl;

}

//
//Function to check if two words differ by exactly one letter
//
bool isOneLetterDifferent(const string& a, const string& b) 
{
	if (a.size() != b.size()) return false;
	int diffCount = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) diffCount++;
		if (diffCount > 1) return false;
	}
	return diffCount == 1;
}

//
//
//
vector<string> loadWordsFromFile(const string& filename) 
{
	ifstream file(filename);
	vector<string> words;
	string word;

	if (!file) {
		cerr << "Error: Could not open file.\n";
		return {};
	}

	while (file >> word) {
		words.push_back(word);
	}

	return words;
}

//
// BFS to find the shortest transformation path and count steps, using a stack
//
pair<vector<string>, int> findTransformationPath(string start, string target, vector<string>& wordList) 
{
	unordered_set<string> wordSet(wordList.begin(), wordList.end());
	queue<vector<string>> q;
	q.push({ start });

	while (!q.empty()) {
		vector<string> path = q.front();
		q.pop();
		string lastWord = path.back();

		if (lastWord == target) {
			// Use a stack to store the path in correct order
			stack<string> transformationStack;
			for (const string& word : path) {
				transformationStack.push(word);
			}

			// Extract the transformation path from the stack
			vector<string> transformationOrder;
			while (!transformationStack.empty()) {
				transformationOrder.push_back(transformationStack.top());
				transformationStack.pop();
			}

			return { transformationOrder, path.size() - 1 }; // Steps = path length - 1
		}

		for (auto it = wordSet.begin(); it != wordSet.end(); ) {
			if (isOneLetterDifferent(lastWord, *it)) {
				vector<string> newPath = path;
				newPath.push_back(*it);
				q.push(newPath);
				it = wordSet.erase(it); // Remove word to avoid cycles
			}
			else {
				++it;
			}
		}
	}

	return { {}, -1 }; // No valid transformation found
}