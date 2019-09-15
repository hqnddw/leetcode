//
// Created by hqnddw on 2019/8/27.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
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


//第二次
class Solution2 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !(head->next) || k == 1)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *begin = &dummy;
        ListNode *cur = begin;
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

class Solution3 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = 0;
        ListNode *cur = head;
        for (auto i = cur; cur; n++, cur = cur->next);
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *next = pre->next;
        for (; n >= k; n -= k) {
            for (int i = 1; i < k; ++i) {
                ListNode *temp = pre->next;
                pre->next = next->next;
                next->next = next->next->next;
                pre->next->next = temp;
            }
            pre = next;
            next = next->next;
        }
        return dummy.next;
    }
};


class Solution4 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next || k == 1)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head;
        ListNode *pre = &dummy;
        int count = 0;
        while (cur) {
            cur = cur->next;
            count++;
        }
        cur = pre->next;
        for (; count >= k; count -= k) {
            for (int i = 1; i < k; ++i) {
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};


class Solution5 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        ListNode *cur = pre->next;
        for (; count >= k; count -= k) {
            for (int i = 1; i < k; ++i) {
                ListNode *temp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = temp;
            }
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};