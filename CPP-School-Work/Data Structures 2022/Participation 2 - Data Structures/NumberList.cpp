#include "NumberList.h"
#include <iostream>
#include <cassert>
using namespace std;


NumberList::NumberList() {
  count = 0;
  size = 100;
}

bool NumberList::isEmpty() {
  return (count == 0);
}

bool NumberList::isFull() {
  return (count == size);
}

void NumberList::append(int num) {
  //Make sure list isn't full
  //put new element (num) at end of the array or at position count.
  //increment count
  if(isFull()) {
    cout << "\nError: The list is full." << endl;
    return;
  }else {
    list[count] = num;
    count++;
  }
}

void NumberList::insert(int numberToInsert, int target) {
  // check if full.
  // check if number given is in the list
  // if number given is found then insert the number at the given position
  // and shift everything so that the new number can be inserted correctly.
  int index;

  if(isFull()) {
    cout << "\nError: The list is full." << endl;
    return;
  }else {
    for(int i = 0; i < count; i++) {
      if(list[i] == target) {
        index = i;
        break;
      }else if(i == count){
        cout << "\nError: " << target << " is not in the list." << endl;
        return;
      }
    }

    if(index == count-1) {
      list[index+1] = numberToInsert;
      count++;
    }else {
      for(int i = count; i > index; i--) {
        list[i] = list[i-1];
        list[index+1] = numberToInsert;
      }
      count++;
    }
  }
}

void NumberList::remove(int numToDelete) {
  // check if empty.
  // check if number to delete is in list
  // if found shift; {3, 4, 6, 7} -> {3, 6 ,7} and count--
  // if index is the last index in the array, then count--
  int index;
  if(isEmpty()) {
    cout << "\nError: The list is empty." << endl;
    return;
  }else {

    for(int i = 0; i < count; i++) {
      if(numToDelete == list[i]) {
        index = i;
        break;
      }else if(i == count){
        cout << "\nError: " << numToDelete << " is not in the list." << endl;
        return;
      }
    }

    if(index == count-1) {
      count--;
    }else {
      for(int i = index; i < count; i++) {
        list[i] = list[i+1];
      }
      count--;
    }
  }
}

void NumberList::display() {
  // Use a for loop
  // Stop at count, not ARRAY_SIZE
  if(isEmpty()) {
    cout << "\nThe List is empty." << endl;
  }else {
    for(int i = 0; i < count; i++) {
    cout << "\nElement at index " << i << " is: " << list[i];
    }
    cout << endl;
  }
}