//
// Created by hqnddw on 2019/10/19.
//
#include <vector>

using namespace std;

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            if (helper(matrix[i], target)) return true;
        }
        return false;
    }

    bool helper(vector<int> &nums, int target) {
        int hi = nums.size() - 1;
        int lo = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] > target)
                hi = mid - 1;
            else if (nums[mid] < target)
                lo = mid + 1;
            else return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        int row = 0, col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            matrix[row][col] > target ? col-- : row++;
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
        int left = 0, right = n - 1;
        while (left < m && right >= 0) {
            int root = matrix[left][right];
            if (root == target)
                return true;
            else if (root > target)
                right--;
            else left++;
        }
        return false;
    }
};


class Solution4 {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) return false;
        int up = 0;
        int right = matrix[0].size() - 1;
        while (up <= matrix.size() - 1 && right >= 0) {
            if (matrix[up][right] == target)
                return true;
            else if (matrix[up][right] > target)
                right--;
            else up++;
        }
        return false;
    }
};