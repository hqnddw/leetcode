//
// Created by hqnddw on 2019/11/15.
//
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode *Clone(RandomListNode *head) {
        if (!head)
            return nullptr;
        RandomListNode *l1 = head;
        RandomListNode *l2 = nullptr;
        while (l1) {
            l2 = new RandomListNode(l1->label);
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
        RandomListNode *res_head = l1->random;
        while (l1) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
            l1 = l1->next;
        }
        return res_head;
    }
};