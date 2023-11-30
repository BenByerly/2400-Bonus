/*///////////////////////////////////////////////////////
Author: Ben Byerly                                      /
Class: CSC 2400-004                                     /
Purpose: create 4 algorithms to sort 3 arrays           /
Date of completeion: 10/26/23                           /
    Info: ran each algorithm in increments so that I    /
    got the best output possible                        /
///////////////////////////////////////////////////////*/


#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>

using namespace std;

void generate_randomArray(int [], int);
void generate_increasingArray(int [], int);     //function initializations
void generate_decreasingArray(int [], int);
void shellSort(int [], int );
void insertionSort(int [], int);
void selectionSort(int [], int);
void bubbleSort(int [], int);


int main(){

    srand(time(0)); // Seed for random number generation

    int arraySizes[] = {100, 1000, 10000, 100000, 1000000,}; //creates an arary for each of the 10^n values are at each index.
    int size = 0;                                                  //for this part I manually changed the values when testing different algorithms to get accurate data.
    double elapsedTime1 = 0, elapsedTime2 = 0, elapsedTime3 = 0, averageTime = 0;

    for(int i = 0; i < 4; i++){
        size = arraySizes[i];       //sets the size of the new allocated array = the index of the arraySizes array. 

        
       //Below, this creates a new array of numbers for each 10^n, it does not use a new array for the different sorting algorithms.  
        int* randomArray = new int[size];   //creates a pointer to the start of a random array of size n
        generate_randomArray(randomArray, size);

        int* increasingArray = new int[size];  //creates a pointer to the start of an increasing array of size n.
        generate_increasingArray(increasingArray, size);

        int* decreasingArray = new int[size];   //creates a pointer to the starts of a decreasing array of size n.
        generate_decreasingArray(decreasingArray, size);
        
        // Creates varibales to measure the time taken by each sorting algorithm
        clock_t startTime1, startTime2, startTime3;
        clock_t endTime1, endTime2, endTime3;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //This part is long. Each block of comment represents a clock that saves the runntime of each algorithms. It then outputs the average of those three clocks.
    //After each 4 algorithms are ran there is a long double line comment line('//')(like like 53 and 54) that separates from the increasing, decreasing, and random arrays.
        cout << "Algorithm set 10^" << i+2 << ": " << endl;
        
            cout << "\n\nRandom Array:\n";
            //The three clocks below run the SHELL SORT three times and outputs the average of each sort.
            //RANDOM ARRRAY
            /////////////////////////////////////////////////////////////////////////
            //dont need to create an array yet since at the beginning of the for   //
                //loop we created 3 arrays                                         //
            startTime1 = clock();                                                  //   Starts clock
            shellSort(randomArray, size);                                          //Clock 1
            endTime1 = clock();                                                    //   Stops clock
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //   Gets the time in seconds (this will repeat for every algorithm 3 times)
            delete [] randomArray;  
        //deletes so that we can make new space for random array
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                      //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime2 = clock();                                                  //
            shellSort(randomArray, size);                                          //Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        // 
            startTime3 = clock();                                                  //
            shellSort(randomArray, size);                                          //Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;         //gets the average of the three times, repeats for every algorithm.
        cout << endl << "\tShell Sort for random array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

            //The three clocks below run the INSERTION SORT three times and outputs the average of each sort. 
            //RANDOM ARRAY
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime1 = clock();                                                  //
            insertionSort(randomArray, size);                                      // Clock 1 
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime2 = clock();                                                  //
            insertionSort(randomArray, size);                                      // Clock 2 
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime3 = clock();                                                  //
            insertionSort(randomArray, size);                                      // Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tInsertion Sort for random array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

            //The three clocks below take the SELECTION SORT algorithm and runs it three times and outputs the average.
            //RANDOM ARRAY
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime1 = clock();                                                  //    
            selectionSort(randomArray, size);                                      // Clock 1 
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime2 = clock();                                                  //
            selectionSort(randomArray, size);                                      // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime2 = clock();                                                  //
            selectionSort(randomArray, size);                                      // Clock 3
            endTime2 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tSelection Sort for random array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;
            
            //The three clocks below take the BUBBLE SORT algorithm and runs it three times and outputs the average.
            //RANDOM ARRAY
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime1 = clock();                                                  //
            bubbleSort(randomArray, size);                                         // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime2 = clock();                                                  //
            bubbleSort(randomArray, size);                                         // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            randomArray = new int[size];                                           //
            generate_randomArray(randomArray, size);                               //
            //generates a new array to sort                                        //
            startTime3 = clock();                                                  //
            bubbleSort(randomArray, size);                                         // Clock 3
            endTime3 = clock();                                                    //        
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] randomArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tBubble Sort for random array of size " << size << ", ran three times and the average is: " << elapsedTime1 << " seconds" << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //Sorting algorithms for the increasing array and their average
        //The three clocks below run the SHELL SORT three times and outputs the average of each sort.
        //INCREASING ARRAY
        cout << "\n\nIncreasing Array: \n";
            /////////////////////////////////////////////////////////////////////////
            //dont need to create a new array yet since we created ones at the top 
            startTime1 = clock();                                                  //
            shellSort(increasingArray, size);                                      // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime2 = clock();                                                  //
            shellSort(increasingArray, size);                                      // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime3 = clock();                                                  //
            shellSort(increasingArray, size);                                      // Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << endl << "\tShell Sort for increasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

        //The three clocks below run the INSERTION SORT three times and outputs the average of each sort. 
        //INCREASING ARRAY 
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime1 = clock();                                                  //
            insertionSort(increasingArray, size);                                  // Clock 1 
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime2 = clock();                                                  //
            insertionSort(increasingArray, size);                                  // Clock 2 
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime3 = clock();                                                  //
            insertionSort(increasingArray, size);                                  // Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tInsertion Sort for increasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

        //The three clocks below take the SELECTION SORT algorithm and runs it three times and outputs the average.
        //INCREASING ARRAY
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime1 = clock();                                                  //    
            selectionSort(increasingArray, size);                                  // Clock 1 
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime2 = clock();                                                  //
            selectionSort(increasingArray, size);                                  // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime2 = clock();                                                  //
            selectionSort(increasingArray, size);                                  // Clock 3
            endTime2 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tSelection Sort for increasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;
      
        //The three clocks below take the BUBBLE SORT algorithm and runs it three times and outputs the average.
        //INCREASING ARRAY
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime1 = clock();                                                  //
            bubbleSort(increasingArray, size);                                     // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime2 = clock();                                                  //
            bubbleSort(increasingArray, size);                                     // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            increasingArray = new int[size];                                       //
            generate_increasingArray(increasingArray, size);                       //
            //generates a new increasing array to sort.                            //
            startTime3 = clock();                                                  //
            bubbleSort(increasingArray, size);                                     // Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] increasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tBubble Sort for increasing array of size " << size << ", ran three times and the average is: " << elapsedTime1 << " seconds" << endl;
        cout << endl;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        //The three clocks below take the SHELL SORT algorithm and runs it three times and outputs the average.
        //DECREASING ARRAY
        cout << "\n\nDecreasing Array:\n";
            /////////////////////////////////////////////////////////////////////////
            //dont need to create a new array yet since we created ones at the top 
            startTime1 = clock();                                                  //
            shellSort(decreasingArray, size);                                      // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime2 = clock();                                                  //
            shellSort(decreasingArray, size);                                      // Clock 2 
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime3 = clock();                                                  //
            shellSort(decreasingArray, size);                                      // Clock 3 
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tShell sort for decreasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

        //The three clocks below take the INSERTION SORT algorithm and runs it three times and outputs the average.
        //DECREASING ARRAY
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime1 = clock();                                                  //
            insertionSort(decreasingArray, size);                                  // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime2 = clock();                                                  //
            insertionSort(decreasingArray, size);                                  // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime3 = clock();                                                  //
            insertionSort(decreasingArray, size);                                  // Clock 3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tInsertion sort for decreasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;

        //The three clocks below take the SELECTION SORT algorithm and runs it three times and outputs the average.
        //DECREASING ARRAY
            /////////////////////////////////////////////////////////////////////////   
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime1 = clock();                                                  //
            selectionSort(decreasingArray, size);                                  // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime2 = clock();                                                  //        
            selectionSort(decreasingArray, size);                                  // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime3 = clock();                                                  //
            selectionSort(decreasingArray, size);                                  // Clock 3
            endTime3 = clock();                                                    //        
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tSelection sort for decreasing array of size " << size << ", ran three times and the average is: " << averageTime << " seconds" << endl;
        
        //The three clocks below take the BUBBLE SORT algorithm and runs it three times and outputs the average.
        //DECREASING ARRAY
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime1 = clock();                                                  //
            bubbleSort(decreasingArray, size);                                     // Clock 1
            endTime1 = clock();                                                    //
            elapsedTime1 = double(endTime1 - startTime1) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime2 = clock();                                                  //
            bubbleSort(decreasingArray, size);                                     // Clock 2
            endTime2 = clock();                                                    //
            elapsedTime2 = double(endTime2 - startTime2) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            decreasingArray = new int[size];
            generate_decreasingArray(decreasingArray, size);                       //
            //generates a new decreasing array to sort.                            //
            startTime3 = clock();                                                  //
            bubbleSort(decreasingArray, size);                                     // Clock3
            endTime3 = clock();                                                    //
            elapsedTime3 = double(endTime3 - startTime3) / double(CLOCKS_PER_SEC); //
            delete [] decreasingArray;
            /////////////////////////////////////////////////////////////////////////
            averageTime  = (elapsedTime1 + elapsedTime2 + elapsedTime3) / 3;
        cout << "\tBubble sort for decreasing array of size " << size << ", ran three times and the average is: " << elapsedTime1  << " seconds" << endl;
        cout << endl;

        for(int i=0; i<2; i++){
            for(int i=0; i<120; i++){
                cout << '-';            //prints double dashed line to screen to make the output cleaner. 
            }
            cout << endl;
        }
        cout << endl; 
              ;

    }
    return 0;
}

