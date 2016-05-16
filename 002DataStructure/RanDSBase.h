#ifndef _RANDSBASE_H
#define _RANDSBASE_H

#include <iostream>
using namespace std;

template <class T>
class RanDSBase {
protected:
    T *elem;
    int length;
    int maxSize;

public:
    RanDSBase(int m=10);
    RanDSBase(const RanDSBase<T> &mRan);
    ~RanDSBase(){
        delete []elem;
        delete elem;
        cout << "Destructed!" << endl;
    }
    virtual void push(const T &x)=0;
    virtual T pop()=0;
    // Try to remove ''virtual'' from function display()
    virtual void display() {
        for(int i = 0; i < length; i++) {
            cout << elem[i] << endl;
        }
        cout << "OUTPUT FROM BASE CLASS" << endl;
    }
};

template <class T>
RanDSBase<T>::RanDSBase(int m) {
    elem = new T[m];
    maxSize = m;
    length = 0;
}

template <class T>
RanDSBase<T>::RanDSBase(const RanDSBase<T> &mRan) {
    maxSize = mRan.maxSize;
    length = mRan.length;
	elem = new T[maxSize];
	for(int i = 0; i < length; i++) {
		elem[i]=mRan.elem[i];
	}
}


#endif
