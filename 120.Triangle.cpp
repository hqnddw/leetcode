//
// Created by hqnddw on 2020/5/7.
//
#include <vector>

using namespace std;

//O(m*n)
class Solution1 {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<vector<int>> res(triangle.begin(), triangle.end());
        int m = triangle.size();
        for (int i = m - 2; i >= 0; --i) {
            for (int j = 0; j < i + 1; ++j) {
                res[i][j] = min(res[i + 1][j], res[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return res[0][0];
    }
};

//O(m)
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i) {
            res[i] = triangle[m - 1][i];
        }
        for (int j = m - 2; j >= 0; --j) {
            for (int i = 0; i <= j; ++i) {
                res[i] = min(res[i], res[i + 1]) + triangle[j][i];
            }
        }
        return res[0];
    }
};

