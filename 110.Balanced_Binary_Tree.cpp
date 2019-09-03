//
// Created by hqnddw on 2019/9/3.
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
    bool isBalanced(TreeNode *root) {
        int max = max_depth(root);
        int min = min_depth(root);
    }

    int max_depth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(max_depth(root->left), max_depth(root->right));
    }

    int min_depth(TreeNode *root) {
        if (!root) return 0;
        return 1 + min(min_depth(root->left), min_depth(root->right));
    }
};