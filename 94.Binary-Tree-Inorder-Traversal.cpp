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
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        TreeNode *cur = root;
        TreeNode *pre;
        while (cur) {
            if (!cur->left) {
                v.push_back(cur->val);
                cur = cur->right; //移动到下一个右节点
            } else {
                pre = cur->left;
                while (pre->right) { //发现最右边的节点
                    pre = pre->right;
                }
                pre->right = cur; //把cur接到pre的右节点上
                TreeNode *temp = cur; //储存cur
                cur = cur->left; // move cur to the top of the new tree
                temp->left = nullptr; // original cur left be null, avoid infinite loops
            }
        }
        return v;
    }
};

//第二次
class Solution4 {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty()) break;
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right;
        }
        return v;
    }
};


//第二次
class Solution {
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