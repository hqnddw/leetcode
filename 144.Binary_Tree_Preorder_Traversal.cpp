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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        preOrder(root, v);
        return v;
    }

    void preOrder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
};

//迭代
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if (!root)
            return v;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};


//第二次
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        preOrder(root, v);
        return v;
    }

    void preOrder(TreeNode *root, vector<int> &v) {
        if (!root) return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
};

class Solution4 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        if (!root) return v;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};


class Solution5 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if (!root) return v;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};


class Solution6 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        if (!root) return v;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            v.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return v;
    }
};



