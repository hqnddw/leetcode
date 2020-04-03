//
// Created by hqnddw on 2020/4/3.
//
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

// 使用队列，用额外的空间
class Solution1 {
public:
    Node *connect(Node *root) {
        if (!root)
            return nullptr;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node *pre = nullptr;
            for (int i = 0; i < n; ++i) {
                Node *cur = q.front();
                q.pop();
                if (i > 0)
                    pre->next = cur;
                pre = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};

//用二个变量标记当前层和下一层，不用额外的空间
class Solution2 {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        Node *pre = root;
        Node *cur = nullptr;
        while (pre->left) {
            cur = pre;
            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            pre = pre->left;
        }
        return root;
    }
};

//递归
class Solution3 {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        if (root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};