//
// Created by lwl on 2020/8/7.
//
#include <iostream>

using namespace std;

template<typename T>
class smartPointer;


template<typename T>
class Ptr {
private:
    T *p;
    int count;

    friend class smartPointer<T>;

    Ptr(T *ptr) : p(ptr), count(1) {}

    ~Ptr() {
        delete p;
    }
};

template<typename T>
class smartPointer {
private:
    Ptr<T> *ptr;
public:
    smartPointer(T *t) : ptr(new Ptr<T>(t)) {};

    smartPointer(const smartPointer<T> &s) : ptr(s.ptr) {
        ptr->count++;
    }

    smartPointer &operator=(const smartPointer<T> &s) {
        --ptr->count;
        if (ptr->count == 0) {
            delete ptr;
        }
        ++s.ptr->count;
        ptr = s.ptr;
        return *this;
    }

    ~smartPointer() {
        --ptr->count;
        if (ptr->count == 0) {
            delete ptr;
        } else {
            cout << "还有" << ptr->count << "个指针指向基础对象" << endl;
        }
    }
    T* operator->(){
        return ptr->p;
    }
    T& operator*(){
        return *ptr->p;
    }
};