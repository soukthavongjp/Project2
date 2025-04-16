//Project 2
//Kristian Tokos and Jakob Soukthavong

#include "Functions.h"


int main(void)
{
	ifstream inFile;

	//----------------- Test Driver for Task 3 (By Jakob Soukthavong) ----------------------------------

	//string inputFileName = "test.txt";

	//RemoveDuplicates(inputFileName);

	//system("pause");

	//--------------------------------------------------------------------------------------------------

	//----------------- Test Driver for Task 5 (By Jakob Soukthavong) ----------------------------------

	//string inputFileName = "dictionary345.txt";
	//string start;
	//string target;

	////this word list will contain the words from the input file
	//vector<string> wordList = loadWordsFromFile(inputFileName);

	////error check to see if the list of words is empty.
	//if (wordList.empty())
	//{
	//	cout << "Error: No words found in the file . \n";
	//	return 1;
	//}

	////obtain user input for the starting word to the target word
	//cout << "Enter starting word: ";
	//cin >> start;
	//cout << "Enter target word: ";
	//cin >> target;

	////This line utilizes structure binding which will
	////automatically unpack the return values from the function used
	////rather than having to manually extract the values.
	//auto [path, stepCount] = findTransformationPath(start, target, wordList);

	////conditional statement for if a transformation path is found
	////where if the path is not empty then it will display the path
	////in stack for of Last in First Out which means the starting word
	////will be at the end of the line and the target word will be at the beginning
	////If not path is found then it will display a message clarifying.
	//if (!path.empty())
	//{
	//	cout << "Transformation Path using Stack: ";
	//	for (const string& word : path) cout << word << " -> ";

	//	cout << "\b\b \n";
	//	cout << "Total transformations required: " << stepCount << endl;
	//}
	//else
	//{
	//	cout << "No valid transformation found. \n";
	//}

	////Close input file
	//inFile.close();

	//system("pause");

	//--------------------------------------------------------------------------------------------------

	return 0;
}

