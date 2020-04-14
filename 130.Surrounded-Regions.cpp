//
// Created by hqnddw on 2020/4/11.
//
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) return;
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for (int i = 0; i < col; ++i) {
            if (board[0][i] == 'O')
                check(0, i, board, visited);
            if (board[row - 1][i] == 'O')
                check(row - 1, i, board, visited);
        }
        for (int j = 1; j < row - 1; ++j) {
            if (board[j][0] == 'O')
                check(j, 0, board, visited);
            if (board[j][col - 1] == 'O')
                check(j, col - 1, board, visited);
        }
        for (int k = 0; k < row; ++k) {
            for (int i = 0; i < col; ++i) {
                if (!visited[k][i])
                    board[k][i] = 'X';
            }
        }
    }

    void check(int row, int col, vector<vector<char>> &board, vector<vector<bool>> &visited) {
        if (row < 0 || row == board.size() || col < 0 || col == board[0].size())
            return;
        if (visited[row][col])
            return;
        if (board[row][col] == 'O') {
            visited[row][col] = true;
            check(row, col - 1, board, visited);
            check(row, col + 1, board, visited);
            check(row - 1, col, board, visited);
            check(row + 1, col, board, visited);
        }
    }
};