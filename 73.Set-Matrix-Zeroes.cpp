//
// Created by hqnddw on 2019/10/28.
//
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> v(m, vector<int>(n, 1));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; ++k) {
                        v[i][k] = 0;
                    }
                    for (int l = 0; l < m; ++l) {
                        v[l][j] = 0;
                    }
                }
            }
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[0].size(); ++j) {
                if (v[i][j] == 1)
                    v[i][j] = matrix[i][j];
            }
        }
        matrix = v;
    }
};


class Solution2 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        unordered_set<int> row;
        unordered_set<int> col;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int k = 0; k < matrix.size(); ++k) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                if (row.count(k) || col.count(i))
                    matrix[k][i] = 0;
            }
        }
    }
};


class Solution3 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        bool isCol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)
                isCol = true;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int k = 1; k < m; ++k) {
            for (int j = 1; j < n; ++j) {
                if (matrix[k][0] == 0 || matrix[0][j] == 0)
                    matrix[k][j] = 0;
            }
        }
        if (matrix[0][0]) {
            for (int i = 0; i < n; ++i) {
                matrix[0][n] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};


class Solution4 {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        bool isCol = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0)
                isCol = true;
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};