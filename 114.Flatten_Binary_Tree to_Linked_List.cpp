//
// Created by hqnddw on 2019/9/6.
//

#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//递归
class Solution1 {
public:
    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};


class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right)
                    pre = pre->right;

                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};


class Solution3 {
public:
    void flatten(TreeNode *root) {
        helper(root, nullptr);
    }

    TreeNode *helper(TreeNode *root, TreeNode *pre) {
        if (!root) return nullptr;
        pre = helper(root->right, pre);
        pre = helper(root->left, pre);
        root->right = pre;
        root->left = nullptr;
        pre = root;
        return pre;
    }
};

class Solution4 {
public:
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right)
                    pre = pre->right;

                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            } else root = root->right;
        }
    }
};


class Solution5 {
public:
    void flatten(TreeNode *root) {
        TreeNode *pre = nullptr;
        while (root) {
            if (root->left) {
                pre = root->left;
                while (pre->right)
                    pre = pre->right;

                pre->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    }
};


class Solution6 {
public:
    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {
        if (!root)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};


class Solution7 {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = nullptr;
        while (root) {
            if (root->left) {
                cur = root->left;
                while (cur->right)
                    cur = cur->right;

                cur->right = root->right;
                root->right = root->left;
                root->left = nullptr;

            }
            root = root->right;
        }
    }
};


class Solution {
public:
    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {
        if (!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
};