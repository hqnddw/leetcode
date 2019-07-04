//
// Created by hqnddw on 2019/7/3.
//
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }

    void bfs(vector<vector<char>> &grid, int x, int y) {
        grid[x][y] = '0';
        queue<pair<int, int >> q;
        q.push({x, y});
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (x > 0 && grid[x - 1][y] == '1') {
                q.push({x - 1, y});
                grid[x - 1][y] = '0';
            }
            if (x < grid.size() - 1 && grid[x + 1][y] == '1') {
                q.push({x + 1, y});
                grid[x + 1][y] = '0';
            }
            if (y > 0 && grid[x][y - 1] == '1') {
                q.push({x, y - 1});
                grid[x][y - 1] = '0';
            }
            if (y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
                q.push({x, y + 1});
                grid[x][y + 1] = '0';
            }
        }
    }
};