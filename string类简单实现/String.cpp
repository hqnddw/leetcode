#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

//
// Created by lwl on 2020/8/17.
//
#include <utility>
#include <string.h>

class String {
public:
    String(): data_(new char[1]) {
        *data_ = '\0';
        cout << "构造" << endl;
    }

    String(const char *str)
            : data_(new char[strlen(str) + 1]) {
        strcpy(data_, str);
        cout << "构造" << endl;
    }

    String(const String &rhs)
            : data_(new char[rhs.size() + 1]) {
        strcpy(data_, rhs.c_str());
        cout << "拷贝构造" << endl;
    }

    /* Delegate constructor in C++11
    String(const String& rhs)
      : String(rhs.data_)
    {
    }
    */

    ~String() {
        delete[] data_;
    }

    /* Traditional:
    String& operator=(const String& rhs)
    {
      String tmp(rhs);
      swap(tmp);
      return *this;
    }
    */
    String &operator=(String rhs) // yes, pass-by-value
    {
        swap(rhs);
        cout << "拷贝赋值" << endl;
        return *this;
    }

    // C++ 11
    String(String &&rhs)
            : data_(rhs.data_) {
        rhs.data_ = nullptr;
        cout << "移动构造" << endl;
    }

    String &operator=(String &&rhs) {
        swap(rhs);
        cout << "移动赋值" << endl;
        return *this;
    }

    // Accessors

    size_t size() const {
        return strlen(data_);
    }

    const char *c_str() const {
        return data_;
    }

    void swap(String &rhs) {
        std::swap(data_, rhs.data_);
    }

private:
    char *data_;
};


void foo(String x) {
}

void bar(const String &x) {
}

String baz() {
    String ret("world");
    return ret;
}

int main() {
    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s0;
    s2 = s0;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    String s4 = baz();

    std::vector<String> svec;
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(baz());
    svec.push_back("good job");
}