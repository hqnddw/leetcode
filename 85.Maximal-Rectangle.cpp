//
// Created by hqnddw on 2020/4/29.
//
#include <vector>
#include <stack>

using namespace std;

//使用栈
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> height(n + 1, 0);
        int h = 0, w = 0, res = 0;
        for (int i = 0; i < m; ++i) {
            stack<int> s;
            for (int j = 0; j <= n; ++j) {
                if (j < n && matrix[i][j] == '1')
                    height[j] += 1;
                else height[j] = 0;

                while (!s.empty() && height[s.top()] > height[j]) {
                    h = height[s.top()];
                    s.pop();
                    w = s.empty() ? j : j - s.top() - 1;
                    if (w * h > res) res = w * h;
                }
                s.push(j);
            }
        }
        return res;
    }
};