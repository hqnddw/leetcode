//
// Created by hqnddw on 2020/5/4.
//

// Definition for a Node.
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution {
public:
    Node *flatten(Node *head) {
        if (!head) return nullptr;
        Node *cur = head;
        while (cur) {
            if (!cur->child) {
                cur = cur->next;
                continue;
            }
            Node *p = cur->child;
            while (p->next)
                p = p->next;
            p->next = cur->next;
            if (cur->next) cur->next->prev = p;
            cur->next = cur->child;
            cur->child->prev = cur;
            cur->child = nullptr;
        }
        return head;
    }
};