#include <iostream>
#include "myStack.h"

using namespace std;

void postfixTest() 
{
	myStack operandStack(100);
	bool error = true;
	cout << "Please enter the operands (integers 1~9) and operators (+, -, *, /) one by one..." << endl;
	cout << "and enter '=' to indicate the end of the expression and to output the result." << endl;

	while(1)
	{
		char inputHolder;
		int flag = 0;

		while(inputHolder != '=') {
			cin >> inputHolder;
			if(inputHolder >= 49 && inputHolder <= 57) {
				operandStack.push(inputHolder-48);
				flag++;
			}else if(inputHolder == '+' && flag >= 2) {
				int operand1 = operandStack.pop();
				int operand2 = operandStack.pop();
				flag--;

				operandStack.push(operand1 + operand2);
			}else if(inputHolder == '-' && flag >= 2) {
				int operand1 = operandStack.pop();
				int operand2 = operandStack.pop();
				flag--;

				operandStack.push(operand2 - operand1);
			}else if(inputHolder == '*' && flag >= 2) {
				int operand1 = operandStack.pop();
				int operand2 = operandStack.pop();
				flag--;

				operandStack.push(operand1 * operand2);
			}else if(inputHolder == '/' && flag >= 2) {
				int operand1 = operandStack.pop();
				int operand2 = operandStack.pop();
				flag--;

				operandStack.push(operand1 / operand2);
			}else if(inputHolder == '+' && inputHolder == '-' && inputHolder == '*' && inputHolder == '/') {
				cout << "Error! No sufficient operands." << endl;
				error = false;
			}else if(inputHolder != '='){
				cout << "Error! No sufficient operands." << endl;
				error = false;
			}else if(flag > 1){
				cout << "The entered post-fix expression was not a legal one." << endl;
				error = false;
			}
			
		}

		break;

	}
	if(error)
		cout << "\nThe result is: " << operandStack.pop() << endl;
}

int main()
{
    cout << "Testing the basic functions of the stack..." << endl;
	cout << "Please enter the max capacity of the testStack: ";
	int testSize;
	cin >> testSize;
	myStack testStack(testSize);
	
	cout << "Testing..." << endl;
	while(1)
	{
		cout << "Please enter 'p' for push, 'o' for pop, 'e' for exit:  ";
		char userChoice;
		cin >> userChoice;
		
		if(userChoice == 'e')
			break;
		
		switch (userChoice) 
		{
			case 'p':			
				if(!testStack.isFull()) 
				{
					cout << "Please enter the integer you would like to push: ";
					int userInt;
					cin >> userInt;
					testStack.push(userInt);
				}
				else
					cout << "Nothing has been pushed in. The stack is full!" << endl;
				break;
			case 'o':
				if(!testStack.isEmpty())
					cout << testStack.pop() << " has been popped out" << endl;
				else
					cout << "Nothing has been popped out. The stack is empty!" << endl;
				break;
			default:
				cout << "Illegal user-input character. Please try again." << endl;
		}
	}

	cout << "Now, start to use a stack to evaluate postfix expressions..." << endl;
	postfixTest();
	
	cout << endl;
	return 0;
}

