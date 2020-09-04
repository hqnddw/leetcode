#include <cstring>

//
// Created by lwl on 2020/8/17.
//
class myString {
public:
    //构造函数
    myString(const char *str) {
        if (str) {
            data = new char[strlen(str) + 1];
            strcpy(data, str);
        } else {
            data = new char[1];
            *data = '\0';
        }
    }

    //拷贝构造函数
    myString(const myString &str) {
        data = new char[strlen(str.data) + 1];
        strcpy(data, str.data);
    }

    //移动构造函数
    myString(myString&& str):data(str.data){
        str.data = nullptr;
        return;
    }

    // 拷贝赋值函数 =号重载
    myString &operator=(const myString &str) {
        if (this == &str) // 避免自我赋值
            return *this;
        delete data;
        data = new char[strlen(str.data) + 1];
        strcpy(data, str.data);
        return *this;
    }

    // 移动赋值函数 =号重载
    myString& operator=(myString&& str){
        if (this == &str) // 避免自我赋值
            return *this;
        delete data;
        data = str.data;
        str.data = nullptr;
        return *this;
    }
    ~myString(){
        delete data;
    }

    char *c_str() const{
        return data;
    }

private:
    char *data;
};
