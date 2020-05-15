//
// Created by hqnddw on 2020/5/7.
//
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        queue<pair<TreeNode *, int>> q;
        if (!root) return false;
        q.push(make_pair(root, 0));
        int parent = -1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto it = q.front();
                TreeNode *cur = it.first;
                int v = it.second;
                q.pop();
                if (cur->val == x || cur->val == y) {
                    if (parent != -1) {
                        return parent != v;
                    }
                    parent = v;
                }
                if (cur->left) {
                    q.push(make_pair(cur->left, cur->val));
                }
                if (cur->right) {
                    q.push(make_pair(cur->right, cur->val));
                }
            }
            if (parent != -1) {
                return false;
            }
        }
        return false;
    }
};
