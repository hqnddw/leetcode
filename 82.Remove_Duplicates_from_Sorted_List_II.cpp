//
// Created by hqnddw on 2019/8/26.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
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


class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        int temp;
        while (pre->next && pre->next->next) {
            if (pre->next->val == pre->next->next->val) {
                temp = pre->next->val;
                while (pre->next && pre->next->val == temp)
                    pre->next = pre->next->next;
            } else pre = pre->next;
        }
        return dummy.next;
    }
};


class Solution3 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        while (pre->next && pre->next->next) {
            if (pre->next->val == pre->next->next->val) {
                int tempValue = pre->next->val;
                while (pre->next && pre->next->val == tempValue)
                    pre->next = pre->next->next;
            } else pre = pre->next;
        }
        return dummy.next;
    }
};