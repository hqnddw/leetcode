//
// Created by yida on 2020/5/24.
//
#include <vector>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;

//暴力
class Solution1 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        vector<vector<int>> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        res.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    int tmp = INT_MAX;
                    for (int k = 0; k < m; ++k) {
                        for (int l = 0; l < n; ++l) {
                            if (matrix[k][l] == 0)
                                tmp = min(tmp, abs(k - i) + abs(j - l));
                        }
                    }
                    res[i][j] = tmp;
                }
            }
        }
        return res;
    }
};

//bfs
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) return matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dir[4][2] = {{-1, 0},
                         {1,  0},
                         {0,  -1},
                         {0,  1}};
        while (!q.empty()) {
            int curRow = q.front().first;
            int curCol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int row = curRow + dir[i][0];
                int col = curCol + dir[i][1];
                if (row < 0 || row == m || col < 0 || col == n
                    || res[row][col] <= res[curRow][curCol] + 1)
                    continue;
                res[row][col] = res[curRow][curCol] + 1;
                q.push({row, col});
            }
        }
        return res;
    }
};