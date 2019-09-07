//
// Created by hqnddw on 2019/9/6.
//

#include <vector>
#include <stack>
#include <queue>

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


class Solution {
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