//Name: generate_randomArray
//Purpose: Generates a random array
//Input: integer array, size of array
//Output: random array of size n 
void generate_randomArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100000; // Generating random numbers between 0 and 99999
    }
}

//Name: generate_increasingArray
//Purpose: Generates a increasing array
//Input: integer array, size of array
//Output: random array of size n
void generate_increasingArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;     //takes pointer to beginning of allocated spaces and the size of the array, 
    }                       //it then iterates through the memory and stores a value at arr[i] = (i + 1)
}

//Name: generate_decreasingArray
//Purpose: Generates a decreasing array
//Input: integer array, size of array
//Output: random array of size n
void generate_decreasingArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        arr[i] = n - i;
    }
}

//Name: shellShort
//Purpose: Sorts an array using shell sort algorithm
//Input: integer array, size of array
//Output: Sorted int array
void shellSort(int arr[], int n) {
    // Start with a large gap and reduce it over each iteration
    for(int gap = n / 2; gap > 0; gap /= 2){
        // Perform an insertion sort on the elements separated by 'gap'
        for(int i = gap; i < n; i++){
            int temp = arr[i];
            int j;
            // Move elements of the subarray 'arr[0..i-gap]' that are greater than 'temp'
            // to the right by 'gap' positions
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap){
                arr[j] = arr[j - gap];
            }
            // Place 'temp' (the current element being compared) in its correct position
            arr[j] = temp;
        }
    }
}

