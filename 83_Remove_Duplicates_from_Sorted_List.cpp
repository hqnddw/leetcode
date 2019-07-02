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
        ListNode *cur = head;
        ListNode *new_head = head;
        while (cur->next) {
            if (cur->val == cur->next->val)
                cur = cur->next;
            else {
                new_head->next = cur->next;
                new_head = new_head->next;
                cur = cur->next;
            }
        }
        return new_head;
    }
};