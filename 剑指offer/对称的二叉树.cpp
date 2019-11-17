//
// Created by hqnddw on 2019/11/14.
//
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode *pRoot) {
        if (!pRoot) return nullptr;
        return helper(pRoot, pRoot);
    }

    bool helper(TreeNode *root1, TreeNode *root2) {
        if (!root1 || !root2) return root1 == root2;
        return (root1->val == root2->val) && helper(root1->left, root2->right)
               && helper(root1->right, root2->left);
    }

};