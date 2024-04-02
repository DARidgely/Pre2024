#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

char searchString(string str, int i=0) {
    if(str[i] == 0) {
        return 0;
    }
    if(isupper(str[i])){
        return str[i];
    }
    return searchString(str, i++);
}


int main() {
    string userInput;
    char returnedChar;

    cout << "Input a string: ";
    cin >> userInput;

    cout << "Searching for uppercase letter..." << endl;
    cout << endl;
    returnedChar = searchString(userInput);

    if(returnedChar == 0) {
        cout << "No uppercase letter in string." << endl;
    }else {
        cout << "The uppercase letter is: " << returnedChar << endl;
    }
    
    return 0;
}