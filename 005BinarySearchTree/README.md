# Binary Search Tree

## Definition

*[Princeton CS Slides](http://algs4.cs.princeton.edu/lectures/32BinarySearchTrees.pdf)* A Binary Search Tree (BST) is a binary tree in symmetric order. Each node has a key which is **larger** than all keys in its **left subtree** and **smaller** than all keys in its **right subtree**. 

*[Wikipeida](https://en.wikipedia.org/wiki/Binary_search_tree)* A binary search tree is a rooted binary tree, whose internal nodes each store a key (and optionally, an associated value) and each have two distinguished sub-trees, commonly denoted left and right. The tree additionally satisfies the binary search tree property, which states that the key in each node must be greater than all keys stored in the left sub-tree, and smaller than all keys in right sub-tree.

## Basic Terms

**Maximum** Largest key in the tree

**Minimum** Smallest key in the tree

**Floor** Largest key no larger than a given key

*How to get the floor of a given key?*

- equal: the floor of *k* is *k*

- less: the floor of *k* is in the left subtree

- greater: the floor of *k* is in the right subtree if there is any key no larger than *k* in right tree; otherwise it is the key in the node

**Ceiling** Smaillest key no smaller than a given key

## Basic Operations

**Search** If less go left, if greater go right; if equal, search hit.

**Insert** If less, go left; if greater, go right; if null, insert.

**Rank** Count the number of keys less than *k* (Recall how to get the size of a binary tree)

**Traversal** In BST, to retrieve all keys in the increasing order, in-order traversal is adopted

**Deletion** *(remove a node with a given key)* If no children, simply remove the node; if one child, replace the node with its child; if two children, follow the steps below.

Choose either its in-order successor node or its in-order predecessor node, *j*. Copy the value of *j* to *k*, then recursively call delete on *j* until reaching one of the first two cases. If you choose in-order successor of a node, as right sub tree is not NIL (Our present case is node has 2 children), then its in-order successor is node with least value in its right sub tree, which will have at a maximum of 1 sub tree, so deleting it would fall in one of the first 2 cases.

*(delete the minimum key)* 1. Go left until finding a node with null left link 2. Replace that node by its right link 3. Update subtree counts

## Balanced Search Trees

Balanced Search Trees include: [2-3 tree](https://en.wikipedia.org/wiki/2-3_tree), [AA tree](https://en.wikipedia.org/wiki/AA_tree), [AVL tree](https://en.wikipedia.org/wiki/AVL_tree), [Red-black tree](https://en.wikipedia.org/wiki/Red-black_tree), etc.

### AVL tree

*“An AVL tree is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.” - Wikipedia*

**Balance factor** the balance factor of a node *N* is defined to be the height difference of its left subtree and right subtree.


