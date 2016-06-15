#ifndef _AVL_TREE_H
#define _AVL_TREE_H

#include <iostream>
using namespace std;

struct TreeNode
{
	int key;
	TreeNode* left;
	TreeNode* right;
	unsigned char height;
	TreeNode(int k)
	{
		key = k;
		left = NULL;
		right = NULL;
		height = 1;
	}
};

class AVL_Tree
{
	private:
		TreeNode* root;
	
	public:
		AVL_Tree();
		~AVL_Tree();
		void insert(int n);
		void remove(int n);
		void removeMin();
		bool has_key(int k);
		void traversal();
		TreeNode* findMin();
		TreeNode* balance(TreeNode* p);

	private:
		unsigned char height(TreeNode* p);
		int balanceFactor(TreeNode* p);
		void fixHeight(TreeNode* p);
		void _traversal(TreeNode* p);
		TreeNode* _insert(TreeNode* p, int k);
		TreeNode* _remove(TreeNode* p, int k);
		TreeNode* _findMin(TreeNode* p);
		TreeNode* _removeMin(TreeNode* p);
		TreeNode* rotateRight(TreeNode* p);
		TreeNode* rotateLeft(TreeNode* p);
		void clear(TreeNode* p);
};

AVL_Tree::AVL_Tree()
{
	root = NULL;
}

AVL_Tree::~AVL_Tree()
{
	clear(root);
}

void AVL_Tree::clear(TreeNode* p)
{
	if(p == NULL) return;
	if(p->left != NULL) clear(p->left);
	if(p->right != NULL) clear(p->right);
	delete p;
}
		
unsigned char AVL_Tree::height(TreeNode* p)
{
	return p ? p->height : 0;
}

int AVL_Tree::balanceFactor(TreeNode* p)
{
	return height(p->right) - height(p->left);
}

void AVL_Tree::fixHeight(TreeNode* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr ? hl : hr) + 1;
}

TreeNode* AVL_Tree::rotateRight(TreeNode* p)
{
	TreeNode* tmp = p->left;
	p->left = tmp->right;
	tmp->right = p;
	fixHeight(tmp);
	fixHeight(p);
	return tmp;
}

TreeNode* AVL_Tree::rotateLeft(TreeNode* p)
{
	TreeNode* tmp = p->right;
	p->right = tmp->left;
	tmp->left = p; 
	fixHeight(p);
	fixHeight(tmp);
	return tmp;
}

TreeNode* AVL_Tree::balance(TreeNode* p)
{
	fixHeight(p);
	if(balanceFactor(p) == 2)
	{
		if(balanceFactor(p->right) < 0)
			p->right = rotateRight(p->right);
		return rotateLeft(p);
	}
	else if(balanceFactor(p) == -2)
	{
		if(balanceFactor(p->left) > 0)
			p->left = rotateLeft(p->left);
		return rotateRight(p);
	}
	return p;
}

void AVL_Tree::insert(int n)
{
	if(root == NULL) root = new TreeNode(n);
	else root = _insert(root, n);
}

TreeNode* AVL_Tree::_insert(TreeNode* p, int k)
{
	if(!p) 
	{
		p = new TreeNode(k);
		return p;
	}
	if(k < p->key)
		p->left = _insert(p->left, k);
	else
		p->right = _insert(p->right, k);
	return balance(p);
}

bool AVL_Tree::has_key(int k)
{
	if(root == NULL) return false;
	TreeNode* p = root;
	while(true)
	{
		if(k == p->key) return true;
		else if(k < p->key)
			if(p->left) p = p->left;
			else return false;
		else if(p->right) p = p->right;
			else return false; 
	}
}

TreeNode* AVL_Tree::findMin()
{
    return _findMin(root);
}

void AVL_Tree::removeMin()
{
    root = _removeMin(root);
}

TreeNode* AVL_Tree::_findMin(TreeNode* p)
{
    return p->left ? _findMin(p->left) : p;
}

TreeNode* AVL_Tree::_removeMin(TreeNode* p)
{
    if(p->left == 0)
        return p->right;
    p->left = _removeMin(p->left);
    return balance(p);
}

void AVL_Tree::remove(int k)
{
	if(!has_key(k)) return;
	else
		root = _remove(root, k);
}

TreeNode* AVL_Tree::_remove(TreeNode* p, int k) // deleting k key from p tree
{
    if(!p) return 0;
    if(k < p->key)
        p->left = _remove(p->left,k);
    else if(k > p->key)
        p->right = _remove(p->right,k);  
    else
    {
        TreeNode* q = p->left;
        TreeNode* r = p->right;
        delete p;
        if(!r) return q;
        TreeNode* min = _findMin(r);
        min->right = _removeMin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

void AVL_Tree::traversal()
{
	_traversal(root);
	cout << endl;
}

void AVL_Tree::_traversal(TreeNode* p)
{
	if(p == NULL) return;
	if(p->left != NULL) _traversal(p->left);
	cout << p->key << ' ';
	if(p->right != NULL) _traversal(p->right);
}

#endif
