//
// Created by hqnddw on 2019/6/26.

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;


// reverse algorithm example
#include <iostream>
// std::cout
#include <algorithm>
// std::reverse
#include <vector>
// std::vector

int main() {
    std::vector<int> myvector;
    // set some values:
    for (int i = 1; i < 10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
    std::reverse(myvector.begin(), myvector.end());    // 9 8 7 6 5 4 3 2 1
    // print out content:
    std::cout << "myvector contains:";
    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}
