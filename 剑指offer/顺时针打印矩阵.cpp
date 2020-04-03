//
// Created by hqnddw on 2019/10/20.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<int> printMatrix(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;

            for (int j = up; j <= down; ++j) {
                res.push_back(matrix[j][right]);
            }
            if (--right < left) break;
            for (int k = right; k >= left; --k) {
                res.push_back(matrix[down][k]);
            }
            if (--down < up) break;
            for (int l = down; l >= up; --l) {
                res.push_back(matrix[l][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;
            for (int j = up; j <= down; ++j) {
                res.push_back(matrix[j][right]);
            }
            if (--right < left) break;
            for (int k = right; k >= left; --k) {
                res.push_back(matrix[down][k]);
            }
            if (--down < up) break;
            for (int l = down; l >= up; --l) {
                res.push_back(matrix[l][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};