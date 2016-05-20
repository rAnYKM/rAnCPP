#include <iostream>
#include <fstream>
#define MAX_POST_LENGTH 200
#define MAX_SENSITIVE_LENGTH 20
#define MAX_NONSENSE_LENGTH 20
using namespace std;

bool inString(const char &n, char* str) {
	//return if a char appears in the given string
	for (char* ptr = str; *ptr != '\0'; ptr++)
		if (*ptr == n) return true;
	return false;
}

void copyChar(char* origin, char* dest) {
	char* sta;
	char* stb;
	for (sta = origin, stb = dest; *stb != '\0'; sta++, stb++) {
		*sta = *stb;
	}
	*sta = '\0';
}

void replaceWith(char* st, char* en, const char &n) {
	//replace a string clip with a single char
	//Example: r[a]ny{k}m, [] is st pointer, {} is en pointer, n = '#', then return r####m
	for (char* ptr = st; ptr != en; ptr++) {
		*ptr = n;
	}
}

void removeNonsense(char* origin, char* nonsense) {
	char new_post[MAX_POST_LENGTH];
	int current = 0;
	for (char* ptr = origin; *ptr != '\0'; ptr++) {
		if (inString(*ptr, nonsense)) {
			continue;
		}
		else {
			new_post[current++] = *ptr;
		}
	}
	new_post[current] = '\0'; // string end with '\0'
	copyChar(origin, new_post);
}


bool filter(char* origin, char* sensitive, char* nonsense) {
	// return True: changes, return False: no change
	char* clip_start = origin;
	char* clip_end = origin;
	char* ptr_sen = sensitive;
	bool flag = false; // nothing changed
	while (*clip_start != '\0' && *clip_end != '\0') {
		if (*clip_end == *ptr_sen) {
			clip_end++;
			ptr_sen++;
			if (*ptr_sen == '\0') {
				replaceWith(clip_start, clip_end, nonsense[0]);
				clip_start = clip_end;
				ptr_sen = sensitive;
				flag = true;
			}
		}
		else if (inString(*clip_end, nonsense)) {
			clip_end++;
		}
		else {
			//one case: interuptted from a potential item
			if (ptr_sen != sensitive) clip_start = clip_end;
			else {
				clip_end++;
				clip_start = clip_end;
			}
			ptr_sen = sensitive;
		}
	}
	return flag;
}

int main() {
	
	ifstream in("in.txt");
	ofstream out("out.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	
	char origin[MAX_POST_LENGTH];
	char sensitive[MAX_SENSITIVE_LENGTH];
	char nonsense[MAX_NONSENSE_LENGTH];
	cin.getline(origin, MAX_POST_LENGTH);
	cin.getline(sensitive, MAX_SENSITIVE_LENGTH);
	cin.getline(nonsense, MAX_NONSENSE_LENGTH);
	while (filter(origin, sensitive, nonsense));  //recursively test whether there is sensitive words
	removeNonsense(origin, nonsense);
	cout << origin << endl;
	return 0;
}