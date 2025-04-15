//Project 2
//Kristian Tokos and Jakob Soukthavong

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <fstream>
#include "RadixSort.h"

using namespace std;

// ----- Function Definitions -----

// Function to load dictionary from a file, filtering by word length
unordered_set<string> loadDictionary(const string& filename, size_t wordLength);

// Function to find immediate transformations
vector<string> findImmediateTransformations(const string& word, const unordered_set<string>& dictionary);

// ----- Main Function -----

int main(void)
{
    // ----- Test Driver for RadixSort -----
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

    // ----- Test Driver for findImmediateTransformations & loadDictionary functions -----
    // Example dictionary
    //unordered_set<string> dictionary = { "land", "lens", "pend", "send", "tend", "fend", "bend", "rend", "pane", "pens", "pans", "pare" };
    //
    //string filename = "dictionary345.txt"; // Input file name
    //string initialWord = "lend"; // The word to start with

    //unordered_set<string> dictionary = loadDictionary(filename, initialWord.length());

    //if (dictionary.empty()) {
    //    cerr << "Error: Dictionary is empty or file not found!" << endl;
    //    return 1;
    //}

    //vector<string> transformations = findImmediateTransformations(initialWord, dictionary);

    //std::cout << "Immediate transformations for \"" << initialWord << "\":" << std::endl;
    //for (const string& w : transformations) {
    //    cout << w << endl;
    //}
    //
    //system("pause");

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
