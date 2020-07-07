//
// Created by hqnddw on 2020/6/2.
//
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution1 {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left)
            return right;
        if (!right)
            return left;
        return root;
    }
};

class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode *, TreeNode *> map;
        stack<TreeNode *> s;
        s.push(root);
        map[root] = nullptr;
        while (!map.count(p) && !map.count(q)) {
            TreeNode *cur = s.top();
            s.pop();
            if (cur->left) {
                s.push(cur->left);
                map[cur->left] = cur;
            }
            if (cur->right) {
                s.push(cur->right);
                map[cur->right] = cur;
            }
        }
        unordered_set<TreeNode *> set;
        while (p) {
            set.insert(p);
            p = map[p];
        }
        while (q) {
            if (set.count(q))
                break;
            q = map[q];
        }
        return q;
    }
};