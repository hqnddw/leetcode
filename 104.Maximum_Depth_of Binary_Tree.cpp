//
// Created by hqnddw on 2019/9/1.
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

//BFS,利用层次遍历
class Solution1 {
public:
    int maxDepth(TreeNode *root) {
        queue<TreeNode *> q;
        if (!root) return 0;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            count++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return count;
    }
};

//DFS
class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


class Solution3 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


class Solution4 {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};