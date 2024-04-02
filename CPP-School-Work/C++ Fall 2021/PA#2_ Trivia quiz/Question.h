// File Name: Question.h
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 9/21/2021
// Assignment Number: 2
// CS 2308 Fall 2021
//
// This is the Question header file. This includes the definition
// of the Question class and initializes it. This file will be
// included in both Question.cpp and QuizDriver.cpp in order to
// have the Question class available to make Question objects.

#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
using namespace std;

const int NUM_ANS_CHOICE = 4;

class Question
{
    public:
        Question();
        Question(string, string[], char);
        string getStem() const;
        string getAnswer(int) const;
        char getKey() const;
        string ask() const;

        void setStem(string);
        void setAnswers(string[]);
        void setKey(char);
        void cycle();

    private:
        string stem;
        string answerChoices[NUM_ANS_CHOICE];
        char answerKey;
};

#endif // QUESTION_H
