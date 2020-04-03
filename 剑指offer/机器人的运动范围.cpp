//
// Created by hqnddw on 2019/11/12.
//
class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0 || rows <= 0 || cols <= 0)
            return 0;
        bool *visited = new bool[rows * cols];
        for (int i = 0; i < rows * cols; ++i) {
            visited[i] = false;
        }
        int count = move(threshold, rows, cols, 0, 0, visited);
        delete[] visited;
        return count;
    }

    int move(int threshold, int rows, int cols, int row, int col, bool *visited) {
        int count = 0;
        if (helper(threshold, rows, cols, row, col, visited)) {
            visited[row * cols + col] = true;
            count = 1 + move(threshold, rows, cols, row + 1, col, visited)
                    + move(threshold, rows, cols, row - 1, col, visited)
                    + move(threshold, rows, cols, row, col + 1, visited)
                    + move(threshold, rows, cols, row, col - 1, visited);
        }
        return count;
    }

    bool helper(int threshold, int rows, int cols, int i, int j, bool *visited) {

        return i >= 0 && i < rows && j >= 0 && j < cols
               && getSum(i) + getSum(j) <= threshold
               && !visited[i * cols + j];
    }

    int getSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
};
