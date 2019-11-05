//
// Created by hqnddw on 2019/10/21.
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

class BSTIterator1 {
public:
    stack<TreeNode *> s;
    queue<int> q;

    BSTIterator1(TreeNode *root) {

        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            q.push(root->val);
            root = root->right;
        }
    }

    /** @return the next smallest number */
    int next() {
        int a = q.front();
        q.pop();
        return a;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};


class BSTIterator2 {
public:
    stack<TreeNode *> s;
    queue<int> q;

    BSTIterator2(TreeNode *root) {
        helper(root);
    }

    void helper(TreeNode *root) {
        if (!root) return;
        helper(root->left);
        q.push(root->val);
        helper(root->right);
    }

    /** @return the next smallest number */
    int next() {
        int a = q.front();
        q.pop();
        return a;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};
