//
// Created by hqnddw on 2019/9/12.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>> &board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solve(board, row + 1, 0);
        if (board[row][col] != '.') return solve(board, row, col + 1);
        for (int i = '1'; i <= '9'; ++i) {
            if (valid(board, row, col, i)) {
                board[row][col] = i;
                if (solve(board, row, col + 1))
                    return true;
                else board[row][col] = '.';
            }
        }
        return false;
    }

    bool valid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};


class Solution2 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>> &board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solve(board, row + 1, 0);
        if (board[row][col] != '.') return solve(board, row, col + 1);
        for (int i = '1'; i <= '9'; ++i) {
            if (valid(board, row, col, i)) {
                board[row][col] = i;
                if (solve(board, row, col + 1))
                    return true;
                else board[row][col] = '.';
            }

        }
        return false;
    }

    bool valid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) return false;
            if (board[row][i] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }
};


class Solution3 {
public:
    void solveSudoku(vector<vector<char>> &board) {
        solve(board, 0, 0);
    }

    bool solve(vector<vector<char>> &board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solve(board, row + 1, 0);
        if (board[row][col] != '.') return solve(board, row, col + 1);
        for (int i = '1'; i <= '9'; ++i) {
            if (valid(board, row, col, i)) {
                board[row][col] = i;
                if (solve(board, row, col + 1))
                    return true;
                else board[row][col] = '.';
            }
        }
        return false;
    }

    bool valid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == c) return false;
            if (board[i][col] == c) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};