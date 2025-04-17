#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Class for performing Radix Sort on a list of strings
class RadixSort {
public:
    // Public method to sort a vector of strings
    void sort(std::vector<std::string>& strings);

private:
    // Helper method to find the maximum length of strings in the input
    size_t findMaxLength(const std::vector<std::string>& strings);

    // Method to perform counting sort on strings based on a specific character position
    void countingSort(std::vector<std::string>& strings, size_t position);
};