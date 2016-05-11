#ifndef _people_h
#define _people_h
#define MAX_NAME_LENGTH 10

class People {
private:
	char* name;
	int age;

public:
	People(const char* n, const int &a);
	char* get_name();
	int get_age();
	void grow_up();
};

#endif