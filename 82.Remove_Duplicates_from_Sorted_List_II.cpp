//
// Created by hqnddw on 2019/8/26.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int temp_value = cur->next->val;
                while (cur->next && cur->next->val == temp_value)
                    cur->next = cur->next->next;
            } else cur = cur->next;
        }
        return dummy.next;
    }
};