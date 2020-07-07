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


class Solution2 {
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


class Solution3 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int pre_begin,
                        vector<int> &inorder, int in_begin, int in_end) {
        if (pre_begin > preorder.size() - 1 || in_begin > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_begin]);
        int index = 0;
        for (int i = in_begin; i <= in_end; i++) {
            if (preorder[pre_begin] == inorder[i])
                index = i;
        }
        int len = index - in_begin;
        root->left = buildTree(preorder, pre_begin + 1,
                               inorder, in_begin, index - 1);
        root->right = buildTree(preorder, pre_begin + len + 1,
                                inorder, index + 1, in_end);
        return root;
    }
};


class Solution4 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0,
                         inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder, int pre_start,
                        vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > preorder.size() - 1 || in_start > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                index = i;
                break;
            }
        }
        int len = index - in_start;
        root->left = buildTree(preorder, pre_start + 1, inorder, in_start, index - 1);
        root->right = buildTree(preorder, pre_start + 1 + len, inorder, index + 1, in_end);
        return root;
    }
};


class Solution5 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, int pre_start, int pre_end,
                     vector<int> &inorder, int in_start, int in_end) {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == preorder[pre_start]) {
                index = i;
                break;
            }
        }
        int len = index - in_start;
        root->left = helper(preorder, pre_start + 1, pre_start + len,
                            inorder, in_start, index - 1);
        root->right = helper(preorder, pre_start + len + 1, pre_end,
                             inorder, index + 1, in_end);
        return root;
    }
};