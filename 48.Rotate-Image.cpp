//
// Created by hqnddw on 2019/10/8.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:
    void rotate(vector<vector<int>> &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};


class Solution3 {
public:
    void rotate(vector<vector<int>> &matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


class Solution4 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};


class Solution5 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2 - 1; ++j) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};


class Solution6 {
public:
    void rotate(vector<vector<int>> &matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int k = 0; k < matrix.size(); ++k) {
            for (int i = 0; i < matrix[i].size() / 2; ++i) {
                swap(matrix[k][i], matrix[k][matrix[i].size() - 1 - i]);
            }
        }
    }
};


class Solution7 {
public:
    void rotate(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};