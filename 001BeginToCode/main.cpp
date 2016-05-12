#include <iostream>
#include <cstdlib>
#include "people.h"
using namespace std;

int main(int argc, char** argv) {
	// See how many arguments
	cout << "Argument Number: " << argc << endl;
	char* name = new char[MAX_NAME_LENGTH];
	int age = 0;
	if (argc < 3) {
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the age: ";
		cin >> age;
	} else {
		name = argv[1];
		age = atoi(argv[2]);
	}
	People p(name, age);
	cout << p.get_name() << ": " << p.get_age() << endl;
	cout << p.get_name() << " grows up." << endl;
	p.grow_up();
	cout << p.get_name() << ": " << p.get_age() << endl;
	return 0;
}
