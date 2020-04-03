//
// Created by hqnddw on 2019/10/29.
//

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
    int kthSmallest(TreeNode *root, int k) {
        queue<int> s;
        helper(root, s);
        while (--k && !s.empty()) {
            s.pop();
        }
        return s.front();
    }

    void helper(TreeNode *root, queue<int> &s) {
        if (!root) return;
        helper(root->left, s);
        s.push(root->val);
        helper(root->right, s);
    }
};


class Solution2 {
public:
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> s;
        while (!root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
};


class Solution3 {
public:
    int count = 0;
    int res = 0;

    int kthSmallest(TreeNode *root, int k) {
        if (!root) return -1;
        kthSmallest(root->left, k);
        if (++count == k) res = root->val;
        kthSmallest(root->right, k);
        return res;
    }
};