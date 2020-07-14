//
// Created by lwl on 2020/7/9.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, res);
        return res;
    }

    void dfs(vector<string> &board, int row, vector<vector<string>> &res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board[0].size(); ++col) {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            dfs(board, row + 1, res);
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string> &board, int row, int col) {
        for (int i = 0; i < board.size() && i != row; ++i) {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[0].size();
             --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};