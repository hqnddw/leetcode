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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> v;
        if (!root) return v;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            count ++;
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            v.push_back(temp);
            reverse(v.begin(), v.end());
        }
        return v;
    }
};
