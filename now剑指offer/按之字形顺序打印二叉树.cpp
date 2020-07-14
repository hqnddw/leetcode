//
// Created by hqnddw on 2019/11/15.
//
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int> > Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;
        queue<TreeNode *> q;
        q.push(pRoot);
        int flag = 1;
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; ++i) {
                pRoot = q.front();
                q.pop();
                tmp.push_back(pRoot->val);
                if (pRoot->left) q.push(pRoot->left);
                if (pRoot->right) q.push(pRoot->right);
            }
            if (flag & 1) res.push_back(tmp);
            else {
                reverse(tmp.begin(), tmp.end());
                res.push_back(tmp);
            }
            flag++;
        }
        return res;
    }
};