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

class Solution {
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
