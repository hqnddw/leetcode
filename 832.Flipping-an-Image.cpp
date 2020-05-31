//
// Created by yida on 2020/5/25.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        for (auto &v : A){
            reverse(v.begin(), v.end());
        }
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j])
                    A[i][j] = 0;
                else A[i][j] = 1;
            }
        }
        return A;
    }
};