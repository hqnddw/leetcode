//
// Created by hqnddw on 2019/11/15.
//
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};

class Solution1 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (root->val == sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


class Solution {
public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        vector<vector<int>> res;
        if (!root)
            return res;
        vector<int> v;
        helper(root, expectNumber, res, v);
        return res;
    }

    void helper(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> v) {
        if (!root->left && !root->right && root->val == sum) {
            v.push_back(root->val);
            res.push_back(v);
            return;
        }
        v.push_back(root->val);
        if (root->left) {
            helper(root->left, sum - root->val, res, v);
        }
        if (root->right) {
            helper(root->right, sum - root->val, res, v);
        }
    }
};