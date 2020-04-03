//
// Created by hqnddw on 2019/10/26.
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
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s) return false;
        if (helper(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool helper(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return (s->val == t->val) && helper(s->left, t->left) && helper(s->right, t->right);
    }
};


class Solution2 {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s) return false;
        if (helper(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool helper(TreeNode *t1, TreeNode *t2) {
        if (!t1 || !t2) return t1 == t2;
        return (t1->val == t2->val) && helper(t1->left, t2->left)
               && helper(t1->right, t2->right);
    }
};