//
// Created by hqnddw on 2019/11/13.
//
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *deleteDuplication(ListNode *pHead) {
        ListNode dummy(-1);
        dummy.next = pHead;
        ListNode *cur = &dummy;
        while ((cur->next && cur->next->next)) {
            if (cur->next->val == cur->next->next->val) {
                int tmp = cur->next->val;
                while (cur->next && cur->next->val == tmp)
                    cur->next = cur->next->next;
            } else cur = cur->next;
        }
        return dummy.next;
    }
};