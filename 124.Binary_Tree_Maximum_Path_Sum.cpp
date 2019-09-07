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

class Solution {
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
