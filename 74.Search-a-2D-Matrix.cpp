//
// Created by hqnddw on 2019/10/19.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (matrix[mid / n][mid % n] > target)
                hi = mid - 1;
            else if (matrix[mid / n][mid % n] < target)
                lo = mid + 1;
            else return true;
        }
        return false;
    }
};


class Solution3 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};


class Solution4 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0;
        int hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};