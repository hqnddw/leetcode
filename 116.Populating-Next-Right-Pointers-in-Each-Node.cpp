//
// Created by hqnddw on 2019/10/16.
//
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};


class Solution1 {
public:
    Node *connect(Node *root) {
        queue<Node *> q;
        if (!root) return nullptr;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n - 1; ++i) {
                Node *node1 = q.front();
                q.pop();
                if (node1->left) q.push(node1->left);
                if (node1->right) q.push(node1->right);
                Node *node2 = q.front();
                node1->next = node2;
            }
            Node *last = q.front();
            q.pop();
            if (last->left) q.push(last->left);
            if (last->right) q.push(last->right);
        }
        return root;
    }
};


class Solution2 {
public:
    Node *connect(Node *root) {
        Node *level_start = root;
        while (level_start) {
            Node *cur = level_start;
            while (cur) {
                if (cur->left) cur->left->next = cur->right;
                if (cur->right && cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            level_start = level_start->left;
        }
        return root;
    }
};


class Solution3 {
public:
    Node *connect(Node *root) {
        if (!root) return root;
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};


class Solution4 {
public:
    Node *connect(Node *root) {
        Node *head = root;
        while (root) {
            Node *cur = root;
            while (root->left) {
                if (root->left) root->left->next = root->right;
                if (root->right && root->next) root->right->next = root->next->left;
                root = root->next;
            }
            root = cur->left;
        }
        return head;
    }
};


class Solution5 {
public:
    Node *connect(Node *root) {
        Node *head = root;
        while (root) {
            Node *tmp = root;
            while (root) {
                if (root->left)
                    root->left->next = root->right;
                if (root->right && root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
            root = tmp->left;
        }
        return head;
    }
};


class Solution6 {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        if (root->left) {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};