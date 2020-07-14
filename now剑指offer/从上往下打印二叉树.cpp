//
// Created by hqnddw on 2019/10/20.
//
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        queue<TreeNode *> q;
        vector<int> v;
        if (!root) return v;
        q.push(root);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left) q.push(root->left);
            if (root->right) q.push(root->right);
        }
        return v;
    }
};