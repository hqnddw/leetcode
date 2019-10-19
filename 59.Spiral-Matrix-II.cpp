//
// Created by hqnddw on 2019/10/10.
//

#include <vector>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int i = 0, k = 1;
        while (k <= n * n) {
            int j = i;
            while (j < n - i)
                res[i][j++] = k++;

            j = i + 1;
            while (j < n - i)
                res[j++][n - i - 1] = k++;

            j = n - 2 - i;
            while (j > i)
                res[n - 1 - i][j--] = k++;

            j = n - i - 1;
            while (j > i)
                res[j--][i] = k++;

            i++;
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        int p = 0;
        vector<vector<int>> res(n, vector<int>(n));
        int up = 0;
        int left = 0;
        int down = n - 1;
        int right = n - 1;
        while (up <= down && left <= right) {
            for (int i = left; i <= right; ++i) {
                res[up][i] = ++p;
            }
            if (++up > down) break;
            for (int j = up; j <= down; ++j) {
                res[j][right] = ++p;
            }
            if (--right < left) break;
            for (int k = right; k >= left; k--) {
                res[down][k] = ++p;
            }
            if (--down < up) break;
            for (int l = down; l >= up; l--) {
                res[l][left] = ++p;
            }
            if (++left > right) break;
        }
        return res;
    }
};