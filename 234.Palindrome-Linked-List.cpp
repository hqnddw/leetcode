//
// Created by hqnddw on 2020/5/4.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = nullptr;
        ListNode *l2 = reverse(slow);
        while (head && l2) {
            if (head->val != l2->val)
                return false;
            head = head->next;
            l2 = l2->next;
        }
        return true;

    }

    ListNode *reverse(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *cur = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};
