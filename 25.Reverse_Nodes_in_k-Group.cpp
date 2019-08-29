//
// Created by hqnddw on 2019/8/27.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !(head->next) || k == 1)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *begin = &dummy;
        int i = 0;
        while (head) {
            i++;
            if (i % k == 0) {
                begin = reverse(begin, head->next);
                head = begin->next;
            } else head = head->next;
        }
        return dummy.next;
    }

    ListNode *reverse(ListNode *begin, ListNode *end) {
        ListNode *cur = begin->next;
        while (cur->next != end) {
            ListNode *temp = begin->next;
            begin->next = cur->next;
            cur->next = cur->next->next;
            begin->next->next = temp;
        }
        return cur;
    }
};