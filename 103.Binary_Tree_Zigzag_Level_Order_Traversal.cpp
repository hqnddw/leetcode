//
// Created by hqnddw on 2019/9/1.
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

//将vector反转
class Solution1 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty()) {
            vector<int> temp;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (flag % 2 == 0) {
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
            } else v.push_back(temp);
            flag++;
        }
        return v;
    }
};

//插入vector头部
class Solution2 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> v;
        if (!root) return v;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                if (flag % 2 == 0)
                    temp.push_back(root->val);
                else temp.insert(temp.begin(), root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            flag++;
            v.push_back(temp);
        }
        return v;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        vector<vector<int>> v;
        if (!root) return v;
        q.push(root);
        int n;
        int flag = 0;

        while (!q.empty()) {
            n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            if (flag % 2 != 0) {
                reverse(temp.begin(), temp.end());
                v.push_back(temp);
            }
            else v.push_back(temp);
            flag++;
        }
        return v;
    }
};