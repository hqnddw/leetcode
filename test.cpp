//
// Created by hqnddw on 2019/9/19.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    vector<vector<int>> res;
    res.push_back({1, 1, 2});
    res.push_back({1, 1, 2});
    cout << res.size() << endl;
    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << endl;
}