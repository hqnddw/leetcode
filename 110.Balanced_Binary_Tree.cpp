//
// Created by hqnddw on 2019/9/3.
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

//自上而下
//先验证以root为根的树是否为平衡树
//再验证root的左右子树是否为平衡树
class Solution1 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root);
    }

    int getDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
};


//自下而上
//利用DFS进入树的底部，向上开始验证
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return getHeight(root) != -1;
    }

    int getHeight(TreeNode *root) {
        if (!root) return 0;
        int leftHeight = getHeight(root->left);
        if (leftHeight == -1) return -1;
        int rightHeight = getHeight(root->right);
        if (rightHeight == -1) return -1;
        if (abs(leftHeight - rightHeight) > 1) return false;
        return 1 + max(leftHeight, rightHeight);
    }
};