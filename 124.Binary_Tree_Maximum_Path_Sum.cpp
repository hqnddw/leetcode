#include <climits>
#include <algorithm>

//
// Created by hqnddw on 2019/9/6.
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int max_sum = INT_MIN;

    int maxPathSum(TreeNode *root) {
        helper(root);
        return max_sum;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        max_sum = max(max_sum, left + right + root->val);
        return max(left, right) + root->val;
    }
};


class Solution2 {
public:
    int maxvalue = INT_MIN;

    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxvalue;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        maxvalue = max(maxvalue, root->val + right + left);
        return root->val + max(right, left);
    }
};


class Solution3 {
public:
    int maxvalue = INT_MIN;

    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        helper(root);
        return maxvalue;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        maxvalue = max(maxvalue, root->val + left + right);
        return root->val + max(left, right);
    }
};


class Solution4 {
public:
    int maxValue = INT_MIN;

    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxValue;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        maxValue = max(maxValue, right + left + root->val);
        return root->val + max(left, right);
    }
};

class Solution5 {
public:
    int maxValue = INT_MIN;

    int maxPathSum(TreeNode *root) {
        helper(root);
        return maxValue;
    }

    int helper(TreeNode *root) {
        if (!root)
            return 0;
        int left = max(helper(root->left), 0);
        int right = max(helper(root->right), 0);
        maxValue = max(root->val + left + right, maxValue);
        return root->val + max(left, right);
    }
};