//Project 2
//Kristian Tokos and Jakob Soukthavong


#include "RadixSort.h"
#include "Functions.h"

// ----- Function Definitions -----

// Function to load dictionary from a file, filtering by word length
unordered_set<string> loadDictionary(const string& filename, size_t wordLength);

// Function to find immediate transformations
vector<string> findImmediateTransformations(const string& word, const unordered_set<string>& dictionary);

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
  
  // ----- Test Driver for RadixSort (By Kristian Tokos) -----------------------------------------------
  //RadixSort sorter; // Create an instance of RadixSort
  //std::vector<std::string> strings = { "banana", "apple", "kiwi", "orange", "grape" }; // Input strings
  //sorter.sort(strings); // Sort the strings using radix sort
  //
  //// Output the sorted strings
  //std::cout << "Sorted strings:\n";
  //for (const auto& str : strings) {
  //    std::cout << str << "\n";
  //}
  //system("pause");

  //----------------------------------------------------------------------------------------------------

  // ----- Test Driver for findImmediateTransformations & loadDictionary functions ---------------------
 
  //string filename = "dictionary345.txt"; // Input file name
  //string initialWord = "lend"; // The word to start with
  //
  //unordered_set<string> dictionary = loadDictionary(filename, initialWord.length());
  //
  //if (dictionary.empty()) {
  //    cerr << "Error: Dictionary is empty or file not found!" << endl;
  //    return 1;
  //}
  //
  //vector<string> transformations = findImmediateTransformations(initialWord, dictionary);
  //
  //std::cout << "Immediate transformations for \"" << initialWord << "\":" << std::endl;
  //for (const string& w : transformations) {
  //    cout << w << endl;
  //}
  //
  //system("pause");

  // ---------------------------------------------------------------------------------------------------

	return 0;
}

// ----- Function Bodies -----

unordered_set<string> loadDictionary(const string& filename, size_t wordLength)
{
    unordered_set<string> dictionary;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return dictionary;
    }

    string word;
    while (file >> word) {
        if (word.length() == wordLength) { // Check if the word length matches the target length
            transform(word.begin(), word.end(), word.begin(), ::tolower); // Convert to lowercase
            dictionary.insert(word);
        }
    }

    file.close();
    return dictionary;
}

vector<string> findImmediateTransformations(const string& word, const unordered_set<string>& dictionary)
{
    vector<string> results;

    // Iterate through each position in the word
    for (size_t i = 0; i < word.length(); ++i) {
        char originalChar = word[i];

        // Replace the character with every possible letter
        for (char c = 'a'; c <= 'z'; ++c) {
            if (c == originalChar) continue; // Skip if it's the same character
            string transformedWord = word;
            transformedWord[i] = c;

            // Check if the transformed word is in the dictionary
            if (dictionary.find(transformedWord) != dictionary.end()) {
                results.push_back(transformedWord);
            }
        }
    }

    return results;
}


