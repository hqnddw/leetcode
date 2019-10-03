//
// Created by hqnddw on 2019/9/1.
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

//迭代
class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            TreeNode *node1 = q.front();
            q.pop();
            TreeNode *node2 = q.front();
            q.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2) return false;
            if (node1->val != node2->val) return false;
            q.push(node1->left);
            q.push(node2->right);
            q.push(node1->right);
            q.push(node2->left);
        }
        return true;
    }
};

//递归
class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};


class Solution3 {
public:
    bool isSymmetric(TreeNode *root) {
        return vaild(root, root);
    }

    bool vaild(TreeNode *root1, TreeNode *root2) {
        if (!root1 || !root2) return root1 == root2;
        return root1->val == root2->val &&
               vaild(root1->left, root2->right) && vaild(root1->right, root2->left);
    }
};


class Solution4 {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        TreeNode *t1 = nullptr;
        TreeNode *t2 = nullptr;
        while (!q.empty()) {
            t1 = q.front();
            q.pop();
            t2 = q.front();
            q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};


class Solution5 {
public:
    bool isSymmetric(TreeNode *root) {
        return valid(root, root);
    }

    bool valid(TreeNode *root1, TreeNode *root2) {
        if (!root1 || !root2) return root1 == root2;
        return (root1->val == root2->val) && valid(root1->left, root2->right)
               && valid(root1->right, root2->left);
    }
};


class Solution6 {
public:
    bool isSymmetric(TreeNode *root) {
        return valid(root, root);
    }

    bool valid(TreeNode *root1, TreeNode *root2) {
        if (!root1 || !root2) return root1 == root2;
        return (root1->val == root2->val) && valid(root1->left, root2->right)
               && valid(root1->right, root2->left);
    }
};