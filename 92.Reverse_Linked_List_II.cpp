//
// Created by hqnddw on 2019/8/21.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        dummy.next = head;
        for (int i = 0; i < m - 1; ++i) {
            prev = prev->next;
        }
        ListNode *cur = prev->next;
        for (int j = 0; j < n - m; ++j) {
            ListNode *temp = prev->next;
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = temp;
        }
        return dummy.next;
    }
};


//第二次
class Solution2 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int j = 0; j < n - m; ++j) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy.next;
    }
};


//第三次
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || !head->next)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        for (int i = 0; i < m - 1; ++i) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        for (int j = 0; j < n - m; ++j) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy.next;
    }
};