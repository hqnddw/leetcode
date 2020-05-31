//
// Created by yida on 2020/5/29.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *pruneTree(TreeNode *root) {
        if (!root) return root;
        root->left =  pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
            return nullptr;
        return root ;
    }
};