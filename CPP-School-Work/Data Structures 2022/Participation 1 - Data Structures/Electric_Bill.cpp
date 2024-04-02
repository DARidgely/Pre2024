//**************************************************
// File Name: ElectricBill.cpp
//
// Author: David Ridgely
// Date: 7/5/2022
// Assignment: Participation 1 - Electric Bill
// CS 3358 Summer 2022
//**************************************************

#include "Electric_Bill.h"
#include <iostream>
using namespace std;

Electric_Bill::Electric_Bill()
{
  customerName = "";
  customerNumber = 0;
  electricityUsed = 0;
  billAmount = 0.0;
}

void Electric_Bill::display()
{
  cout << "\nCustomer Name: " << customerName;
  cout << "\nCustomer Number: " << customerNumber;
  cout << "\nUnits of Electricity Used: " << electricityUsed << " units.";
  cout << "\nBill Amount: " << billAmount;
}

void Electric_Bill::setCustNum(int num)
{
  customerNumber = num;
}

int Electric_Bill::getCustNum()
{
  return customerNumber;
}

void Electric_Bill::setCustName(string name)
{
  customerName = name;
}

string Electric_Bill::getCustName()
{
  return customerName;
}

void Electric_Bill::setElecUsed(int units)
{
  electricityUsed = units;
}

int Electric_Bill::getElecUsed()
{
  return electricityUsed;
}

void Electric_Bill::setBillAmount(float amount)
{
  billAmount = amount;
}

float Electric_Bill::getBillAmount()
{
    return billAmount;
}

float Electric_Bill::calc_bill(int unitsUsed)
{
  float totalCost;
  int temp;

  // if units of electricity used is under 100 then the total cost is that amount of units * 1.20
  // for example: 40*1.20 = 48 so totalCost = 48 and the bill would be $48.
  if (unitsUsed <= 100)
  {
    totalCost = unitsUsed * 1.20;
  }else if (unitsUsed > 100 && unitsUsed <= 300)
  {
    // if units of electricity used is greater than 100 and less than or equal to 300 then the
    // total cost is equal to 100*1.20 + any additional units * 2.
    // for example: 100*1.20 + 24*2 = 168 so totalCost = 168 and the bill would be $168.
    temp = unitsUsed - 100;
    totalCost = 100 * 1.20;
    totalCost += temp * 2;
  }else if (unitsUsed > 300)
  {
    // similar to the previous two, if electricity used is greater than 300 then the total cost
    // is equal to 100*1.20 + 200*2 + additional units * 3. This is because 100 + 200 = 300.
    // for example: 100*1.20 + 200*2 + 24*3 = 592 so totalCost = 592 and the bill would be $592.
    temp = unitsUsed - 300;
    totalCost = (100 * 1.20) + (200 * 2);
    totalCost += temp * 3;
  }

  return totalCost;
}
