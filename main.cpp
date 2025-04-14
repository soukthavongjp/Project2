//Project 2
//Kristian Tokos and Jakob Soukthavong


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

//Constants
const int SCREEN_WIDTH = 80;
const char SYMBOL = '*';

//Prototypes
void OutputDivider(char symbol, int width);


int main(void)
{


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

