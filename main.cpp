//Project 2
//Kristian Tokos and Jakob Soukthavong

#include <vector>
#include <string>
#include "RadixSort.h"

using namespace std;

int main(void)
{
    RadixSort sorter; // Create an instance of RadixSort
    std::vector<std::string> strings = { "banana", "apple", "kiwi", "orange", "grape" }; // Input strings
    sorter.sort(strings); // Sort the strings using radix sort

    // Output the sorted strings
    std::cout << "Sorted strings:\n";
    for (const auto& str : strings) {
        std::cout << str << "\n";
    }
    system("pause");
    return 0;
}