//
// Created by hqnddw on 2019/9/2.
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

class Solution1 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(0, preorder.size() - 1,
                         0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *buildTree(int pre_start, int pre_end, int in_start, int in_end,
                        vector<int> &preorder, vector<int> &inorder) {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int in_dex = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start])
                in_dex = i;
        }
        int len = in_dex - in_start;
        root->left = buildTree(pre_start + 1, pre_start + len, in_start,
                               in_dex - 1, preorder, inorder);
        root->right = buildTree(pre_start + len + 1, pre_end,
                                in_dex + 1, in_end, preorder, inorder);
        return root;
    }
};


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty())
            return nullptr;
        stack<TreeNode *> s;

        int i = 0; // 遍历preorder的标记
        int j = 0; //遍历inorder的标记
        int flag = 0; //向右子树插入节点的标记

        TreeNode *root = new TreeNode(preorder[i]);
        s.push(root);
        TreeNode *cur = root;
        i++;
        while (i < preorder.size()) {
            if (!s.empty() && s.top()->val == inorder[j]) {
                cur = s.top();
                s.pop();
                flag = 1;
                j++;
            } else {
                if (flag == 0) {
                    cur->left = new TreeNode(preorder[i]);
                    cur = cur->left;
                    s.push(cur);
                    i++;
                } else {
                    cur->right = new TreeNode(preorder[i]);
                    cur = cur->right;
                    s.push(cur);
                    flag = 0;
                    i++;
                }
            }
        }
        return root;
    }
};