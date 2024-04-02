// File Name: Question.cpp
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 9/21/2021
// Assignment Number: 2
// CS 2308 Fall 2021
//
// This is the Question class definition .cpp file. This includes
// all of the functions inside of the Question class. This allows
// for the QuizDriver.cpp to run and create Question objects.

#include "Question.h"

//***********************************************************
// Question: This is the default constructor for the Question
// class, which sets the variables to empty string or 'X' for
// the key.
//***********************************************************
Question::Question() {
    stem = "";
    answerKey = 'X';

    for(int i = 0; i < NUM_ANS_CHOICE; i++) {
        answerChoices[i] = "";
    }
}

//***********************************************************
// Question: This is a constructor for the Question class that
// sets the parameters to the variables, answerKey, stem, and
// the array of answerChoices.
//
// stemQ type string variable that asks for the stem question.
// choices array of strings that asks for stem answer choices.
// key type char variable that asks for the correct answer.
//***********************************************************
Question::Question(string stemQ, string choices[], char key) {
    stem = stemQ;
    answerKey = key;
    for (int i = 0; i < NUM_ANS_CHOICE; i++) {
        answerChoices[i] = choices[i];
    }
}

//***********************************************************
// getStem: This function when called will return the string
// for the stem question.
//
// returns: The Stem Question as a string.
//***********************************************************
string Question::getStem() const {
   return stem;
}

//***********************************************************
// getAnswer: This function gets the answer choice at a given
// index.
//
// answerIndex the int given is what will be used to get the
// answer choice for the given index.
// returns: the answer choice at a given index
//***********************************************************
string Question::getAnswer(int answerIndex) const {
    return answerChoices[answerIndex];
}

//***********************************************************
// getKey: This function when called will return the correct
// answer for the question.
//
// returns: based on the question this will return the correct
// answer that is given for the answer key.
//***********************************************************
char Question::getKey() const {
    return answerKey;
}

//***********************************************************
// ask: This function will put together a string of the full
// steam question and answer choices lettered as A, B, C, or D
//
// returns: the string fullStem is returned which includes the
// entire Question Stem and Question Answer Choices with their
// letter in front of them.
//***********************************************************
string Question::ask() const {
    string fullStem = stem + "\n";
    char answerChoice = 'A';
    string strAns;
    for(int i = 0; i < NUM_ANS_CHOICE; i++) {
        strAns = answerChoice + i;
        fullStem += (strAns) + ". " + answerChoices[i] + "\n";
    }

    return fullStem;
}

//***********************************************************
// setStem: This function will set the Stem that is given
//
// stemQuestion this is the question stem which is then set to
// the Question class stem variable.
//***********************************************************
void Question::setStem(string stemQuestion) {
    stem = stemQuestion;
}

//***********************************************************
// setAnswers: This function will set the answerChoices for
// the specific stem question.
//
// answers An array of strings that will but put into the
// answerChoices array.
//***********************************************************
void Question::setAnswers(string answers[]) {
    for(int i = 0; i < NUM_ANS_CHOICE; i++) {
        answerChoices[i] = answers[i];
    }
}

//***********************************************************
// setKey: This function will set the given correct answer to
// the answerKey as a char datatype.
//
// aKey This is the char for the correct answer of the question.
// which is then set to answerKey.
//***********************************************************
void Question::setKey(char aKey) {
    answerKey = aKey;
}

//***********************************************************
// cycle: This function will take the answerChoices for the
// question and move them "up" one in it's order. So A will be
// D, D will be C, C will be B, and B will be A. Once this is
// done it will update the answer key according to the move.
//***********************************************************
void Question::cycle() {
    string tempStr;

    tempStr = answerChoices[0]; //china
    answerChoices[0] = answerChoices[1]; //china>>india
    answerChoices[1] = answerChoices[2]; //india>>mexico
    answerChoices[2] = answerChoices[3]; //mexico>>australia
    answerChoices[3] = tempStr; //australia>>china

    if(answerKey == 'A') {
        setKey('D');
    }else {
        setKey(answerKey-1);
    }
}
