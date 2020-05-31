//
// Created by hqnddw on 2020/5/4.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *l2 = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = l2;
        return head;
    }
};


class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *l1 = head;
        ListNode *l2 = head->next;
        ListNode *dummy = l2;
        while (l2 && l2->next) {
            l1->next = l1->next->next;
            l1 = l1->next;
            l2->next = l2->next->next;
            l2 = l2->next;
        }
        l1->next = dummy;
        return head;
    }
};