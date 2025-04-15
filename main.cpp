//Project 2
//Kristian Tokos and Jakob Soukthavong

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "RadixSort.h"

using namespace std;

// Function Definitions
vector<string> findImmediateTransformations(const string& word, const unordered_set<string>& dictionary);

int main(void)
{
    // Test Driver for RadixSort
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

    // Test Driver for findImmediateTransformations function
    // Example dictionary
    unordered_set<string> dictionary = { "land", "lens", "pend", "send", "tend", "fend", "bend", "rend", "pane", "pens", "pans", "pare" };

    string word = "lend";
    vector<string> transformations = findImmediateTransformations(word, dictionary);

    cout << "Immediate transformations for \"" << word << "\":" << endl;
    for (const string& w : transformations) {
        cout << w << endl;
    }

    system("pause");

    return 0;
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
