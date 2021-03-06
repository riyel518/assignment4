bool getMenuChoice(char choices[]);
bool validChoice(char userInput);
int* createResultsList(int size);
void createRandomLists(int firstArray[], int secondArray[]);
int timeSort(void (*sortFuncPtr)(int*, int, int), int intArray[]);
void insertionSort(int intArray[], int lowIdx, int highIdx);
void mergeSort(int intArray[], int lowIdx, int highIdx);
void displaySortNumber(int num);
bool successfulSort(int firstArray[], int secondArray[]);
bool isSorted(int sortedArray[]);
void deleteResultsArray(int* firstResultsPtr, int* secondResultsPtr);