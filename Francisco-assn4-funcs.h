#include <iostream>
using namespace std;


          



void displaySortMenu();

int getRepeatChoice();

void storeFunctionsToPointers(char choices[]);

void chosenFunctionPointer(char specificChoices, void (*sortFuncPtr)(int*, int, int));

void bubbleSort (int* toBeSorte, int first, int last);

void quickSort(int* toBeSorted, int first, int last);

void recquickSort(int* toBeSorted, int first, int last);

int partition(int* toBeSorted, int first, int last);

void swap(int* toBeSorted, int first, int second);

void displaySortTime(int* resultPointer, int idx,  char choices);

void displayResult(int *firstResult, int *secondResult, char choices[], int repitition);

double resultAvg(int *result, int repitition);

void outResult(double average, char choicess);



