//
// Created by hqnddw on 2020/4/11.
//
//
//#include <algorithm>
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
    int res = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        helper(root);
        return res;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};