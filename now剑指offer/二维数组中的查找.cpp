//
// Created by hqnddw on 2019/10/20.
//
#include <vector>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            matrix[row][col] > target ? col-- : row++;
        }
        return false;
    }
};