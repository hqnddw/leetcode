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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        while (head) {
            if (pre->next->val > head->val) pre = &dummy;
            while (pre->next && pre->next->val < head->val)
                pre = pre->next;
            ListNode *temp = head->next;
            head->next = pre->next;
            pre->next = head;
            head = temp;
        }
        return dummy.next;
    }
};
