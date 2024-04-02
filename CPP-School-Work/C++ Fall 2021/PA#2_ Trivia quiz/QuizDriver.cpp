// File Name: QuizDriver.cpp
//
// Author: David Ridgely
// Collaborators: Melanie Garza
// Date: 9/21/2021
// Assignment Number: 2
// CS 2308 Fall 2021
//
// This program will create an array of the 5 Question objects which is
// called by including the Question.h file. It will then get the Stem from
// the questions.txt file and cycle the answer choices. Then the program will
// ask the user a question, show answer choices, and then ask for an answer
// input. The program will then display the Answer key and show how many
// correct answers out of 5.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "Question.h"

const int NUM_QUESTIONS = 5;

int main() {
    vector<Question> triviaQuiz;
    Question currQuestion;
    ifstream fin("questions.txt");
    string inStem, inAnswers[NUM_ANS_CHOICE], garbage;
    char inKey, userAnswer[NUM_QUESTIONS];
    int answersCorrect = 0;

    if(fin.is_open()) {

        for(int i = 0; i < NUM_QUESTIONS; i++) {
            getline(fin, inStem);
            currQuestion.setStem(inStem);

            for(int j = 0; j < NUM_ANS_CHOICE; j++) {
                getline(fin, inAnswers[j]);
            }
            currQuestion.setAnswers(inAnswers);

            fin >> inKey;
            currQuestion.setKey(inKey);
            triviaQuiz.push_back(currQuestion);
            getline(fin, garbage);
        }

        for(int i = 0; i < NUM_QUESTIONS; i++) {
            currQuestion = triviaQuiz.at(i);
            currQuestion.cycle();
            triviaQuiz.at(i).setKey(currQuestion.getKey());
            cout << (i+1) << ". " << currQuestion.ask();
            cout << "Your answer (enter the letter): ";
            cout << endl;
            cin >> userAnswer[i];
            if(islower(userAnswer[i])) {
                userAnswer[i] = userAnswer[i] - 32;
            }
        }

        cout << "Answers: " << endl;
        for(int i = 0; i < NUM_QUESTIONS; i++) {
            currQuestion = triviaQuiz.at(i);
            cout << currQuestion.getKey() << " ";
        }
        cout << endl << endl;

        cout << "Your score out of 5: ";
        for(int i = 0; i < NUM_QUESTIONS; i++) {
            currQuestion = triviaQuiz.at(i);
            if(userAnswer[i] == currQuestion.getKey()) {
                answersCorrect++;
            }
        }
        cout << answersCorrect << endl;

    }else {
        cout << "Unable to open file" << endl;
    }



    fin.close();
}
