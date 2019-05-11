#include <iostream>
#include <stdio.h>
#include "car.h"

using namespace std;

CarType::CarType() {
  char title[200];
  double mpg;
  int cylinders;
  double displacement;
  double horsepower;
  double weight;
  double acceleration;
  int model;
  char origin[200];
}

CarType::CarType(char newTitle[]) {
  strcpy(title, newTitle);
}

void CarType::print() {
  cout << title << ";"
       << mpg << ";"
       << cylinders << ";"
       << displacement << ";"
       << horsepower << ";"
       << weight << ";"
       << acceleration << ";"
       << model << ";";

  switch (origin) {
    case EUROPE:
      cout << "Europe;" << endl;
      break;
    case US:
      cout << "US;" << endl;
      break;
    default:
      cout << "Japan;" << endl;
      break;
  }

  return;
}

void CarType::setTitle(char newTitle[]) {
  strcpy(title, newTitle);
}

void CarType::getTitle(char outTitle[]) {
  strcpy(outTitle, title);
}

void CarType::setMpg(double newMpg) {
  mpg = newMpg;
  return;
}

void CarType::setCylinders(int newCylinders) {
  cylinders = newCylinders;
  return;
}

void CarType::setDisplacement(double newDisplacement) {
  displacement = newDisplacement;
  return;
}

void CarType::setHorsepower(double newHorsepower) {
  horsepower = newHorsepower;
  return;
}

void CarType::setWeight( double newWeight) {
  weight = newWeight;
  return;
}

void CarType::setAcceleration(double newAcceleration) {
  acceleration = newAcceleration;
  return;
}

void CarType::setModel(int newModel) {
  model = newModel;
  return;
}

int CarType::getModel() {
  return model;
}

void CarType::setOrigin(Origin newOrigin) {
  origin = newOrigin;
}

Origin CarType::getOrigin() {
  return origin;
}
