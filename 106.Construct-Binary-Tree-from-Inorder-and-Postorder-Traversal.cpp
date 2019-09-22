//
// Created by hqnddw on 2019/9/4.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &postorder, int post_begin, int post_end,
                        vector<int> &inorder, int in_begin, int in_end) {
        if (post_begin > post_end || in_begin > in_end) return nullptr;
        TreeNode *root = new TreeNode(postorder[post_end]);
        int index;
        for (int i = in_begin; i <= in_end; ++i) {
            if (postorder[post_end] == inorder[i]) {
                index = i;
                break;
            }
        }
        int len = index - in_begin;
        root->left = buildTree(postorder, post_begin, post_begin + len - 1,
                               inorder, in_begin, index - 1);
        root->right = buildTree(postorder, post_begin + len, post_end - 1,
                                inorder, index + 1, in_end);
        return root;
    }
};

class Solution2 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &inorder, int in_start, int in_end,
                        vector<int> &postorder, int post_start, int post_end) {
        if (in_start > in_end || post_start > post_end) return nullptr;
        TreeNode *root = new TreeNode(postorder[post_end]);
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == postorder[post_end]) {
                index = i;
                break;
            }

        }
        int len = index - in_start;
        root->left = buildTree(inorder, in_start, index - 1,
                               postorder, post_start, post_start + len - 1);
        root->right = buildTree(inorder, index + 1, in_end,
                                postorder, post_start + len, post_end - 1);
        return root;
    }
};


class Solution3 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &postorder, int post_start, int post_end,
                        vector<int> &inorder, int in_start, int in_end) {
        if (in_start > in_end || post_start > post_end) return nullptr;
        TreeNode *root = new TreeNode(postorder[post_end]);
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == postorder[post_end]) {
                index = i;
                break;
            }
        }
        int len = index - in_start;
        root->left = buildTree(postorder, post_start, post_start + len - 1,
                               inorder, in_start, index - 1);
        root->right = buildTree(postorder, post_start + len, post_end - 1,
                                inorder, index + 1, in_end);
        return root;
    }
};


class Solution4 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(postorder, 0, postorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &postorder, int post_start, int post_end,
                        vector<int> &inorder, int in_start, int in_end) {
        if (post_start > post_end || in_start > in_end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[post_end]);
        int index = 0;
        for (int i = in_start; i <= in_end; ++i) {
            if (inorder[i] == postorder[post_end]) {
                index = i;
                break;
            }
        }
        int len = index - in_start;
        root->left = buildTree(postorder, post_start, post_start + len - 1,
                               inorder, in_start, index - 1);
        root->right = buildTree(postorder, post_start + len, post_end - 1,
                                inorder, index + 1, in_end);
        return root;
    }
};