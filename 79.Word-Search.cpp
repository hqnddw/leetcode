//
// Created by hqnddw on 2020/6/2.
//
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty()) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, visited, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &visited,
             string &word, int i, int j, int start) {
        if (start == word.size())
            return true;
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
            visited[i][j] || board[i][j] != word[start])
            return false;
        visited[i][j] = true;
        if (dfs(board, visited, word, i + 1, j, start + 1) ||
            dfs(board, visited, word, i - 1, j, start + 1) ||
            dfs(board, visited, word, i, j + 1, start + 1) ||
            dfs(board, visited, word, i, j - 1, start + 1))
            return true;
        visited[i][j] = false;
        return false;
    }
};