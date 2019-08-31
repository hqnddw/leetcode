//
// Created by hqnddw on 2019/8/30.
//

#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//借助一个maker
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        vector<int> v;
        queue<TreeNode *> q;
        if (!root) return res;
        q.push(root);
        q.push(nullptr);
        while (!q.empty()) {
            root = q.front();
            q.pop();
            if (!root) {
                res.push_back(v);
                v.resize(0);
                if (!q.empty())
                    q.push(nullptr);
            } else {
                v.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};

//不需要额外的队列和maker
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        if (!root) return res;
        while (!q.empty()) {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                v.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (!v.empty())
                res.push_back(move(v));
        }
        return res;
    }
};