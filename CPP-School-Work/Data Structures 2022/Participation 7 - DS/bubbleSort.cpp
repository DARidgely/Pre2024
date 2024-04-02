#include <iostream>
using namespace std;

template <typename T>

void bubbleSort(T array[], int n) {
  T temp;
  
  for(int i = 0; i < n-1; i++) {
    
     for(int j = 0; j < n-i-1; j++) {
       if(array[j] > array[j+1]) {
         temp = array[j];
         array[j] = array[j+1];
         array[j+1] = temp;
       }
     }
  }
  
}

int main() {
  int intArray[] = {5, 3, 7, 6, 1};
  int size = 5;
  for(int i = 0; i < size; i++) {
    cout << intArray[i] << " ";
  }
  cout << endl;
  cout << "Sorting array..." << endl;
  bubbleSort(intArray, size);
  for(int i = 0; i < size; i++) {
    cout << intArray[i] << " ";
  }
  cout << endl << endl;

  char charArray[] = {'b', 'a', 'i', 'd', 'e'};
  for(int i = 0; i < size; i++) {
    cout << charArray[i] << " ";
  }
  cout << endl;
  cout << "Sorting Array..." << endl;
  bubbleSort(charArray, size);
  for(int i = 0; i < size; i++) {
    cout << charArray[i] << " ";
  }
  cout << endl;
}
