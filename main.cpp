#include <iostream>
#include "School.h"

int main(int argc, char* argv[]) {
	cout << "|----------------------------|" << endl;
	cout << "| Perfect School Database TM |" << endl;
	cout << "|       Chapter 2: C++       |" << endl;
	cout << "|----------------------------|" << endl << endl;

	cout << "Your database name: " << argv[1] << endl;
	School* school = new School();
	school->initFromFile(argv[1]);

	bool check = true;
	while (check) {
		cout << "=====================================================" << endl << endl;
		cout << "Please, choose your action:" << endl;
		cout << "1) Add new assignment to database" << endl;
		cout << "2) Find information by Class" << endl;
		cout << "3) Find information by Classhead's lastname" << endl;
		cout << "4) Find information by Teacher's lastname" << endl;
		cout << "5) Print Database file" << endl;
		cout << "6) Change data about Class" << endl;
		cout << "7) Delete information about Class" << endl;
		cout << "0) Any other input will close this app" << endl << endl;

		int choice;
		cout << "Your choice: ";
		cin >> choice;
		Info* info;
		char* tmp = new char[30];

		switch (choice)
		{
		case 1:
			info = new Info();
			info->fillInfo();
			school->addClass(info);
			cout << "New class added" << endl << endl;
			break;
		case 2:
			cout<<"Enter Class: ";
			cin >> tmp;
			info = school->findByClass(tmp);
			if (info == NULL) {
				cout << "There is no Class " << tmp << endl << endl;
			}
			else {
				cout << info->toString() << endl << endl;
			}
			delete tmp;
			break;
		case 3:
			cout<<"Enter Classhead's lastname: ";
			cin >> tmp;
			info = school->findByClass(tmp);
			if (info == NULL) {
				cout << "There is no Classhead" << tmp << endl << endl;
			}
			else {
				cout << info->toString() << endl << endl;
			}
			delete tmp;
			break;
		case 4:
			cout << "Teacher's lastame: ";
			cin >> tmp;
			info = school->findByClass(tmp);
			if (info == NULL) {
				cout << "There is no Teacher " << endl << endl;
			}
			else {
				cout << info->toString() << endl << endl;
			}
			delete tmp;
			break;
		case 5:
			school->printAllClasses();
			cout << endl;
			break;
		case 6:
			cout << "Enter Class to change information about: ";
			cin >> tmp;
			school->changeClass(tmp);
			cout << endl;
			break;
		case 7:
			cout << "Enter Class to delete: ";
			cin >> tmp;
			school->removeClass(tmp);
			cout << endl;
			break;
		default:
			school->saveToFile(argv[1]);
			check = false;
		}
		school->saveToFile(argv[1]);
		
	}


}
