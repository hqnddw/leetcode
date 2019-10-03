//
// Created by hqnddw on 2019/9/3.
//
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!(root->left)) return 1 + minDepth(root->right);
        if (!(root->right)) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

class Solution2 {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        int n = 1;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                root = q.front();
                q.pop();
                if (!root->left && !root->right)
                    return n;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            n++;
        }
        return n;
    }
};


class Solution3 {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (!root->left && !root->right)
                    return count;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            count++;
        }
        return count;
    }
};


class Solution4 {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;

        if (!root->left) return minDepth(root->right) + 1;
        if (!root->right) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};


class Solution5 {
public:
    int minDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if (!root) return 0;
        int count = 1;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (!root->left && !root->right) return count;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            count++;
        }
        return count;
    }
};


class Solution16 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->right) && isBalanced(root->left);
    }

    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};

class Solution7 {
public:
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }

    int depth(TreeNode *root) {
        if (!root) return 0;
        int left = depth(root->left);
        if (left == -1) return -1;
        int right = depth(root->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return max(right, left) + 1;
    }
};


class Solution8 {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left)
            return minDepth(root->right) + 1;
        if (!root->right)
            return minDepth(root->left) + 1;
        return min(minDepth(root->right), minDepth(root->left)) + 1;
    }
};


class Solution9 {
public:
    int minDepth(TreeNode *root) {
        queue<TreeNode *> q;
        int count = 0;
        if (root) {
            q.push(root);
            count++;
        }
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (!root->left && !root->right)
                    return count;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            count++;
        }
        return count;
    }
};