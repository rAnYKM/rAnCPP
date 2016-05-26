#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
using namespace std;


template <class T>
class Node {
public:
	T value;
	Node<T>* next;
	Node(T v=NULL, Node<T>* n=NULL) : value(v), next(n) {} 
};

template <class T>
class LinkedList {

template <class S>
friend ostream& operator<<(ostream &os, const LinkedList<S> &m);

private:
	Node<T>* head;
	void recursive_delete(Node<T> *p) {
		if (p->next != NULL) recursive_delete(p->next);
		delete p;
	}
public:
	// Note that the head node never include
	LinkedList(T elem) {
		head = new Node<T>();
		Node<T>* tmp = new Node<T>(elem);
		head->next = tmp; 
	}

	~LinkedList() {
		recursive_delete(head);
	}

	void append(T elem) {
		Node<T>* ptr;
		for(ptr = head; ptr->next != NULL; ptr = ptr->next);
		Node<T>* tmp = new Node<T>(elem);
		ptr->next = tmp;
	}

	T dequeue() {
		Node<T>* ptr;
		try {
			if (head->next == NULL) {
				throw -1;	
			}
			for(ptr = head; ptr->next->next != NULL; ptr = ptr->next);
			T val = ptr->next->value;
			Node<T>* tmp = ptr->next;
			ptr->next = NULL;
			delete tmp;
			return val;
		}
		catch(int e) {
			cout << "ERROR: Empty LinkedList" << endl;
		}
	}

	void push(T elem) {
		//add a new element like a stack
		Node<T>* tmp = new Node<T>(elem, head->next);
		head->next = tmp;
	}

	T pop() {
		T val = head->next->value;
		Node<T>* tmp = head->next;
		head->next = tmp->next;
		delete tmp;
		return val;
	}

	void display() {
		for(Node<T>* ptr = head->next; ptr != NULL; ptr = ptr->next) {
			cout << ptr->value << "->";
		}
		cout << endl;

	}

};

template <class T>
ostream& operator<<(ostream &os, const LinkedList<T> &m) {
	if (m.head->next == NULL) {
		os << endl;
	} 
	else {
		for(Node<T>* ptr = m.head->next; ptr != NULL; ptr = ptr->next) {
			os << ptr->value << endl;
		}
	}
	return os;
}

#endif

