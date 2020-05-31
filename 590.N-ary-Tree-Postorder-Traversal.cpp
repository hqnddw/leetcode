//
// Created by yida on 2020/5/27.
//

#include <vector>
#include <stack>
#include <algorithm>
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

class Solution1 {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(Node *root, vector<int> &res) {
        if (!root) return;
        for (auto child : root->children)
            helper(child, res);
        res.push_back(root->val);
    }
};


class Solution {
public:
    vector<int> postorder(Node *root) {
        vector<int> res;
        stack<Node *> s;
        if (!root) return res;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            res.push_back(root->val);
            for (auto it = root->children.rbegin(); it != root->children.rend(); it++) {
                s.push(*it);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};