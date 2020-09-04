//
// Created by lwl on 2020/8/5.
//

#include <iostream>

class single {
private:
    single() {}

    ~single() {}

public:
    static single *getInstance(){
        static single obj;
        return &obj;
    }
};


int main(){
    single *s1 = single::getInstance();
    single *s2 = single::getInstance();
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}