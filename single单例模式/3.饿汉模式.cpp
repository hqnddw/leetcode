//
// Created by lwl on 2020/8/5.
//

#include <iostream>

class single {
private:
    static single *p;

    single() {}

    ~single() {}

public:
    static single *getInstance(){
        return p;
    }

    static single* destroy(){
        delete p;
        p = nullptr;
    }
};
single* single::p = new single();

int main() {
    single *s1 = single::getInstance();
    single *s2 = single::getInstance();
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}