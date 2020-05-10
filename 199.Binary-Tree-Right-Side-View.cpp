//
// Created by hqnddw on 2020/5/9.
//
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//BFS
class Solution1 {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (i == n - 1)
                    res.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};

//DFS
class Solution2 {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        helper(res, root, 0);
        return res;
    }

    void helper(vector<int> &res, TreeNode *root, int depth) {
        if (!root) return;
        if (res.size() == depth)
            res.push_back(root->val);
        helper(res, root->right, depth + 1);
        helper(res, root->left, depth + 1);
    }
};