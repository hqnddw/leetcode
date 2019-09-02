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
class Solution2 {
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

//第二次
class Solution3 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//迭代
//两个队列
class Solution4 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> q1;
        queue<TreeNode *> q2;
        if (!p && !q) return true;
        if (!p || !q) return false;
        q1.push(p),
                q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            p = q1.front();
            q1.pop();
            q = q2.front();
            q2.pop();
            if (p->val != q->val) return false;
            if (p->left) q1.push(p->left);
            if (q->left) q2.push(q->left);
            if (q1.size() != q2.size()) return false;
            if (p->right) q1.push(p->right);
            if (q->right) q2.push(q->right);
            if (q2.size() != q1.size()) return false;
        }
        return true;
    }
};

//一个队列
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        queue<TreeNode *> queue;
        queue.push(p);
        queue.push(q);
        while (!queue.empty()) {
            p = queue.front();
            queue.pop();
            q = queue.front();
            queue.pop();
            if (!p && !q) continue;
            if (!p || !q || p->val != q->val) return false;
            queue.push(p->left);
            queue.push(q->left);
            queue.push(p->right);
            queue.push(q->right);
        }
        return true;
    }
};