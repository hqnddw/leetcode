//
// Created by hqnddw on 2019/10/16.
//
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
        Node *head = root;
        Node *dummy = new Node(-1, nullptr, nullptr, nullptr);
        while (root) {
            Node *cur = dummy;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy->next;
            dummy->next = nullptr;
        }
        return head;
    }
};


class Solution2 {
public:
    Node *connect(Node *root) {
        Node *head = root;
        Node *dummy = new Node(-1, nullptr, nullptr, nullptr);
        while (root) {
            Node *cur = dummy;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy->next;
            dummy->next = nullptr;
        }
        return head;
    }
};


class Solution3 {
public:
    Node *connect(Node *root) {
        Node *dummy = new Node(-1, nullptr, nullptr, nullptr);
        Node *head = root;
        while (root) {
            Node *cur = dummy;
            while (root) {
                if (root->left) {
                    cur->next = root->left;
                    cur = cur->next;
                }
                if (root->right) {
                    cur->next = root->right;
                    cur = cur->next;
                }
                root = root->next;
            }
            root = dummy->next;
            dummy->next = nullptr;
        }
        return head;
    }
};