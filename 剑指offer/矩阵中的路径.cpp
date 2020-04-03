#include <cstring>

//
// Created by hqnddw on 2019/11/11.
//
class Solution {
public:
    bool hasPath(char *matrix, int rows, int cols, char *str) {
        if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
            return false;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int length = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (helper(matrix, rows, cols, i, j, str, length, visited))
                    return true;
            }
        }
        delete[] visited;
        return false;
    }

    bool helper(char *matrix, int rows, int cols, int row, int col, char *str, int length, bool *visited) {
        if (str[length] == '\0')
            return true;
        bool hasPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols
            && matrix[row * cols + col] == str[length] && !visited[row * cols + col]) {
            ++length;
            visited[row * cols + col] = true;

            hasPath = helper(matrix, rows, cols, row + 1, col, str, length, visited)
                      || helper(matrix, rows, cols, row - 1, col, str, length, visited)
                      || helper(matrix, rows, cols, row, col - 1, str, length, visited)
                      || helper(matrix, rows, cols, row, col + 1, str, length, visited);
            if (!hasPath) {
                --length;
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }
};
