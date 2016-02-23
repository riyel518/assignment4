
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Thomas-assn4-funcs.h"
#include "Francisco-assn4-funcs.h"
#include "FranciscoThomas-assn4-common.h"

using namespace std;

extern void (*firstFuncPtr)(int*, int, int);
extern void (*secondFuncPtr)(int*, int, int);

/**************************************************************
FUNCTION: getMenuChoice
DESCRIPTION: Displays message to user and retrieves two sorting algorithm choices from the
			sorting menu options. Returns false if user chooses to exit program.
INPUT: 
    PARAMETERS: firstChoice - character variable to store first algorithm choice
    			secondChoice - character variable to store second algorithm choice
OUTPUT:
    RETURN VALUE: contProg - boolean false if user chooses to exit program
    PARAMETERS: firstChoice - first sorting algorithm choice
    			secondChoice - second sorting algorithm choice
CALLS TO: validChoice
**************************************************************/
bool getMenuChoice(char choices[]) {

	bool contProg = true; //True if user does not select to exit program
	
	do {
		cout << "Enter two letter choices (or EE to exit): ";
		cin.clear();
		cin >> choices[0] >> choices[1];
		cin.ignore(1000, '\n');
	} while (!validChoice(choices[0]) || !validChoice(choices[1]));

	if ((choices[0] == EXIT_PROGRAM) && (choices[1] == EXIT_PROGRAM)) {
		contProg = false;
		cout << endl << "Exiting program." << endl;
	}

	return contProg;
}
/**************************************************************
FUNCTION: validChoice
DESCRIPTION: Verifies that the user input is valid. Displays a message if
			input was invalid.
INPUT: 
    PARAMETERS: userInput - character to be verified.
OUTPUT:
    RETURN VALUE: valid - true if valid
CALLS TO: N/A
**************************************************************/
bool validChoice(char userInput) {

	bool valid = false; //True if input is valid

	//array of valid character choices
	char validChoices[MENU_CHOICES] = { BUBBLE_SORT, INSERTION_SORT, MERGE_SORT,
										QUICK_SORT, EXIT_PROGRAM };

	for (int i = 0; i < MENU_CHOICES; i++) {
		if (userInput == validChoices[i])
			valid = true;
	}

	if (!valid)
		cout << endl << userInput << " is not a valid choice. Please try again." << endl;

	return valid;
}
/**************************************************************
FUNCTION: createResultsList
DESCRIPTION: Dynamically allocates an array with the specified number of
			elements to store the results of each algorithm test.
INPUT: 
    PARAMETERS: size - size of each array
OUTPUT:
    RETURN VALUE: resultsPtr - points to new integer array
CALLS TO: N/A
**************************************************************/
int* createResultsList(int size) {

	int* resultsPtr = new int[size](); //Dynamically allocated array

	return resultsPtr;
}

/**************************************************************
FUNCTION: createRandomLists
DESCRIPTION: Stores the same set of ARRAY_SIZE random integers ranging from MIN_INTEGER to 
			MAX_INTEGER to two different arrays.
INPUT: 
    PARAMETERS: firstArray - ARRAY_SIZE element array
    			secondArray - ARRAY_SIZE element array
OUTPUT:
    PARAMETERS: firstArray - ARRAY_SIZE random integers
    			secondArray - ARRAY_SIZE random integers
CALLS TO: N/A
**************************************************************/
void createRandomLists(int firstArray[], int secondArray[]) {

	int randomNum; //Random integer to be stored to each array

	for (int i = 0; i < ARRAY_SIZE; i++) {
		randomNum = rand() % MAX_INTEGER - 1;
		firstArray[i] = randomNum;
		secondArray[i] = randomNum;
	}

	return;
}

/**************************************************************
FUNCTION: timeSort
DESCRIPTION: Starts a timer and intiates a sorting algorithm using a
			specified function pointer. Returns the time it takes to sort 
			an array.
INPUT: 
    PARAMETERS: intArray - ARRAY_SIZE random integer array
    			sortFuncPtr - points to a specific sorting algorithm function
OUTPUT:
    RETURN VALUE: timeDifference - amount of time it took to sort intArray using sortFuncPtr
CALLS TO: function pointed to by sortFuncPtr - bubbleSort, insertonSort, mergeSort, or quickSort
**************************************************************/
int timeSort(void (*sortFuncPtr)(int*, int, int), int intArray[]) {

	int startTime,  //Clock time prior to sorting algorithm
		endTime, //Clock time after sorting algorithm
		timeDifference, //Difference between start and end time
		lowIdx = 0, //Lowest index of the array to be sorted
		highIdx = ARRAY_SIZE - 1; //Highest index of the array to be sorted

		startTime = clock();

		(*sortFuncPtr)(intArray, lowIdx, highIdx);

		endTime = clock();

		timeDifference = endTime - startTime;

		return timeDifference;
}

