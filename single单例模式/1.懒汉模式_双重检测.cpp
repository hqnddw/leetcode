//
// Created by lwl on 2020/8/5.
//
#include <mutex>
#include <iostream>

class single {
private:
    static single *p;
    static std::mutex mutex_t;

    single() {}


public:
    static single *getInstance() {
        if (p == nullptr) {
            std::lock_guard<std::mutex> lock(mutex_t);
            if (p == nullptr) {
                p = new single;
            }
        }
        return p;
    }
    ~single(){
        delete p;
        p = nullptr;
    }
};

single *single::p = nullptr;
std::mutex single::mutex_t;

int main() {
    single *s1 = single::getInstance();
    single *s2 = single::getInstance();
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
}