//Name: insertionSort
//Purpose: Sorts an array using insertion sort algorithm
//Input: integer array, size of array
//Output: Sorted int array
void insertionSort(int arr[], int n){
    // Iterate through the array starting from the second element (index 1)
    for(int i = 1; i < n; i++){
        // Store the current element for comparison
        int key = arr[i];
        int j = i - 1;
        // Compare and shift elements to the right to make space for the 'key'
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        // Place the 'key' element in its correct sorted position
        arr[j + 1] = key;
    }
}

//Name: selectionSort
//Purpose: Sorts an array using selection sort algorithm
//Input: integer array, size of array
//Output: Sorted int array
void selectionSort(int arr[], int n){
    int min = 0; // Variable to store the index of the minimum element
    // Iterate through the array
    for(int i = 0; i < n; i++){
        min = i; // Assume the current element is the minimum
        // Find the index of the minimum element in the unsorted portion
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        // Swap the current element with the minimum element found
        swap(arr[i], arr[min]);
    }
}

//Name: bubbleSort
//Purpose: Sorts an array using bubble sort algorithm
//Input: integer array, size of array
//Output: Sorted int array
void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        bool swapped = false; // Variable to track if any swaps were made
        // Traverse the array and compare adjacent elements
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]); // Swap if the current element is greater
                swapped = true; // Mark that a swap has occurred
            }
        }
        // If no swaps were made in a pass, the array is already sorted
        if(!swapped){
            break;
        }
    }
}