//
// Created by hqnddw on 2019/10/9.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> re;
        if (matrix.empty()) return re;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        int p = 0;
        vector<int> res(m * n);
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res[p++] = matrix[up][i];
            }

            if (++up > down) break;

            for (int j = up; j <= down; ++j) {
                res[p++] = matrix[j][right];
            }

            if (--right < left) break;

            for (int k = right; k >= left; k--) {
                res[p++] = matrix[down][k];
            }

            if (--down < up) break;
            for (int l = down; l >= up; l--) {
                res[p++] = matrix[l][left];
            }

            if (++left > right) break;
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<vector<int>> dir = {{0,  1},
                                   {1,  0},
                                   {0,  -1},
                                   {-1, 0}};
        vector<int> res;
        int nr = matrix.size();
        if (nr == 0) return res;
        int nc = matrix[0].size();
        if (nc == 0) return res;

        vector<int> nSteps{nc, nr - 1};

        int iDir = 0;
        int ir = 0, ic = -1;
        while (nSteps[iDir % 2]) {
            for (int i = 0; i < nSteps[iDir % 2]; ++i) {
                ir += dir[iDir][0];
                ic += dir[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir % 2]--;
            iDir = (iDir + 1) % 4;
        }
        return res;
    }
};


class Solution3 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int up = 0, down = matrix.size() - 1;
        vector<int> res;
        if (matrix.empty())
            return res;
        int left = 0, right = matrix[0].size() - 1;
        while (left <= right && up <= down) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;
            for (int j = up; j <= down; ++j) {
                res.push_back(matrix[j][right]);
            }
            if (--right < left) break;
            for (int k = right; k >= left; k--) {
                res.push_back(matrix[down][k]);
            }
            if (--down < up) break;
            for (int l = down; l >= up; l--) {
                res.push_back(matrix[l][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};


class Solution4 {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) break;

            for (int j = up; j <= down; ++j) {
                res.push_back(matrix[j][right]);
            }
            if (--right < left) break;
            for (int k = right; k >= left; --k) {
                res.push_back(matrix[down][k]);
            }
            if (--down < up) break;
            for (int l = down; l >= up; --l) {
                res.push_back(matrix[l][left]);
            }
            if (++left > right) break;
        }
        return res;
    }
};