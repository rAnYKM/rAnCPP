#include <iostream>
#include <fstream>
#include <vector>
#include "ran_tree.h"
using namespace std;

int main() 
{
	streambuf* backup = cout.rdbuf();
	ifstream in("rin.txt");
	ofstream out("rout.txt");
	cin.rdbuf(in.rdbuf());
	cout.rdbuf(out.rdbuf());
	//get the size of tree
	int size1, size2;
	vector<int> ll1, ll2;
	cin >> size1;
	for(int i = 0; i < size1; ++i)
	{
		int tmp;
		cin >> tmp;
		ll1.push_back(tmp);
	}
	cin >> size2;
	for(int i = 0; i < size2; ++i)
	{
		int tmp;
		cin >> tmp;
		ll2.push_back(tmp);
	}
	BinaryTree<int> t1(ll1, -1), t2(ll2, -1);

	t1.preOrder();
	t1.midOrder();
	t1.postOrder();
	t2.postOrder();
	//t1.iterPostOrder();
	if(t1 == t2) cout<< "Y" <<endl;
	else cout << "N" << endl;
	cout.rdbuf(backup);
	return 0;

}