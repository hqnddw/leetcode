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

class Solution1 {
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
                pre->right = cur;
            }
            s.push(cur);
        }
        return root;
    }
};


class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, int start, int end) {
        if (start > end) return nullptr;
        TreeNode *root = new TreeNode(preorder[start]);
        int i = start+1;
        while (i <= end && preorder[i] < preorder[start])
            i++;
        root->left = helper(preorder, start + 1, i - 1);
        root->right = helper(preorder, i, end);
        return root;
    }
};