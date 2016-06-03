#include "tree.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	streambuf* backup = cout.rdbuf();
	ifstream in("in.txt");
	ofstream out("out.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	BinaryTree<int> t1, t2;
	t1.createTree(0);
	t2.createTree(0);
	t1.preOrder();
	t2.postOrder();
	t1.iterPostOrder();
	if(t1 == t2) cout<< "Y" <<endl;
	else cout << "N" << endl;
	cout.rdbuf(backup);
	return 0;
}
