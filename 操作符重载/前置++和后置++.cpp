//
// Created by hqnddw on 2020/9/6.
//
#include <iostream>

using namespace std;

/**
 * 从上述代码，我们可以看出前置++和后置++，有3点不同：
 *      1. 返回类型不同
 *      2. 形参不同
 *      3. 代码不同
 *      4. 效率不同
 * */

class Age {

public:
    int age;

    Age &operator++() {
        ++age;
        return *this;
    }

    const Age operator++(int) {
        Age tmp = *this;
        ++(*this);
        return tmp;
    }
};

int main() {
    Age a;
    cout << a.age << endl;
}