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
        while (cur && cur->next) {
            if (!cur->next->next) {
                if (cur->val == cur->next->val)
                    cur->next = cur->next->next;
                else cur = cur->next;
            } else {
                if (cur->val != cur->next->val)
                    while (cur->next->val == cur->next->next->val)

                        cur->next = cur->next->next;
            }
        }
        return head;
    }
};