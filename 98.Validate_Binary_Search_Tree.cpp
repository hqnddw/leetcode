//
// Created by hqnddw on 2019/8/26.
//
#include <stack>

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

    bool valid(TreeNode *root, TreeNode *pre) {
        if (!root) return true;
        if (!valid(root->left, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        root = root->right;
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

    bool valid(TreeNode *root, TreeNode *pre) {
        if (!root) return true;
        if (!valid(root, pre)) return false;
        if (pre && pre->val >= root->val) return false;
        pre = root;
        return valid(root->right, pre);
    }
};

class Solution {
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
            if (pre && pre->val > root->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};