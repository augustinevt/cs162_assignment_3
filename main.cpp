#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "carList.h"

using namespace std;

int const MAX_CHAR = 100;

int main() {
  char fileName[100] = "cars.txt";

  CarList carList(fileName);

  carList.print();

  carList.searchByTitle();

  return 0;
}