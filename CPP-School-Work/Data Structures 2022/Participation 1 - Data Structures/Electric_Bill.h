//**************************************************
// File Name: ElectricBill.h
//
// Author: David Ridgely
// Date: 7/5/2022
// Assignment: Participation 1 - Electric Bill
// CS 3358 Summer 2022
//**************************************************

#include <string>
using namespace std;

class Electric_Bill
{
  private:
    int customerNumber;
    string customerName;
    int electricityUsed;
    float billAmount;

  public:
    Electric_Bill();
    void setCustNum(int);
    int getCustNum();
    void setCustName(string);
    string getCustName();
    void setElecUsed(int);
    int getElecUsed();
    void setBillAmount(float);
    float getBillAmount();
    float calc_bill(int);
    void display();
};
