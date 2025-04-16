//Header file that contains standard things for the program
//This header file corresponds with the cpp file functions.cpp
//This contains prototypes for the methods that were used
//as well as the include statements that were needed to execute
//these methods. This was done by Jakob Soukthavong




#ifndef FUNCTIONS_h
#define FUNCTION_h

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
#include <stack>

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


#endif // !FUNCTIONS_h


