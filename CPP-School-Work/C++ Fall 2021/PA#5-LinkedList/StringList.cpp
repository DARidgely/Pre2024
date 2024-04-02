// File Name: StringList.cpp
//
// Author: David Ridgely
//Collaborators: Melanie Garza
// Date: 11/4/2021
// Assignment Number: 5
// Instructor: Jill Seaman
//
// This file defines all of the functions in the StringList class.
// These functions help implement an interface that manipulates a
// list of strings.
//

#include "StringList.h"
#include <iostream>

StringList::StringList() {
    head = nullptr;
    tail = nullptr;
}

StringList::~StringList() {
    while (head) {
        popFront();
    }
}

int StringList::count() {
    int total = 0;
    StringNode *p = head;
    while(p != nullptr) {
        total++;
        p = p->next;
    }

    return total;
}

//No Loops
void StringList::pushLast(string newString) {
    StringNode *p = new StringNode;
    p->data = newString;
    p->next = nullptr;
    if(head==nullptr) {
        head = p;
    }else {
        tail->next = p;
    }

    tail = p;
}

void StringList::popFront() {
    if(head != nullptr){
        StringNode *temp = head;
        head = head->next;
        delete temp;
        if(head == nullptr) {
            tail = nullptr;
        }
    }
}

//No Loops
string StringList::last () {
    if(head == nullptr) {
        return "";
    }else {
        return tail->data;
    }
}

void StringList::display(ostream& out) {
    StringNode *p = head;

    while(p != nullptr) {
        out << p->data << endl;
        p = p->next;
    }
}

string StringList::concatenate(char x) {
    string str = "";
    StringNode *newNode = head;

    while(newNode) {
        str += newNode->data;
        if(newNode->next) {
            str += x;
        }
        newNode = newNode->next;
    }

    return str;
}

//No Loops
void StringList::moveToLast(string s) {
    StringNode *current = head;
    StringNode *previous = nullptr;
    
    while(current && current->data != s) {
        previous = current;
        current = current->next;
    }

    if(current && current!=tail) {
        if(previous) {
            previous->next = current->next;
        }else {
            head = head->next;
        }

        current->next = nullptr;
        tail->next = current;
        tail = current;
    }
}

string StringList::minimumUpTo(int i) {
    if(!head) {
        return "";
    }

    int pos = 0;
    StringNode *p = head;
    string min = p->data;
    p = p->next;
    pos++;
    while(p && pos <= i) {
        if(p->data < min) {
            min = p->data;
        }
        p = p->next;
        pos++;
    }
    return min;
}

void StringList::selectionSort() {
    if(head) {
        int c = count() - 1;
        for(int i = c; i >= 0; i--) {
            string str = minimumUpTo(i);
            moveToLast(str);
        }
    }
}