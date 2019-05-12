
#ifndef CAR_LIST // include guard
#define CAR_LIST

#include <fstream>
#include "car.h"

using namespace std;

void getInt(int &input, char prompt[200]);
void getDouble(double &input, char prompt[200]);


class CarList {

  private:
    CarType carList[10000];
    int size;

  public:
    CarList(char fileName[100]);
    void print();
    void searchByTitle();
    void searchByModel();
    void searchByOrigin();
    void remove();
    void addCar();
    void writeFile(char filename[200]);
};

#endif