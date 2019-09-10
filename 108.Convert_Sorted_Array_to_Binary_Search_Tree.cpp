//
// Created by hqnddw on 2019/9/2.
//
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        return buildBST(nums, nums.begin(), nums.end());
    }

    TreeNode *buildBST(vector<int> nums, vector<int>::const_iterator start,
                       vector<int>::const_iterator end) {
        if (start >= end) return nullptr;
        auto mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = buildBST(nums, start, mid);
        root->right = buildBST(nums, mid + 1, end);
        return root;
    }
};


//记得对数组引用，会加快程序运行速度
class Solution2 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        return divide(nums, 0, nums.size());
    }

    TreeNode *divide(vector<int> &nums, int start, int end) {
        if (start >= end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = divide(nums, start, mid);
        root->right = divide(nums, mid + 1, end);
        return root;
    }
};


class Solution3 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode *buildTree(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }
};