//
// Created by hqnddw on 2019/7/7.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;

        return temp;
    }
};