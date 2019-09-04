//
// Created by hqnddw on 2019/9/1.
//
#include <stack>

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
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = nullptr;

    void recoverTree(TreeNode *root) {
        if (!root)
            return;
        inOrder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }

    void inOrder(TreeNode *root) {
        if (!root) return;
        inOrder(root->left);
        if (pre && pre->val >= root->val) {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inOrder(root->right);
    }
};

//迭代
class Solution2 {
public:
    void recoverTree(TreeNode *root) {
        if (!root)
            return;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (prev && prev->val >= root->val) {
                if (!first) first = prev;
                second = root;
            }
            prev = root;
            root = root->right;
        }
        swap(first->val, second->val);
    }
};


class Solution3 {
public:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = nullptr;

    void recoverTree(TreeNode *root) {
        if (!root)
            return;
        inOrder(root);
        swap(first->val, second->val);
    }

    void inOrder(TreeNode *&root) {
        stack<TreeNode *> s;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (pre && pre->val >= root->val) {
                if (!first) first = pre;
                second = root;
            }
            pre = root;
            root = root->right;
        }
    }
};









class Solution {
public:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *pre = nullptr;
    void recoverTree(TreeNode* root) {
        inOrder(root);
        swap(first->val, second->val);
    }
    void inOrder(TreeNode *root){
        if (!root) return;
        inOrder(root->left);
        if (pre && pre->val >= root->val){
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inOrder(root->right);
    }
};