//CPP file corresponding with Functions.h
//This file contains the code for the methods created
//to complete tasks 3 and 5 done by Jakob Soukthavong

#include "Functions.h"

/******************************************************************************
Function #1 Made by Jakob Soukthavong
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

	//Set to contain the words that are found in order to prevent duplicates
	set<string> foundWords;

	string line;
	string word;

	//open input file that is obtained from the parameter.
	inFile.open(inputFileName);

	//Error check to see if the file is valid and can be opened.
	if (!inFile)
	{
		cout << "Error: Could not open input file." << endl;
		return;
	}

	//While statement to get the words from the input file using a getline and storing them.
	while (getline(inFile, line))
	{
		//string stream creates a stream object iss which allows for the extraction of individual words from the
		//input file as if it were being read from an input stream.
		istringstream iss(line);

		//while statement for the extracted words
		while (iss >> word)
		{
			//This line removes punctuation from the extracted words
			word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());

			//This line utilizes tolower to change the characters stored in word to be lower case.
			transform(word.begin(), word.end(), word.begin(), ::tolower);

			//This line adds the processed word to the set that was created prior.
			//This is a set so it does not allow duplicates.
			foundWords.insert(word);

		}
	}

	//Display code to display the set of words without the duplicates.
	for (const auto& w : foundWords)
	{
		cout << w << endl;
	}


	cout << endl << "Duplicate words have been removed and these are the results. " << endl;

}

/******************************************************************************
//Function #3 Made by Jakob Soukthavong
isOneLetterDifferent: This is helper function that checks if two words are different
by one letter.
******************************************************************************/
bool isOneLetterDifferent(const string& a, const string& b)
{
	//this takes two words and checks if they are the same size
	if (a.size() != b.size()) return false;

	int diffCount = 0;
	//This loop checks for difference by one letter.
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i]) diffCount++;
		if (diffCount > 1) return false;
	}
	return diffCount == 1;
}

/******************************************************************************
//Function #4 Made by Jakob Soukthavong
loadWordsFromFile: This function is used to read the words from the input file
and store them in a list.
******************************************************************************/
vector<string> loadWordsFromFile(const string& filename)
{
	ifstream file(filename);
	vector<string> words;
	string word;

	//error check to see if file is valid to open
	if (!file)
	{
		cerr << "Error: Could not open file.\n";
		return {};
	}

	//while loop to load words into a vector
	while (file >> word) 
	{
		words.push_back(word);
	}

	//returns the vector of words found from the file
	return words;
}

/******************************************************************************
//Function #5 Made by Jakob Soukthavong
findTransformationPath: This function uses breadth first search to find the 
transformations between the starting word and the target word while avoiding
cycles.
******************************************************************************/
pair<vector<string>, int> findTransformationPath(string start, string target, vector<string>& wordList)
{
	unordered_set<string> wordSet(wordList.begin(), wordList.end());
	queue<vector<string>> q;
	q.push({ start });

	//while loop until the queue is empty
	while (!q.empty()) 
	{
		vector<string> path = q.front();
		q.pop();
		string lastWord = path.back();

		//checks if the lastWord has successfully been transformed from the start word
		if (lastWord == target) {
			// Use a stack to store the path in correct order
			stack<string> transformationStack;
			for (const string& word : path) 
			{
				//store the path
				transformationStack.push(word);
			}

			// Extract the transformation path from the stack in correct order
			vector<string> transformationOrder;
			
			while (!transformationStack.empty()) 
			{
				transformationOrder.push_back(transformationStack.top());
				transformationStack.pop();
			}

			return { transformationOrder, path.size() - 1 }; // Steps = path length - 1
		}

		//This for loop explores the next words in the word set
		for (auto it = wordSet.begin(); it != wordSet.end(); )
		{
			//if a valid transformation is found then it is added to the new path and then pushed
			//into the queue
			if (isOneLetterDifferent(lastWord, *it)) {
				vector<string> newPath = path;
				newPath.push_back(*it);
				q.push(newPath);
				it = wordSet.erase(it); // Remove word to avoid cycles
			}
			else 
			{
				++it;
			}
		}
	}

	return { {}, -1 }; // No valid transformation found
}