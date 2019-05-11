
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "car.h"
#include "carList.h"

using namespace std;

CarList::CarList(char fileName[]) {

  size = 0;

  ifstream inFile;
  inFile.open(fileName);

  inFile.clear();
  inFile.seekg(0);

  CarType car;

  char title[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[200];
  Origin enumOrigin;

  while(!inFile.eof()) {

    inFile.get(title, 200, ';');
    car.setTitle(title);
    inFile.ignore(200, ';');

    inFile >> mpg;
    car.setMpg(mpg);
    inFile.ignore(100, ';');

    inFile >> cylinders;
    car.setCylinders(cylinders);
    inFile.ignore(100, ';');

    inFile >> displacement;
    car.setDisplacement(displacement);
    inFile.ignore(100, ';');

    inFile >> horsepower;
    car.setHorsepower(horsepower);
    inFile.ignore(100, ';');

    inFile >> weight;
    car.setWeight(weight);
    inFile.ignore(100, ';');

    inFile >> acceleration;
    car.setAcceleration(acceleration);
    inFile.ignore(100, ';');

    inFile >> model;
    car.setModel(model);
    inFile.ignore(100, ';');

    inFile.get(origin, 200, '\n');

    if (strcmp(origin, "Europe") == 0) {
    	enumOrigin = EUROPE;
    } else if (strcmp(origin, "US") == 0) {
    	enumOrigin = US;
    } else if (strcmp(origin, "Japan") == 0) {
    	enumOrigin = JAPAN;
    }

    car.setOrigin(enumOrigin);
    inFile.ignore(200, '\n');

    carList[size] = car;
    size++;
  }
}


void CarList::searchByTitle() {
	char term[200];
  char carTitle[200];

  cin.ignore();
	cin.get(term, 200, '\n');

	for(int i = 0; i < size; i++) {
    carList[i].getTitle(carTitle);
		if(strstr(carTitle, term)) {
			carList[i].print();
		}
	}

	return;
}


void CarList::searchByModel() {
	int model;

	cout << "Enter model: \n";
	cin >> model;

	for(int i = 0; i < size; i++) {
    // cout << (carList[i].getModel() == model) << endl;
		if(carList[i].getModel() == model) {
			carList[i].print();
		}
	}

	return;
}

// void CarList::searchByOrigin(CarType cars[], int size) {
// 	bool validOrigin = false;
// 	int origin;
//
// 	do {
// 		cout << "\n\nSelect Origin:\n\n"
// 				 << "Europe: 0\n"
// 				 << "US: 1\n"
// 				 << "Japan: 2\n"
// 				 << endl;
//
// 		cin >> origin;
//
// 		cout << origin << US << JAPAN;
//
// 		switch (origin) {
// 			case EUROPE:
// 				validOrigin = true;
// 				break;
//
// 			case US:
// 				validOrigin = true;
// 				break;
//
// 			case JAPAN:
// 				validOrigin = true;
// 				break;
//
// 			default:
// 				cout << "Invalid Origin!\n";
// 		}
// 	} while(!validOrigin);
//
// 	for(int i = 0; i < size; i++) {
// 		if (cars[i].getOrigin() == origin) {
// 			printCar(carsList[i]);
// 		}
// 	}
//
// 	return;
// }


void CarList::print() {
  for(int i = 0; i < size; i++) {
    carList[i].print();
  }
  return;
}

