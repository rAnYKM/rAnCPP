#include "people.h"

People::People(const char* n, const int &a) : name((char*) n), age(a) {
	//TODO: Add more functions here
}

char* People::get_name() {
	return name;
}

int People::get_age() {
	return age;
}

void People::grow_up() {
	age++;
}
