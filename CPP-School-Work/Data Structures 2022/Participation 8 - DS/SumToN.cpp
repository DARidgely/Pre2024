#include <iostream>
using namespace std;

int sumToN(int n) {
  if(n == 0) {
    return 0;
  }else {
    return n + sumToN(n-1);
  }
}

int main() {
  int input, sum;

  cout << "Input a number to sum to: ";
  cin >> input;

  cout << "Calculating the sum..." << endl;
  sum = sumToN(input);
  cout << "The sum is: " << sum << endl;

  return 0;
}
