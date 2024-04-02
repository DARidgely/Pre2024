// File Name: main.cpp
// 
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 10/5/2021
// Assignment Number: 3
// CS 2308 Fall 2021
// 
// This program tests 5 different functions on their functionality to do
// what is proposed from their name. Maximum will grab and return the max
// value of an array of ints, oddSwap will swap two ints and multiply them
// by 5 and return the sum of the two values, resize will take an array
// and double its size keeping the original values and putting -1 after,
// concatenate will take two arrays of ints and put them together into
// one array of ints, and subArray will take an array and a start value
// then return the values within that start array and the integers length.

#include <iostream>

using namespace std;

void showArray (int *, int);
int *duplicateArray (int *, int);
int maximum(int*, int);
int oddSwap (int *, int *);
int *resize(int *, int);
int *concatenate(int *, int, int *, int);
int *subArray (int *, int, int);

int main() {
    int testForMax1[10] = { 1, 2, 3, 4, 5, 6, 7, -8, 9, 0};
    int testForMax2[10] = { 1, 2, 3, 4, 5, 16, 7, 8, 9, 0};
//  int expectedMaxForTest1 = 9;
//  int expectedMaxForTest2 = 16;

    int testForOddSwap1 = 3;
    int testForOddSwap2 = 5;
//  int expectedResultOfOddSwap = 40;
//  int expectedValueOfA = 25;
//  int expectedValueOfB = 15;

    int testArrayForResize[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//  int expectedResultOfResize[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

    int testArrayForConcat1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int testArrayForConcat2[5] = { 11, 22, 33, 44, 55};
//  int expectedResultOfConcat[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 11, 22, 33, 44, 55};

    int testArrayForSubArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    const int arrayStartIdx = 5, arrayLength = 4;
//  int expectedArraySub[4] = { 6, 7, 8, 9};
    
    //Testing maximum function (Works)
    cout << "Testing maximum:" << endl;
    cout << "test data: ";
    showArray(testForMax1, 10);
    cout << "Expected maximum: " << 9 << endl;
    cout << "Actual maximum:   " << maximum(testForMax1, 10);
    cout << "\ntest data: ";
    showArray(testForMax2, 10);
    cout << "Expected maximum: " << 16 << endl;
    cout << "Actual maximum:   " << maximum(testForMax2, 10);
    cout << endl << endl;

    //Testing oddSwap function(Works)
    cout << "Testing oddSwap" << endl;
    cout << "test data: testForOddSwapA:" << testForOddSwap1;
    cout << " testForOddSwapB:" << testForOddSwap2 << endl;
    cout << "Expected result: " << 40 << "  testForOddSwapA: ";
    cout << 25 << "  testForOddSwapB: " << 15 << endl;
    int sumHolder = oddSwap(&testForOddSwap1, &testForOddSwap2);
    cout << "Actual results : " << sumHolder;
    cout << "  testForOddSwapA: " << testForOddSwap1;
    cout << "  testForOddSwapB: " << testForOddSwap2;
    cout << endl << endl;

    //Testing resize function(Works)
    cout << "Testing resize:" << endl;
    cout << "test data: ";
    showArray(testArrayForResize, 10);
    cout << "Expected result: ";
    for(int i = 0; i < 10; i++){
            cout << testArrayForResize[i] << " ";
    }
    for(int i = 0; i < 10; i++) {
        if (i == 9) {
                    cout << -1;
        }else{
                    cout << -1 << " ";
        }
    }
    cout << "\nActual result:   ";
    int *resizeHolder = resize(testArrayForResize, 10);
    for(int i = 0; i < 20; i++) {
        if (i > 19) {
            cout << *(resizeHolder+i) << endl;
        }else{
            cout << *(resizeHolder+i) << " ";
        }
    }
    cout << endl << endl;

    //Testing concat function(Works)
    cout << "Testing concat:" << endl;
    cout << "test data: ";
    showArray(testArrayForConcat1, 10);
    cout << " and ";
    showArray(testArrayForConcat2, 5);
    cout << "Expected result: ";
    cout << "1 2 3 4 5 6 7 8 9 0 11 22 33 44 55 " << endl;
    int *concatHolder =
        concatenate(testArrayForConcat1, 10, testArrayForConcat2, 5);
    cout << "Actual result:   ";
    showArray(concatHolder, 15);
    cout << endl;

    //Testing subArray function(Works)
    cout << "Testing subArray:" << endl;
    cout << "test data: ";
    showArray(testArrayForSubArray, 10);
    cout << "start: " << arrayStartIdx << " ";
    cout << "length: " << arrayLength;
    cout << endl << "Expected result: 6 7 8 9" << endl;
    int *subHolder =
        subArray(testArrayForSubArray, arrayStartIdx, arrayLength);
    cout << "Actual result:   ";
    showArray(subHolder, arrayLength);
    cout << endl;

    delete [] concatHolder;
    delete [] subHolder;
    delete [] resizeHolder;
 
    return 0;
}

//***********************************************************
// showArray: displays the elements of an integer array in one line
//       separated by a space.
// array: an array of ints
// size: the number of ints in the array
//***********************************************************
void showArray (int *array, int size) {
    for (int i=0; i<size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//***********************************************************
// duplicateArray: creates a new array that contains the elements of the
//      array argument in the same order
// array: an array of ints
// size: the number of ints in the array
// returns a pointer to the new array.
//      If an invalid size is passed the function returns null.
// NOTE: it is the caller's responsibility to delete the returned array
//      when finished with it.
//***********************************************************
int *duplicateArray (int *arr, int size) {
   
   int *newArray;
   if (size <= 0)         //size must be positive
      return NULL;        //NULL is 0, an invalid address

   newArray = new int [size];  //allocate new array

   for (int index = 0; index < size; index++)
      newArray[index] = arr[index];  //copy to new array

   return newArray;
}

//***********************************************************
// maximum: take an integer array and returns the maximum value
//      in that array.
//
// arr: an array of ints
// size: the number of ints in the array
//
// returns: the max value of the array
//***********************************************************
int maximum(int *arr, int size) {
    int max = *arr;

    for (int i=0; i < size; i++) {
        if (max < *(arr+i)) {
            max = *(arr+i);
        }
    }

    return max;
}

//***********************************************************
// oddSwap: takes two ints and swaps them both (x = y, y = x)
//      and then multiplies them by 5 and returns the sum of both.
//
// x: the first integer value
// y: the second integer value
//
// returns: the sum of both values after being multiplied by 5.
//***********************************************************
int oddSwap (int *x, int *y) {
    int temp = *x;
    *x = *y * 5;
    *y = temp * 5;
    return  *x + *y;
}

//***********************************************************
// resize: take an integer array and returns a new array of ints
//      that is double the size of the original and filling it
//      with the value -1.
//
// array: an array of ints
// size: the number of ints in the array
//
// returns: the new array of integers
//***********************************************************
int *resize(int *array, int size) {
    int *newArray;

    if (size <= 0) {
        return NULL;
    }

    newArray = new int [size+size];

    for(int i = 0; i < size*2; i++){
        if(i > size-1) {
            newArray[i] = -1;
        }else{
            newArray[i] = array[i];
        }
    }

    return newArray;
}

//***********************************************************
// concatenate: takes two integer arrays and returns a new array
//      which is both arrays combined, the first array in front.
//
// arr: an array of ints
// size: the number of ints in the array
// arr2: an array of ints
// size2: the number of ints in the array
//
// returns: the combined arrays, first in front, second following.
//***********************************************************
int *concatenate(int *arr, int size, int *arr2, int size2) {
    int *newArray;

    if (size <= 0 || size2 <= 0) {
        return NULL;
    }

    newArray = new int [size+size2];

    for(int i = 0; i < (size+size2); i++) {
        if (i > size-1) {
            newArray[i] = arr2[i-size];
        }else {
            newArray[i] = arr[i];
        }
    }

    return newArray;
}

//***********************************************************
// subArray: take an integer array and a start value and a length value
//      which calls the duplicateArray function and returns the result
//      of that function which is the segment of the given array between
//      the start value and the length.
//
// array: an array of ints
// start: the value that the result starts
// length: the length of the array
//
// returns: the result of duplicate array, which is a segment
//      of the given array between the start length and the array length.
//***********************************************************
int *subArray (int *array, int start, int length) {
     int *result = duplicateArray((array+start), length);
     return result;
}
