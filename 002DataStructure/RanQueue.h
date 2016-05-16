#ifndef _RANQUEUE_H
#define _RANQUEUE_H

#include "RanDSBase.h"

template <class T>
class RanQueue: public RanDSBase<T> {
protected:
    int operation_number;
public:
    RanQueue(int m=10): RanDSBase<T>(m), operation_number(0) {}
    RanQueue(const RanDSBase<T> &mRan): RanDSBase<T>(mRan), operation_number(0) {}
    RanQueue(const RanQueue<T> &mRan) {
        this -> maxSize = mRan.maxSize;
        this -> length = mRan.length;
        this -> elem = new T[this->maxSize];
        for(int i = 0; i < this->length; i++) {
		this -> elem[i]=mRan.elem[i];
        }
        operation_number = mRan.operation_number;
    }
    void push(const T &x);
    T pop();
    void display();
};

template<class T>
void RanQueue<T>::push(const T &x) {
    if(this->length > this->maxSize - 1) {
        cout << "ERROR: OUT OF LENGTH" << endl;
    } else {
        this->elem[this->length++] = x;
        operation_number++;
    }
}

template <class T>
T RanQueue<T>::pop() {
    if(this->length <= 0) {
        cout << "ERROR: EMPTY QUEUE" << endl;
        return NULL;
    } else {
        operation_number++;
        return this->elem[--this->length];
    }
}

template <class T>
void RanQueue<T>::display() {
    cout << "LENGTH = " << this->length << endl;
    for(int i = 0; i < this->length; i++) {
        cout << this->elem[i] << " " ;
    }
    cout << "\nOUTPUT FROM RANQUEUE CLASS" << endl;
}


#endif // _RANQUEUE_H
