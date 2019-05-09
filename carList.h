
#ifndef CAR_LIST // include guard
#define CAR_LIST

#include <fstream>
#include "car.h"

using namespace std;

class CarList {

  private:
    CarType carList[10000];
    int size;

  public:
    CarList(char fileName[100]);
    void print();
    void searchByTitle();
};

#endif