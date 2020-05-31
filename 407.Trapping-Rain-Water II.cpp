//
// Created by yida on 2020/5/29.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        int res = 0;
        class cell {
        public:
            int row;
            int col;
            int height;

            cell(int row, int col, int height) {
                this->row = row;
                this->col = col;
                this->height = height;
            }
        };
        struct compare {
            bool operator()(cell a, cell b) {
                return a.height > b.height;
            }
        };
        priority_queue<cell, vector<cell>, compare> pq;
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            visited[i][0] = true;
            visited[i][n - 1] = true;
            pq.push(cell(i, 0, heightMap[i][0]));
            pq.push(cell(i, n - 1, heightMap[i][n - 1]));
        }
        for (int j = 1; j < n - 2; ++j) {
            visited[0][j] = true;
            visited[m - 1][j] = true;
            pq.push(cell(0, j, heightMap[0][j]));
            pq.push(cell(m - 1, j, heightMap[m - 1][j]));
        }
        int dirs[4][4] = {{-1, 0},
                          {1,  0},
                          {0,  -1},
                          {0,  1}};
        while (!pq.empty()) {
            cell c = pq.top();
            pq.pop();
            for (auto v:dirs) {
                int row = c.row + v[0];
                int col = c.col + v[1];
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = true;
                    res += max(0, c.height - heightMap[row][col]);
                    pq.push(cell(row, col, max(c.height, heightMap[row][col])));
                }
            }
        }
        return res;
    }
};