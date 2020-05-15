//
// Created by hqnddw on 2019/8/21.
//
#include <vector>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        inorder(root, v);
        return v;
    }

    void inorder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
};

//迭代
class Solution2 {
public:
    void goleft(TreeNode *x, stack<TreeNode *> &s) {
        while (x) {
            s.push(x);
            x = x->left;
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        while (true) {
            goleft(root, s);
            if (s.empty()) break;
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};

//莫里斯遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode *pre = root->left;
                while (pre->right && pre->right != root)
                    pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    res.push_back(root->val);
                    root = root->right;
                }
            } else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};