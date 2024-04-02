#include <iostream>
using namespace std;

double pow(double x, int y) 
{
  if(x > 0) { // x is positive
    if(y > 0) { // y is postive
	  return x * pow(x, y-1);
	}else if(y < 0) { // if y is negative
	  return ((1/x) * pow(x, y+1));
	}else { // if y is 0
	  return 1;
	}
  }else { // x is negative
	if(y > 0) { // y is positive
	  return x * pow(x, y-1);
	}else if(y < 0) { // y is negative
	  return ((1/x) * pow(x, y+1));
	}else { // y is 0
	  return -1;
	}
  }
}

int main()
{
	cout << "To calculate x^y ..." << endl;
	
	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;
	
	if(x == 0) { // x = 0
		if (y > 0) // if y is positive and not equal to 0
			cout << 0 << endl;
		else  // if y <= 0
			cout << "x^y is not defined" <<endl;
	}
	else  // if x > 0 or x < 0 (postive or negative and not equal to 0)
		cout << pow(x,y) << endl;
		
		
	return 0;
}

