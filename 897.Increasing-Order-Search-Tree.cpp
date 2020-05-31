//
// Created by yida on 2020/5/22.
//
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *cur;

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *dummy = new TreeNode(-1);
        cur = dummy;
        inorder(root);
        return dummy->right;
    }
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        root->left = nullptr;
        cur->right = root;
        cur = cur->right;
        inorder(root->right);
    }
};