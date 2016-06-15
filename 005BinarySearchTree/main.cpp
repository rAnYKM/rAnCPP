#include <iostream>
#include "avl_tree.h"
using namespace std;

int main() 
{
	AVL_Tree avl;
	avl.insert(1);
	avl.insert(9);
	avl.insert(7);
	avl.insert(3);
	avl.insert(2);
	avl.insert(4);
	avl.insert(5);
	avl.insert(6);
	avl.insert(8);
	avl.traversal();
	avl.remove(5);
	cout << avl.has_key(5) << endl;
	avl.removeMin();
	avl.traversal();
	return 0;
}