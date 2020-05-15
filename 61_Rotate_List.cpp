//
// Created by hqnddw on 2019/7/2.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
        int len = 1;
        ListNode *new_head = head;
        ListNode *tail = head;
        while (tail->next) {
            len++;
            tail = tail->next;
        }
        tail->next = head;
        if (k % len) {
            for (auto i = 0; i < len - k; ++i)
                tail = tail->next;
        }
        new_head = tail->next;
        tail->next = nullptr;
        return new_head;
    }
};


class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *cur = head;
        int n = 1;
        while (cur->next) {
            cur = cur->next;
            n++;
        }
        cur->next = head;
        k %= n;
        cur = head;
        ListNode *pre = nullptr;
        if (n == k) return head;
        while ((n - k - 1) >= 0) {
            pre = cur;
            cur = cur->next;
            k++;
        }
        pre->next = nullptr;
        return cur;
    }
};