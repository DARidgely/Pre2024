#include <iostream>
using namespace std;

template <typename T>

void swapValues(T &a, T &b) {
  T temp;
  temp = a;
  a = b;
  b = temp;
}

int main() {
  
  int value1 = 5;
  int value2 = 6;
  cout << value1 << " and " << value2 << endl;
  swapValues(value1, value2);
  cout << value1 << " and " << value2 << " swapped." << endl;

  double value3 = 3.0;
  double value4 = 6.0;
  cout << value3 << " and " << value4 << endl;
  swapValues(value3, value4);
  cout << value3 << " and " << value4 << " swapped." << endl;

  char x = 'x';
  char y = 'y';
  cout << x << " and " << y << endl;
  swapValues(x, y);
  cout << x << " and " << y << " swapped." << endl;

  string hello = "Hello";
  string world = "World!";
  cout << hello << " " << world << endl;
  swapValues(hello, world);
  cout << hello << " " << world << endl;

  return 0;
}
