#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class A {
public:
    int n1;
    int n2;

    A() : n2(1), n1(n2 + 2) {}
};

int main() {
    A a;
    cout << a.n1 << endl;
    cout << a.n2 << endl;
}