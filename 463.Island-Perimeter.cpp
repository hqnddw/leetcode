//
// Created by yida on 2020/5/17.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == 1){
                    if (i == 0 || grid[i-1][j] == 0) res++;
                    if (i == row - 1 || grid[i+1][j] == 0) res++;
                    if (j == 0 || grid[i][j-1] == 0) res++;
                    if (j == col -1 || grid[i][j+1] == 0) res++;
                }
            }
        }
        return res;
    }
};