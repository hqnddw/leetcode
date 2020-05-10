//
// Created by hqnddw on 2020/5/9.
//
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//暴力解法（不管树是不是完全二叉树）
class Solution1 {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution2 {
public:
    int countNodes(TreeNode *root) {
        if (!root) return 0;
        TreeNode *left = root;
        TreeNode *right = root;
        int l = 0, r = 0;
        while (left) {
            l++;
            left = left->left;
        }
        while (right) {
            r++;
            right = right->right;
        }
        if (l == r)
            return (1 << l) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;
        int h = height(root);
        int r = height(root->right);
        if (r == h - 1) {
            return (1 << r) + countNodes(root->right);
        } else {
            return (1 << r) + countNodes(root->left);
        }
    }

    int height(TreeNode *root) {
        if (!root) return 0;
        return 1 + height(root->left);
    }
};