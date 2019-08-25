//
// Created by hqnddw on 2019/7/2.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = head;

        while (dummy && dummy->next) {
            if (dummy->val == dummy->next->val) {
                dummy->next = dummy->next->next;
            } else dummy = dummy->next;
        }
        return head;
    }
};