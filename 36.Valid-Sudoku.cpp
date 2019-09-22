//
// Created by hqnddw on 2019/9/17.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int cube[9][9] = {0};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || cube[k][num])
                        return false;
                    else
                        row[i][num] = col[j][num] = cube[k][num] = 1;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int cube[9][9] = {0};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = (i / 3) * 3 + j / 3;
                    if (row[i][num] || col[j][num] || cube[k][num])
                        return false;
                    row[i][num] = col[j][num] = cube[k][num] = 1;
                }
            }
        }
        return true;
    }
};