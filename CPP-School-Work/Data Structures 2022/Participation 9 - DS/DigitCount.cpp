#include <iostream>
using namespace std;

int DigitCount(int num) {
  if(num < 10) {
    return 1;
  }else {
    return 1 + DigitCount(num/10);
  }
}

int main() {
  int input;

  cout << "Enter an integer: ";
  cin >> input;

  cout << "The amount of digits in " << input << " is: ";
  cout << DigitCount(input) << endl;

  return 0;
}
