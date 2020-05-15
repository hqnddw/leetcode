//
// Created by hqnddw on 2019/10/8.
//
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution1 {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> hash;
        Node *cur = head;
        while (cur) {
            Node *v = new Node(cur->val);
            hash[cur] = v;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            if (cur->next)
                hash[cur]->next = hash[cur->next];
            if (cur->random)
                hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return hash[head];
    }
};


class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;
        Node *l1 = head;
        Node *l2 = nullptr;
        while (l1) {
            l2 = new Node(l1->val);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        Node *res = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return res;
    }
};