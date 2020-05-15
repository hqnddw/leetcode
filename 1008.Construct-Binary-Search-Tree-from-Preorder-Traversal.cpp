//
// Created by yida on 2020/4/20.
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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        if (preorder.empty())
            return nullptr;
        stack<TreeNode *> s;
        TreeNode *root = new TreeNode(preorder[0]);
        s.push(root);
        TreeNode *pre = nullptr;
        for (int i = 1; i < preorder.size(); ++i) {
            TreeNode *cur = new TreeNode(preorder[i]);
            if (preorder[i] < s.top()->val) {
                s.top()->left = cur;
            } else {
                while (!s.empty() && preorder[i] > s.top()->val) {
                    pre = s.top();
                    s.pop();
                }
                s.top()->right = pre;
            }
            s.push(cur);
        }
        return root;
    }
};
