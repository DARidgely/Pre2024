#include "NumberList.h"
#include <iostream>
using namespace std;

int main()
{
  NumberList list1;
  int insertNum = 4;
  int insertNum1 = 8;
  int insertNum2 = 28;
  int insertNum3 = 42;
  int removeNum = 8;

  list1 = NumberList();
  list1.display();
  list1.append(insertNum);
  list1.append(insertNum1);
  list1.display();
  list1.append(insertNum3);
  list1.insert(insertNum2, insertNum1);
  list1.display();
  list1.remove(removeNum);
  list1.display();
}