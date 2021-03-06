//
// Created by hqnddw on 2019/9/4.
//
#include <vector>
#include <stack>
#include <queue>
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (root->val == sum && !root->left && !root->right) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

//递归
class Solution2 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (root->val == sum && !root->right && !root->left) return true;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};


//BFS
class Solution3 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        queue<TreeNode *> q1;
        queue<int> q2;
        if (!root) return false;
        q1.push(root);
        q2.push(root->val);
        while (!q1.empty()) {
            int n = q1.size();
            for (int i = 0; i < n; ++i) {
                root = q1.front();
                q1.pop();
                int num = q2.front();
                q2.pop();
                if (!root->left && !root->right && num == sum)
                    return true;
                if (root->left) {
                    q1.push(root->left);
                    q2.push(num + root->left->val);
                }
                if (root->right) {
                    q1.push(root->right);
                    q2.push(num + root->right->val);
                }
            }
        }
        return false;
    }
};


//后序遍历
class Solution4 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        TreeNode *pre = nullptr;
        stack<TreeNode *> s;
        int cursum = 0;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                cursum += root->val;
                root = root->left;
            } else {
                root = s.top();
                if (root->right && root->right != pre) {
                    root = root->right;
                    s.push(root);
                    cursum += root->val;
                    root = root->left;
                } else {
                    if (!root->left && !root->right && cursum == sum)
                        return true;
                    s.pop();
                    cursum -= root->val;
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return false;
    }
};

class Solution5 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val)
               || hasPathSum(root->right, sum - root->val);
    }
};


class Solution6 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        int cursum = 0;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                cursum += root->val;
                root = root->left;
            } else {
                root = s.top();
                if (root->right && root->right != pre) {
                    root = root->right;
                    s.push(root);
                    cursum += root->val;
                    root = root->left;
                } else {
                    if (cursum == sum && !root->left && !root->right)
                        return true;
                    s.pop();
                    cursum -= root->val;
                    pre = root;
                    root = nullptr;

                }
            }
        }
        return false;
    }
};


class Solution7 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right)
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};


class Solution8 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        int curSum = 0;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                curSum += root->val;
                root = root->left;
            } else {
                root = s.top();
                if (root->right && root->right != pre) {
                    root = root->right;
                    s.push(root);
                    curSum += root->val;
                    root = root->left;
                } else {
                    if (!root->left && !root->right && curSum == sum)
                        return true;
                    s.pop();
                    curSum -= root->val;
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return false;
    }
};


class Solution9 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        queue<TreeNode *> q;
        queue<int> curSum;
        q.push(root);
        curSum.push(root->val);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                int cur = curSum.front();
                curSum.pop();
                if (!root->left && !root->right && cur == sum)
                    return true;
                if (root->left) {
                    q.push(root->left);
                    curSum.push(cur + root->left->val);
                }
                if (root->right) {
                    q.push(root->right);
                    curSum.push(cur + root->right->val);
                }
            }

        }
        return false;
    }

};


class Solution10 {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};