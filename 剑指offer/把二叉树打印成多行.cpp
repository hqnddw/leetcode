//
// Created by hqnddw on 2019/11/14.
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
    vector<vector<int> > Print(TreeNode *pRoot) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (!pRoot) return res;
        q.push(pRoot);
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
            res.push_back(tmp);
        }
        return res;
    }
};