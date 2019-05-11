#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "carList.h"

using namespace std;

int const MAX_CHAR = 100;

enum SearchOptions {
  QUIT_SEARCH = 0,
  TITLE_SEARCH = 1,
  MODEL_SEARCH = 2,
  ORIGIN_SEARCH = 3
};

void search(CarList carList);

int main() {
  char fileName[100] = "cars.txt";
  char cmd = 'a';

  CarList carList(fileName);

  cout << "\n\nHello and welcom to project 2!\n\n";

  while(tolower(cmd) != 'q') {
    cout << "------MAIN MENU--------\n"
         << "Please select an option. Enter \n\n"
         << "S to search cars by title, model, or origin\n"
         << "P to print all cars\n"
         << "R to remove a car\n"
         << "A to add a car\n";
    cin >> cmd;

    switch(tolower(cmd)){
      case 's':
        search(carList);
        break;

      case 'p':
        carList.print();
        break;

      case 'r':
        carList.remove();
        break;

      case 'a':
        carList.addCar();
        break;

      case 'q':
        // outFile.close();
        cout << "Goodbye" << endl;
        break;

      default:
        cout << "Please enter a valid option.\n";
        break;
    }
  }

  return 0;
}

void search(CarList carList) {
	int searchSelect = 1;
	double weightTerm;
	char searchTerm[200];

	cout << "\n------SEARCH MENU------\n";

	while(searchSelect != QUIT_SEARCH) {

		char searchPrompt[1000] = "\nPlease select a search criteria:\n\n"
			"search by title: 1\n"
			"search by model: 2\n"
			"search by origin: 3\n"
			"return to main menu: 0\n";

		getInt(searchSelect, searchPrompt);

		switch (searchSelect) {
			case QUIT_SEARCH:
				break;

			case TITLE_SEARCH:
				cout << "Enter search term: " << endl;
				carList.searchByTitle();
				break;

			case MODEL_SEARCH:
				carList.searchByModel();
				break;

			case ORIGIN_SEARCH:
				carList.searchByOrigin();
				break;

			default:
				cout << "Please enter a valid option";
		}
	}

  return;
}

