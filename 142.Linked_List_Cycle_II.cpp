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


class Solution {
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