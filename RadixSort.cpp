// RadixSort CPP file corresponding with RadixSort header file holding function bodies
// for the methods found in the header file. (Done By Kristian Tokos)
//

#include "RadixSort.h"
using namespace std;

void RadixSort::sort(std::vector<std::string>& strings)
{
    if (strings.empty()) return; // If the input is empty, do nothing
    size_t maxLength = findMaxLength(strings); // Find the length of the longest string
    for (size_t i = maxLength; i > 0; --i) { // Loop through characters from the least significant to the most
        countingSort(strings, i - 1); // Sort based on the current character position
    }
}

size_t RadixSort::findMaxLength(const std::vector<std::string>& strings)
{
    size_t maxLength = 0;
    for (const auto& str : strings) {
        maxLength = std::max(maxLength, str.size()); // Update maxLength if a longer string is found
    }
    return maxLength;
}

void RadixSort::countingSort(std::vector<std::string>& strings, size_t position)
{
    const int CHAR_COUNT = 256; // Number of ASCII characters
    std::vector<std::string> output(strings.size()); // Temporary vector to store sorted strings
    std::vector<int> count(CHAR_COUNT, 0); // Count array to store frequencies of characters

    // Count occurrences of each character at the given position
    for (const auto& str : strings) {
        char charAtPosition = position < str.size() ? str[position] : '\0'; // Use '\0' for shorter strings
        count[charAtPosition]++;
    }

    // Update count array to store cumulative counts
    for (size_t i = 1; i < CHAR_COUNT; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array by placing strings in the correct order
    for (auto it = strings.rbegin(); it != strings.rend(); ++it) {
        char charAtPosition = position < it->size() ? (*it)[position] : '\0';
        output[count[charAtPosition] - 1] = *it; // Place the string in the correct position
        count[charAtPosition]--; // Decrease the count for that character
    }

    strings = output; // Copy the sorted output back to the input array
}
