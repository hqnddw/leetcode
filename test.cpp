//
// Created by hqnddw on 2019/6/26.

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main() {
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
              << "\", \"" << v[1] << "\"\n";
    vector<int> v1;
    vector<int> v2;
    if (v1 == v2) {

    }
}