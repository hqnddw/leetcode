//
// Created by hqnddw on 2020/5/2.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int> &A) {
        if (A.size() < 3) return false;
        int i = 1;
        int j = A.size();
        while (i < j && A[i] > A[i - 1])
            i++;
        if (i == 1 || i == j) return false;
        while (i < j && A[i - 1] > A[i])
            i++;
        return i == j;
    }
};