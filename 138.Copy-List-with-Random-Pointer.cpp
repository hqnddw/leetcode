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

    Node() {}

    Node(int _val, Node *_next, Node *_random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution1 {
public:
    Node *copyRandomList(Node *head) {
        Node *cur = head;
        Node *next = nullptr;

        while (cur) {
            next = cur->next;
            Node *copy = new Node(cur->val, next, nullptr);
            cur->next = copy;
            cur = next;
        }

        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        cur = head;
        Node dummy(-1, nullptr, nullptr);
        Node *temp = &dummy;
        Node *res = &dummy;
        while (cur) {
            next = cur->next->next;
            temp = cur->next;
            res->next = temp;
            res = res->next;

            cur->next = next;
            cur = cur->next;
        }
        return dummy.next;
    }
};


class Solution2 {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *l1 = head;
        Node *l2 = nullptr;

        while (l1) {
            l2 = new Node(l1->val, l1->random, nullptr);
            l1->random = l2;
            l1 = l1->next;
        }
        l1 = head;
        while (l1) {
            l2 = l1->random;
            l2->random = (l2->next) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        Node *l2_head = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next) ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return l2_head;
    }
};


class Solution3 {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *l1 = head;
        Node *l2 = nullptr;
        while (l1) {
            l2 = new Node(l1->val, l1->random, nullptr);
            l1->random = l2;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) {
            l2 = l1->random;
            l2->random = (l2->next) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        Node *l2_head = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next) ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return l2_head;
    }
};


class Solution4 {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *l1 = head;
        Node *l2 = nullptr;
        while (l1) {
            l2 = new Node(l1->val, nullptr, nullptr);
            l2->next = l1->random;
            l1->random = l2;
            l1 = l1->next;
        }

        l1 = head;
        while (l1) {
            l2 = l1->random;
            l2->random = (l2->next) ? l2->next->random : nullptr;
            l1 = l1->next;
        }

        l1 = head;
        Node *dummy = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = (l1->next) ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return dummy;
    }
};


class Solution5 {
public:
    Node *copyRandomList(Node *head) {
        if (!head)
            return nullptr;
        Node *l1 = head;
        Node *l2 = nullptr;
        while (l1) {
            l2 = new Node(l1->val, nullptr, nullptr);
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
        Node *res_head = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return res_head;
    }
};