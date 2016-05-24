#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<int> jason(1);
	jason.append(2);
	jason.append(3);
	jason.append(4);
	cout << jason.dequeue() << "," << jason.pop() << "," << jason.dequeue() << "," << jason.pop() << endl;
	jason.dequeue();
	jason.display();
	return 0;
}
