//
// Created by hqnddw on 2020/6/2.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode *root, int sum) {
        if (!root) return 0;
        return (root->val == sum ? 1 : 0) +
               helper(root->left, sum - root->val) +
               helper(root->right, sum - root->val);
    }
};