//
// Created by hqnddw on 2020/5/4.
//
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int s, n;
        vector<int> res;
        while (num) {
            res.push_back(num % 2);
            num /= 2;
        }
        n = res.size();
        for (int i = n - 1; i >= 0; --i) {
            if (res[i] == 0)
                s += pow(2, i);
        }
        return s;
    }
};