//
// Created by hqnddw on 2020/4/30.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int s = 0;
        helper(root, s);
        return s;
    }

    int helper(TreeNode *root, int s) {
        if (!root) return 0;
        if (!root->left && !root->right) return s * 10 + root->val;
        return helper(root->left, s * 10 + root->val) +
               helper(root->right, s * 10 + root->val);
    }
};