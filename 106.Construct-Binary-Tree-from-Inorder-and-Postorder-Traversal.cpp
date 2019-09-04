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


class Solution {
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
