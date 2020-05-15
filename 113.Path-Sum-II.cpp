//
// Created by hqnddw on 2020/5/9.
//
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        helper(root, res, v, sum);
        return res;
    }

    void helper(TreeNode *root, vector<vector<int>> &res, vector<int> &v, int sum) {
        if (!root) return;
        v.push_back(root->val);
        if ((!root->left) && (!root->right) && (root->val == sum)) {
            res.push_back(v);
        }
        helper(root->left, res, v, sum - root->val);
        helper(root->right, res, v, sum - root->val);
        v.pop_back();
    }
};