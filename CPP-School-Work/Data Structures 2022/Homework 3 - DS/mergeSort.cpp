#include <iostream>
using namespace std;

// Merges two sorted subarrays of A[]. 
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{
  int subArrOne = m - l + 1;
  int subArrTwo = r - m;

  int *leftArr = new int[subArrOne];
  int *rightArr = new int[subArrTwo];

  for(int i = 0; i < subArrOne; i++) {
    leftArr[i] = A[l+i];
  }
  for(int i = 0; i < subArrTwo; i++) {
    rightArr[i] = A[m+1+i];
  }

  int leftIndex = 0;
  int rightIndex = 0;
  int mergedIndex = l;

  while(leftIndex < subArrOne && rightIndex < subArrTwo) {
    if(leftArr[leftIndex] <= rightArr[rightIndex]) {
      A[mergedIndex] = leftArr[leftIndex];
      leftIndex++;
    }else {
      A[mergedIndex] = rightArr[rightIndex];
      rightIndex++;
    }
    mergedIndex++;
  }

  while(leftIndex < subArrOne) {
    A[mergedIndex] = leftArr[leftIndex];
    leftIndex++;
    mergedIndex++;
  }

  while(rightIndex < subArrTwo) {
    A[mergedIndex] = rightArr[rightIndex];
    rightIndex++;
    mergedIndex++;
  }

}

// using mergeSort to sort sub-array A[l..r]  
// l is for left index and r is right index of the 
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r)
{
  if(l < r) {
    int mid = (l+r)/2;
    mergeSort(A, l, mid);
    mergeSort(A, mid+1, r);
    merge(A, l, mid, r);
  }
  return;
}


int main()
{
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;
	
	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}
	
	int* A = new int [n];
	
	cout << "Please enter each element in the array" << endl; 
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
  
    cout << "Given array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
  
    mergeSort(A, 0, n-1); 
  
    cout << "After mergeSort, sorted array A[] is: "; 
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;
	
	
	delete [] A;
    return 0;
}
