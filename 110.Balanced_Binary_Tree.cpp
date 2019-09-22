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
class Solution2 {
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
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};


class Solution3 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};

class Solution16 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->right) && isBalanced(root->left);
    }

    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->right), maxDepth(root->left));
    }
};

class Solution4 {
public:
    bool isBalanced(TreeNode *root) {
        return depth(root) != -1;
    }

    int depth(TreeNode *root) {
        if (!root) return 0;
        int left = depth(root->left);
        if (left == -1) return -1;
        int right = depth(root->right);
        if (right == -1) return -1;
        if (abs(left - right) > 1) return -1;
        return max(right, left) + 1;
    }
};

class Solution5 {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return false;
        if (abs(maxdepth(root->left) - maxdepth(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int maxdepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
};


class Solution6 {
public:
    bool isBalanced(TreeNode *root) {
        return helper(root) != -1;
    }

    int helper(TreeNode *root) {
        if (!root) return 0;
        int left = helper(root->left);
        if (left == -1)
            return -1;
        int right = helper(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }
};


