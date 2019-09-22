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


class Solution6 {
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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};


class Solution8 {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int cnt = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (!root->left && !root->right)
                    return cnt;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            cnt++;
        }
        return cnt;
    }
};