/**************************************************************
FUNCTION: insertionSort
DESCRIPTION: Sorts ARRAY_SIZE random integers using an insertion sort algorithm
INPUT: 
    PARAMETERS: intArray - ARRAY_SIZE random integers
    			lowIdx - lowest index of intArray
    			highIdx - highest index of intArray
OUTPUT:
    PARAMETERS: intArray - ARRAY_SIZE sorted integers
CALLS TO: N/A
**************************************************************/
void insertionSort(int intArray[], int lowIdx, int highIdx) {

	int unsortedTopIndex = 1, //High index in the array that hasn't been sorted
		valueToBeInserted, //Value to be sorted
		currentIndex; //Index being examined

	while (unsortedTopIndex <= highIdx) {
		valueToBeInserted = intArray[unsortedTopIndex];
		currentIndex = unsortedTopIndex - 1;

		while ((currentIndex >= lowIdx) && (valueToBeInserted < intArray[currentIndex])) {
			intArray[currentIndex + 1] = intArray[currentIndex];
			currentIndex--;
		}
		
		intArray[currentIndex + 1] = valueToBeInserted;
		unsortedTopIndex++;
	}

	return;
}

/**************************************************************
FUNCTION: mergeSort
DESCRIPTION: Sorts ARRAY_SIZE random integers using a merge sort algorithm
INPUT: 
    PARAMETERS: intArray - ARRAY_SIZE random integers
    			lowIdx - lowest index of array section to be sorted
    			highIdx - highest index of array section to be sorted
OUTPUT:
    PARAMETERS: intArray - ARRAY_SIZE sorted integers
CALLS TO: N/A
**************************************************************/
void mergeSort(int intArray[], int lowIdx, int highIdx) {

	static int tempArray[ARRAY_SIZE]; //Temporary array copy

	int middleIdx, //Middle index used for partitioning the array into two smaller arrays
		leftIdx, //Index to be merged from smaller array
		rightIdx, //Index to be merged from other smaller array
		tempPos; //Index of original array to be merged into

	if (lowIdx < highIdx) {

		middleIdx = (lowIdx + highIdx) / 2;

		mergeSort(intArray, lowIdx, middleIdx);
		mergeSort(intArray, middleIdx + 1, highIdx);

		for (int n = lowIdx; n <= highIdx; n++)
            tempArray[n] = intArray[n];

		leftIdx = lowIdx;
		rightIdx = middleIdx + 1;
		tempPos = lowIdx;

		while ((leftIdx <= middleIdx) && (rightIdx <= highIdx)) {
			if (tempArray[leftIdx] <= tempArray[rightIdx]) {
				intArray[tempPos] = tempArray[leftIdx];
				leftIdx++;
			}
			else {
				intArray[tempPos] = tempArray[rightIdx];
				rightIdx++;
			}
			tempPos++;
		}

		while (leftIdx <= middleIdx) {
			intArray[tempPos] = tempArray[leftIdx];
			tempPos++;
			leftIdx++;
		}

		while (rightIdx <= highIdx) {
			intArray[tempPos] = tempArray[rightIdx];
			tempPos++;
			rightIdx++;
		}
	}

	return;
}

/**************************************************************
FUNCTION: displaySortNumber
DESCRIPTION: Displays the sort test number
INPUT: 
    PARAMETERS: num - current sort number
OUTPUT: N/A
CALLS TO: N/A
**************************************************************/
void displaySortNumber(int num) {
	cout << endl << "Starting sort #" << num << "..." << endl;
	return;
}
/**************************************************************
FUNCTION: successfulSort
DESCRIPTION: Verifies that both arrays were properly sorted. Displays
message whether sorting was successful or not.
INPUT: 
    PARAMETERS: firstArray - ARRAY_SIZE post-sort integers
    secondArray - ARRAY_SIZE post-sort integers
OUTPUT:
    RETURN VALUE: success - true if arrays were successfully sorted
CALLS TO: isSorted
**************************************************************/
bool successfulSort(int firstArray[], int secondArray[]) {

	bool success = true; //Both arrays were successful sorted if true

	if (isSorted(firstArray) && isSorted(secondArray))
		cout << endl << "\tSorts Validated." << endl;
	else {
		success = false;
		cout << "\tSorting failed. Exiting Program." << endl;
	}

	return success;

}

/**************************************************************
FUNCTION: isSorted
DESCRIPTION: Verifies that the specified array was properly sorted.
INPUT: 
    PARAMETERS: sortedArray - ARRAY_SIZE post-sort integer array
OUTPUT:
    RETURN VALUE: sorted - true if array was successfully sorted
CALLS TO: N/A
**************************************************************/
bool isSorted(int sortedArray[]) {
	
	bool sorted = true; //Single array was successfully sorted if true

	for (int i = 0; i < ARRAY_SIZE - 1; i++)
		if (sortedArray[i] > sortedArray[i+1]) {
			sorted = false;
			i = ARRAY_SIZE;
		};

	return sorted;

}

/**************************************************************
FUNCTION: deleteResultsArray
DESCRIPTION: Deallocates the memroy used by the two results arrays
INPUT: 
    PARAMETERS: firstResultsPtr - points to first array to be deleted
    secondResultsPtr - points to second array to be deleted
OUTPUT: N/A
CALLS TO: N/A
**************************************************************/
void deleteResultsArray(int* firstResultsPtr, int* secondResultsPtr) {
	delete[] firstResultsPtr;
	delete[] secondResultsPtr;
	return;
}
