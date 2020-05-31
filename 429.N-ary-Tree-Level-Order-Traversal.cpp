//
// Created by yida on 2020/5/24.
//
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> res;
        queue<Node *> q;
        if (!root) return res;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                v.push_back(root->val);
                for (auto it : root->children) {
                    q.push(it);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};