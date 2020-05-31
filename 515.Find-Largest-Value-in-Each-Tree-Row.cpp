//
// Created by yida on 2020/5/24.
//
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//bfs
class Solution1 {
public:
    vector<int> largestValues(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int tmp = INT_MIN;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                tmp = max(tmp, root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

//dfs
class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
    }

    void helper(TreeNode *root, vector<int> &res, int level) {
        if (!root) return;
        if (res.size() == level)
            res.push_back(root->val);
        else {
            res[level] = max(res[level], root->val);
        }
        helper(root->left, res, level + 1);
        helper(root->right, res, level + 1);
    }
};