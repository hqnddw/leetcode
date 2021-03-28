//
// Created by yida on 2020/5/22.
//
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> children;

    Node(Node *pNode) {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

//bfs
class Solution1 {
public:

    int maxDepth(Node *root) {
        queue<Node *> q;
        if (!root) return 0;
        q.push(root);
        int res = 1;
        while (!q.empty()) {
            res++;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                root = q.front();
                q.pop();
                for (auto child : root->children) {
                    q.push(child);
                }
            }
        }
        return res;
    }
};

//dfs
class Solution {
public:
    int maxDepth(Node *root) {
        int res = 0;
        if (!root) return 0;
        for (auto child : root->children) {
            res = max(res, maxDepth(child));
        }
        return res + 1;
    }
};