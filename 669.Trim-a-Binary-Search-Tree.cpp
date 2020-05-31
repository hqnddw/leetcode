//
// Created by yida on 2020/5/29.
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

class Solution1 {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        vector<int> v;
        helper(root, v);
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] < L || v[i] > R) {
                auto it = v.begin() + i;
                v.erase(it);
            }
        }
        if (v.empty())
            return nullptr;
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        TreeNode *res = new TreeNode(v[0]);
        s.push(res);
        for (int j = 1; j < v.size(); ++j) {
            TreeNode *cur = new TreeNode(v[j]);
            if (v[j] < s.top()->val) {
                s.top()->left = cur;
            } else {
                while (!s.empty() && v[j] > s.top()->val) {
                    pre = s.top();
                    s.pop();
                }
                pre->right = cur;
            }
            s.push(cur);
        }
        return res;
    }

    void helper(TreeNode *root, vector<int> &v) {
        if (!root) return;
        v.push_back(root->val);
        helper(root->left, v);
        helper(root->right, v);
    }
};


class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) return nullptr;
        if (root->val < L) return trimBST(root->right, L, R);
        if (root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};