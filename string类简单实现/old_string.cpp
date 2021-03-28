//
// Created by hqnddw on 2020/9/20.
//
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
class String {
public:
    //构造函数
    String() : data(new char[1]) {
        *data = '\0';
        cout << "构造" << endl;
    }

    String(const char *str) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
        cout << "构造" << endl;
    }

    //拷贝构造函数
    String(const String &str) {
        data = new char[strlen(str.data) + 1];
        strcpy(data, str.data);
        cout << "拷贝构造" << endl;
    }

    //移动构造函数
    String(String &&str) : data(str.data) {
        str.data = nullptr;
        cout << "移动构造" << endl;
    }

    // 拷贝赋值函数 =号重载
    String &operator=(const String &str) {
        if (this == &str) // 避免自我赋值
            return *this;
        delete data;
        data = new char[strlen(str.data) + 1];
        strcpy(data, str.data);
        cout << "拷贝赋值" << endl;
        return *this;
    }

    // 移动赋值函数 =号重载
    String &operator=(String &&str) {
        if (this == &str) // 避免自我赋值
            return *this;
        delete data;
        data = str.data;
        str.data = nullptr;
        cout << "移动赋值" << endl;
        return *this;
    }

    ~String() {
        delete data;
    }

    char *c_str() const {
        return data;
    }

private:
    char *data;
};


int main() {
    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s0;
    s2 = s0;

//    foo(s1);
//    bar(s1);
//    foo("temporary");
//    bar("temporary");
//    String s4 = baz();
//
    std::vector<String> svec;
    svec.push_back(s0);
    svec.push_back("good job");
}