#include <iostream>
#include "Francisco-assn4-funcs.h"
#include "Thomas-assn4-funcs.h"
#include "FranciscoThomas-assn4-common.h"
#include <iomanip>
using namespace std;

extern void (*firstFuncPtr)(int*, int, int);
extern void (*secondFuncPtr)(int*, int, int);

/**************************************************************
FUNCTION: displaySortMenu
DESCRIPTION: Display a menu of choice to the users
INPUT: N/A
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/


void displaySortMenu(){

 cout << endl << "Choose two sorts you wish to compare: " << endl;
 cout <<  "\tB = Bubble sort" << endl;
 cout <<  "\tI = Insertion sort" << endl;
 cout <<  "\tM = Merge sort" << endl;
 cout << "\tQ = Quick sort" << endl;
 cout <<  "\tE = Exit Program" << endl << endl;;

}



/**************************************************************
FUNCTION: displaySortNumber
DESCRIPTION: Displays the sort test number
INPUT: repeatTime - number of time that an array to be sorted
OUTPUT: int - the number of loop or time an array to be sorted
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/


int getRepeatChoice(){

int repeatTime;

cout << endl << "Enter the number of times to repeat each sort (1 or more): ";
cin >> repeatTime;

return repeatTime;


}


/**************************************************************
FUNCTION: storeFunctionsToPointers
DESCRIPTION: It integrate the user choice function to two function
pointes that will be use in sorting the two array
INPUT:
    PARAMETERS: choices[] - an array of user choices.
OUTPUT: N/A
CALLS TO: N/A
implement: Chris Francisco
**************************************************************/

void storeFunctionsToPointers(char choices[]){

char firstUserChoice,  
     secUserChoice;

firstUserChoice  =  choices[FIRST_CHOICES];  //get the first user choice of sort algorithm

   //use switch statement to get the choice and integrate the function pointer to the actually function.
     switch (firstUserChoice) {

       case BUBBLE:
        
        
        firstFuncPtr = &bubbleSort;

        break;
       
       case INSERTS:
      	
      	
       firstFuncPtr = &insertionSort;

        break;
        
       case MERGE:

        firstFuncPtr = &mergeSort;

       break;
       
       default:

      firstFuncPtr  = &quickSort;

       break;

  }



secUserChoice  =  choices[SEC_CHOICES]; //get the second user choice of sort algorithm

//use switch statement to get the choice and integrate the function pointer to the actually function.
     switch (secUserChoice) {

       case BUBBLE:
        
        
        secondFuncPtr = &bubbleSort;

        break;
       
      case INSERTS:
      	
      	
       secondFuncPtr = &insertionSort;

        break;
        
       case MERGE:

       secondFuncPtr  = mergeSort;

       break;
       
       default:

      secondFuncPtr  = &quickSort;

       break;

  }




}



  /**************************************************************
  FUNCTION: quickSort
  DESCRIPTION: sort the array using quickSort
  INPUT:
      PARAMETERS: toBeSorted - the array that will be sorted
      			  first - the first index of the array
      			  last - last or the lenght of the array - one
  OUTPUT: N/A
  CALLS TO: reckQuickSort
  implement: Chris Francisco
  **************************************************************/
  
  void quickSort(int* toBeSorted, int first, int last){
  	
  	  
  	
  	  recquickSort(toBeSorted, first, last);
  	

  	
  }
  
/**************************************************************
  FUNCTION: recquickSort
  DESCRIPTION: provide a recursive function to sort the array
  				using quicksort
  INPUT:
      PARAMETERS: toBeSorted - the array that will be sorted
      			  first - the first index of the array
      			  last - last or the lenght of the array - one
  OUTPUT: N/A
  CALLS TO: reckQuickSort and partition
  implement: Chris Francisco
**************************************************************/ 
  
void recquickSort(int* toBeSorted, int first, int last){
	
	int pivotLocation;
	
	if (first < last){
		
		pivotLocation = partition(toBeSorted, first, last);  //get the partition to divide the array
		recquickSort(toBeSorted, first, pivotLocation - INCREAMENTS);   //sort the uppder bound of array
		recquickSort(toBeSorted, pivotLocation + INCREAMENTS, last );  //sort the lower bound of array
		
		
	}
	

	
}
 
/**************************************************************
  FUNCTION: partition
  DESCRIPTION: partition and sort the array using quick sort
  INPUT:
      PARAMETERS: toBeSorted - the array that will be sorted
      			  first - the first index of the array
      			  last - last or the lenght of the array - one
  OUTPUT: int - the smallIndex of the array
  CALLS TO: swap
  implement: Chris Francisco
**************************************************************/  
  
int partition(int* toBeSorted, int first, int last){

    
 int pivot,
    index,
    smallIndex;

swap(toBeSorted, first, (first + last) / 2);

pivot = toBeSorted[first];
smallIndex = first;

for(index = first + 1; index <= last; index++){

    if (toBeSorted[index] < pivot){

        smallIndex++;
        swap(toBeSorted, smallIndex, index);

    }

}
	swap(toBeSorted, first, smallIndex);

	return smallIndex;

  

}

