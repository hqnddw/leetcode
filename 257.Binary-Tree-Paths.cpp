//
// Created by yida on 2020/5/18.

#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        string s;
        helper(root, s, res);
        return res;
    }

    void helper(TreeNode *root, string s, vector<string> &res) {
        if (!root) return;
        s += to_string(root->val);
        if (!root->left && !root->right)
            res.push_back(s);
        s += "->";
        helper(root->left, s, res);
        helper(root->right, s, res);
    }
};