#include "stack.h"
#include <iostream>
using namespace std;

int main() {
  int testSize, stackInput, poppedResult;
  cout << "Please enter a test size: ";
  cin >> testSize;
  
  Stack<int> testStack(testSize);

  for(int i = 0; i < testSize; i++) {
    cout << "Please enter an integer to push onto the stack: " << endl;
    cin >> stackInput;
    testStack.push(stackInput);
  }
  
  poppedResult = testStack.pop();
  cout << "Popping the top value from the stack..." << endl;
  cout << "The top value was: " << poppedResult << endl;
  cout << "The new top value is: ";
  testStack.displayTop();
  cout << endl << endl;
  
  return 0;
}

