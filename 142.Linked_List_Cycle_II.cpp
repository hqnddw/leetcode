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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow2 != fast) {
                    slow2 = slow2->next;
                    fast = fast->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};


class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};


class Solution3 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow2 != slow) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};


class Solution4 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow1 = head;
                while (slow != slow1) {
                    slow = slow->next;
                    slow1 = slow1->next;
                }
                return slow1;
            }
        }
        return nullptr;
    }
};


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur) {
            if (pre->next && pre->next->val > cur->val)
                pre = &dummy;
            while (pre->next && pre->next->val < cur->val)
                pre = pre->next;

            ListNode *temp = cur->next;
            pre->next = cur;
            cur = temp;
        }
        return dummy.next;
    }
};
