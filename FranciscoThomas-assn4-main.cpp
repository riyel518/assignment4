#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include "FranciscoThomas-assn4-common.h"
#include "Thomas-assn4-funcs.h"
#include "Francisco-assn4-funcs.h"

using namespace std;

void (*firstFuncPtr)(int*, int, int);
void (*secondFuncPtr)(int*, int, int);

int main() {

	char choices[CHOICE_SIZE]; //User input menu choice

	int repitition, //Number of times to repeat each set of algorithms
		currentIdx, //Current index to store results for each sorting algorithm
		firstArray[ARRAY_SIZE] = { 0 }, //Array to be sorted by the first sorting algorithm
		secondArray[ARRAY_SIZE] = { 0 }; //Array to be sorted by the second sorting algorithm

	int *firstResultsPtr = NULL, //Pointer for the results of each test for first sorting algorithm
		*secondResultsPtr = NULL; //Pointer for the results of each test for second sorting algorithm

	bool continueProgram; //While true, program will continue to run.

	srand(time(0));

	do {

		displaySortMenu();

		continueProgram = getMenuChoice(choices);

		if (continueProgram) {

			repitition = getRepeatChoice();

			firstResultsPtr = createResultsList(repitition);

			secondResultsPtr = createResultsList(repitition);

			storeFunctionsToPointers(choices);

			for (int i = 1; i <= repitition; i++) {

				currentIdx = i - 1;

				displaySortNumber(i);

				createRandomLists(firstArray, secondArray);

				firstResultsPtr[currentIdx] = timeSort(firstFuncPtr, firstArray);

				displaySortTime(firstResultsPtr, currentIdx, choices[0]);

				secondResultsPtr[currentIdx] = timeSort(secondFuncPtr, secondArray);

				displaySortTime(secondResultsPtr, currentIdx, choices[1]);

				continueProgram = successfulSort(firstArray, secondArray);

				if (!continueProgram)
					i = repitition + 1;
			}

			if (continueProgram)
				displayResult(firstResultsPtr, secondResultsPtr, choices, repitition);

			deleteResultsArray(firstResultsPtr, secondResultsPtr);
		}

		cin.clear();
		cout << "Press enter to continue...";
		cin.get();
		
	} while (continueProgram);


	return 0;
}
