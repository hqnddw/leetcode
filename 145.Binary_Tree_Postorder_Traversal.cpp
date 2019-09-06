//
// Created by hqnddw on 2019/8/29.
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        postOrder(root, v);
        return v;
    }

    void postOrder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->val);
    }
};

//迭代
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        TreeNode *pre = nullptr;
        stack<TreeNode *> s;
        vector<int> v;
        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top(); //只查看栈顶节点，但不弹出
                if (root->right && root->right != pre) {
                    root = root->right;
                    s.push(root);
                    root = root->left;
                } else {
                    root = s.top();
                    s.pop();
                    v.push_back(root->val);
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return v;
    }
};


//第二次
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        postOrder(root, v);
        return v;
    }

    void postOrder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        postOrder(root->left, v);
        postOrder(root->right, v);
        v.push_back(root->val);
    }
};

class Solution4 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if (!root) return v;
        TreeNode *pre = nullptr;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                if (root->right && root->right != pre) {
                    root = root->right;
                    s.push(root);
                    root = root->left;
                } else {
                    s.pop();
                    v.push_back(root->val);
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return v;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        TreeNode *pre = nullptr;
        if (!root) return v;
        while (!s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                if (root->right && pre != root->right) {
                    root = root->right;
                    s.push(root);
                    root = root->left;
                } else {
                    s.pop();
                    v.push_back(root->val);
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return v;
    }
};