//
// Created by hqnddw on 2019/10/10.
//

#include <vector>

using namespace std;

class Solution {
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