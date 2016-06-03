#ifndef _RAN_TREE_H
#define _RAN_TREE_H

#include <iostream>
#include <vector>
#include "ran_list.h"
using namespace std;

template <class Type>
class BinaryTree
{
private:
	struct Node {
		Node *left,*right;
		Type data;
		Node():left(NULL),right(NULL){}
		Node(Type item,Node *L=NULL,Node *R=NULL):
			data(item),left(L),right(R){}
		~Node(){}

	};
	Node *root;
	int height(Node *t) const
	{
		if(t == NULL)return 0;
		else
		{
			int lt = height(t->left), rt = height(t->right);
			return 1 + ((lt > rt)? lt:rt);
		}
	}

	void clear(Node *t)
	{
		if(t->left != NULL) clear(t->left);
		if(t->right != NULL) clear(t->right);
		delete t;
	}

	int size(Node *t) const
	{
		if(t == NULL) return 0;
		return 1 + size(t->left) + size(t->right);
	}

	void preOrder(Node *t) const
	{
		if(t != NULL)
		{
			cout << t->data << ' ';
			preOrder(t->left);
			preOrder(t->right);
		}
	}

	void midOrder(Node *t) const
	{
		if(t != NULL)
		{
			midOrder(t->left);
			cout << t->data << ' ';
			midOrder(t->right);
		}
	}

	void postOrder(Node *t) const
	{
		if(t != NULL)
		{
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << ' ';
		}
	}


public:
	BinaryTree():root(NULL){}
	BinaryTree(const Type &value){root=new Node(value);}
	BinaryTree(const vector<Type> &v, const Type &ch)
	{
		if(v.empty()) root = NULL;
		else
		{
			vector<Node*> nvec;
			for(int i = 0; i < v.size(); ++i)
			{
				Node *tmp = new Node(v[i], NULL, NULL);
				nvec.push_back(tmp);
			}
			for(int i = 0; i < v.size(); ++i)
			{
				if(i * 2 + 1 < v.size() && v[i * 2 + 1] != ch)
				{
					nvec[i]->left = nvec[i * 2 + 1];
				}
				if(i * 2 + 2 < v.size() && v[i * 2 + 2] != ch)
				{
					nvec[i]->right = nvec[i * 2 + 2];
				}
			}
			root = nvec[0];
		}
	}
	~BinaryTree(){clear();}
	void clear(){if(root!=NULL)clear(root);}

	Type getRoot() const {return root->data;}
	Type getLeft() const {return root->left->data;}
	Type getRight() const {return root->right->data;}

	bool operator==(const BinaryTree &t1)
	{
		linkStack<Node *>s1,s2;
		Node *c1,*c2;
		s1.push(root);
		s2.push(t1.root);
		while(!s1.isEmpty() && !s2.isEmpty())
		{
			c1=s1.pop();
			c2=s2.pop();
			if(c1->data!=c2->data)return false;
			else
			{
				if(c1->right != NULL && c2->right==NULL || 
						c1->right==NULL && c2->right!=NULL)return false;
				else
					if(c1->right != NULL && c2->right != NULL)
					{
						s1.push(c1->right);
						s2.push(c2->right);
					}
				if(c1->left!=NULL && c2->left==NULL || 
						c1->left==NULL && c2->left!=NULL)return false;
				else
					if(c1->left!=NULL && c2->left!=NULL){s1.push(c1->left);s2.push(c2->left);}
			}
		}
		return true;
	}
	void preOrder() const
	{
		if(root != NULL)
		{
			preOrder(root);
		}
		cout << endl;
	}

	void midOrder() const
	{
		if(root != NULL)
		{
			midOrder(root);
		}
		cout << endl;
	}

	void postOrder() const
	{
		if(root != NULL)
		{
			postOrder(root);
		}
		cout << endl;
	}

};

#endif