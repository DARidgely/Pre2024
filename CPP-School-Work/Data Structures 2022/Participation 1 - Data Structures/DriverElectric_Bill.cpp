//**************************************************
// File Name: main.cpp
//
// Author: David Ridgely
// Date: 7/5/2022
// Assignment: Participation 1 - Electric Bill
// CS 3358 Summer 2022
//**************************************************

#include "Electric_Bill.h"
#include <iostream>
using namespace std;

main() {
  Electric_Bill bill0;
  Electric_Bill bill1;
  string customerName = "John";
  int customerNum = 314;
  int elecUnits = 48;
  float billTotal;

  bill0 = Electric_Bill();
  bill0.display();

  bill1.setCustName(customerName);
  bill1.setCustNum(customerNum);
  bill1.setElecUsed(elecUnits);
  billTotal = bill1.calc_bill(elecUnits);
  bill1.setBillAmount(billTotal);
  bill1.display();

  cout << endl;

  return 0;
}
