//
// Created by hqnddw on 2019/8/26.
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


//中序遍历迭代
class Solution1 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty()) break;
            root = s.top();
            s.pop();
            if (pre && pre->val > root->val) return false;
            pre = root;
            root = root->right;
        }
        return false;
    }
};

//中序遍历递归
class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = nullptr;
        return valid(root, pre);
    }

    bool valid(TreeNode *root, TreeNode *&pre) {
        if (!root) return true;
        if (!valid(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return valid(root->right, pre);
    }
};


//第二次
class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = nullptr;
        return valid(root, pre);
    }

    bool valid(TreeNode *root, TreeNode *&pre) {
        if (!root) return true;
        if (!valid(root, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return valid(root->right, pre);
    }
};

class Solution4 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (pre && pre->val >= root->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

//第三次
class Solution5 {
public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        if (!root) return true;
        while (true) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            if (s.empty()) break;
            root = s.top();
            s.pop();
            if (pre && pre->val >= root->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

class Solution6 {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = nullptr;
        return valid(root, pre);
    }

    bool valid(TreeNode *root, TreeNode *&pre) {
        if (!root) return true;
        if (!valid(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return valid(root->right, pre);
    }
};


class Solution8 {
public:
    bool isValidBST(TreeNode *root) {
        TreeNode *pre = nullptr;
        return inOrder(root, pre);
    }

    bool inOrder(TreeNode *root, TreeNode *pre) {
        if (!root) return false;
        if (!inOrder(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        return inOrder(root->right, pre);
    }
};


//BFS
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root || (!root->right && !root->left))
            return true;
        queue<TreeNode *> q;
        queue<TreeNode *> max;
        queue<TreeNode *> min;
        TreeNode *maxvalue = nullptr;
        TreeNode *minvalue = nullptr;
        q.push(root);
        max.push(maxvalue);
        min.push(minvalue);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            maxvalue = max.front();
            max.pop();
            minvalue = min.front();
            min.pop();
            if (maxvalue && root->val >= maxvalue->val)
                return false;
            if (minvalue && root->val <= minvalue->val)
                return false;
            if (root->left) {
                q.push(root->left);
                min.push(minvalue);
                max.push(root);
            }
            if (root->right) {
                q.push(root->right);
                min.push(root);
                max.push(maxvalue);
            }
        }
        return true;
    }
};