/**************************************************************
  FUNCTION: swap
  DESCRIPTION: swap the two value to the first and second cell of
  				array
  INPUT:
      PARAMETERS: toBeSorted - the array that will be sorted
      			  first - the first index of the array
      			  last - last or the lenght of the array - one
  OUTPUT: none
  CALLS TO: none
  implement: Chris Francisco
**************************************************************/  



void swap(int* toBeSorted, int first, int second){

  int temp;

  temp = toBeSorted[first];
  toBeSorted[first] = toBeSorted[second];
  toBeSorted[second] = temp;


}

/**************************************************************
  FUNCTION: partition
  DESCRIPTION: a bubble sort alogirhtm to sort the array
  INPUT:
      PARAMETERS: toBeSorted - the array that will be sorted
      			  first - the first index of the array
      			  last - last or the lenght of the array - one
  OUTPUT: none
  CALLS TO: none
  implement: Chris Francisco
**************************************************************/  

void bubbleSort (int* toBeSorted, int first, int last){

int temp,
	counter,
	idx;
	
 for (counter = first; counter < last; counter++){
 	
 	 for(idx = 0; idx < last - counter; idx++){
 	 	
 	 	if(toBeSorted[idx] > toBeSorted[idx + 1]){
 	 		
 	 		temp = toBeSorted[idx];
 	 		toBeSorted[idx] = toBeSorted[idx + 1];
 	 		toBeSorted[idx + 1] = temp;
 	 		
 	 	}
 	 	
 	 	
 	 }
 	
 	
 }




} // end of  

/**************************************************************
  FUNCTION: displaySortTime
  DESCRIPTION: display the sort time of an algorithm
  INPUT:
      PARAMETERS: resultPointer - the array the store the time of sort
      			  idx - index of current sort time
      			  choice - user choice
  OUTPUT: none
  CALLS TO: none
  implement: Chris Francisco
**************************************************************/ 

void displaySortTime(int* resultPointer, int idx,  char choices){

  char specificChoicess;
  int  totalTime;

  specificChoicess = choices;
  totalTime = resultPointer[idx];

  switch (specificChoicess) {

    case BUBBLE:

    cout << endl << "\tBubble sort time is " << totalTime;

    break;
    case INSERTS:

    cout << endl << "\tInsertion sort time is " << totalTime;


     break;
    case MERGE:

    cout << endl << "\tMerge sort time is " << totalTime;

    break;

    default:

    cout << endl << "\tQuick sort time is " << totalTime;

    break;
}


}

/**************************************************************
  FUNCTION: displayResults
  DESCRIPTION: Display the average time required for each sort method
  				tested
  INPUT:
      PARAMETERS: firstResult - collection array of time of the first sort algoirthm
      			  secondResult - collection array of time of the seo sort algorithm
      			  choice - user choice
      			  repitition - interative 
  OUTPUT: none
  CALLS TO: resultAvg and outResult
  implement: Chris Francisco
**************************************************************/ 

void displayResult(int *firstResult, int *secondResult, char choices[], int repitition){

double firstAvg,
       secAvg;

char firstChoices,
      secChoices;
cout << endl << "SORTING RESULTS" << endl;
cout  << "----------------" << endl;
firstAvg = resultAvg(firstResult, repitition);
firstChoices = choices[FIRST_CHOICES];
outResult(firstAvg, firstChoices);

secAvg = resultAvg(secondResult, repitition);
secChoices = choices[SEC_CHOICES];
outResult(secAvg, secChoices);

cout << endl;

}

/**************************************************************
  FUNCTION: resultAvg
  DESCRIPTION: calculate the avg of time of collection time of sort algorithm
  INPUT:
      PARAMETERS: result - the sort array
      			  repitition - interative 
  OUTPUT: none
  CALLS TO: none
  implement: Chris Francisco
**************************************************************/ 
double resultAvg(int *result, int repitition){

     int extractData,
              counts;

      double avgResult;

          extractData = INITIALIZED;

         for(counts = INITIALIZED; counts < repitition; counts++){

            extractData = extractData + result[counts];

         }

        avgResult = (double) extractData / (double) repitition;

    return avgResult;
}


/**************************************************************
  FUNCTION: outResult
  DESCRIPTION: out put the result of algorithm times
  INPUT:
      PARAMETERS: average - the avearge of algorithm times
      			   choice - user choices 
  OUTPUT: none
  CALLS TO: none
  implement: Chris Francisco
**************************************************************/ 
void outResult(double average, char choicess){



  switch (choicess) {

    case BUBBLE:

    cout << "\tBubble sort " << average << " clock ticks on average" << endl;

    break;
    case INSERTS:

    cout << "\tInsertion sort " << average << " clock ticks on average" << endl;


     break;
    case MERGE:

    cout  << "\tMerge sort " << average << " clock ticks on average"<< endl;

    break;

    default:

    cout << "\tQuick sort " << average << " clock ticks on average" << endl;

    break;
  }

}
