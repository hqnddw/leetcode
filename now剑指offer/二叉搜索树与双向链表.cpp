//
// Created by hqnddw on 2019/11/17.
//
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};


//递归
class Solution1 {
public:
    TreeNode *pre = nullptr;

    TreeNode *Convert(TreeNode *pRootOfTree) {
        if (!pRootOfTree) return nullptr;
        helper(pRootOfTree);
        while (pRootOfTree->left)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }

    void helper(TreeNode *root) {
        if (root == nullptr) return;
        helper(root->left);
        root->left = pre;
        if (pre) pre->right = root;
        pre = root;
        helper(root->right);
    }
};


//迭代
class Solution {
public:
    TreeNode *Convert(TreeNode *pRootOfTree) {
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        bool flag = true;
        TreeNode *head = nullptr;
        if (!pRootOfTree) return nullptr;
        while (pRootOfTree || !s.empty()) {
            while (pRootOfTree) {
                s.push(pRootOfTree);
                pRootOfTree = pRootOfTree->left;
            }
            pRootOfTree = s.top();
            s.pop();
            if (flag) {
                head = pRootOfTree;
                pre = head;
                flag = false;
            } else {
                pRootOfTree->left = pre;
                pre->right = pRootOfTree;
                pre = pRootOfTree;
            }
            pRootOfTree = pRootOfTree->right;
        }
        return head;
    }
};