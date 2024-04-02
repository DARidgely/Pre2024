#include "NumberList.h"
#include <iostream>
using namespace std;

int main() {
  int size, integers;
  cout << "Enter a size for the list: ";
  cin >> size;
  NumberList testList;


  for(int i = 0; i < size; i++) {
    cout << "Enter an integer for the list: ";
    cin >> integers;
    testList.addNode(integers);
  }

  cout << "Printing the list..." << endl;
  cout << "\nThe list contains : ";
  testList.displayNode();
}
