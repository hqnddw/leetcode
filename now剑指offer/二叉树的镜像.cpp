//
// Created by hqnddw on 2019/10/20.
//
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution1 {
public:
    void Mirror(TreeNode *root) {
        if (!root) return;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        Mirror(root->left);
        Mirror(root->right);
    }
};

class Solution2 {
public:
    void Mirror(TreeNode *pRoot) {
        if (pRoot) {
            swap(pRoot->left, pRoot->right);
            Mirror(pRoot->left);
            Mirror(pRoot->right);
        }
    }
};


class Solution3 {
public:
    void Mirror(TreeNode *root) {
        stack<TreeNode *> s;
        if (!root)return;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root->left || root->right)
                swap(root->left, root->right);
            if (root->left) s.push(root->left);
            if (root->right) s.push(root->right);
        }
    }
};