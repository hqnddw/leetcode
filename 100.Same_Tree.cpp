//
// Created by hqnddw on 2019/8/30.
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

//递归
class Solution1 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//迭代
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) return p == q;
        stack<TreeNode *> s_p;
        stack<TreeNode *> s_q;
        s_p.push(p);
        s_q.push(q);
        while (!s_p.empty() && !s_q.empty()) {
            p = s_p.top();
            s_p.pop();
            q = s_q.top();
            s_q.pop();
            if (p->val != q->val) return false;
            if (p->left) s_p.push(p->left);
            if (q->left) s_q.push(q->left);
            if (s_p.size() != s_q.size()) return false;
            if (p->right) s_p.push(p->right);
            if (q->right) s_q.push(q->right);
            if (s_q.size() != s_p.size()) return false;
        }
        return s_p.size() == s_q.size();
    }
};