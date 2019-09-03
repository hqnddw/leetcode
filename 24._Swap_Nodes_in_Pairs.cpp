//
// Created by hqnddw on 2019/7/7.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;

        return temp;
    }
};


class Solution2 {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution3 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !(head->next)) return head;
        ListNode *n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};


//第二次迭代
class Solution4 {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        while (pre->next && pre->next->next) {
            ListNode *cur = pre->next;
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
            pre = cur;
        }
        return dummy.next;
    }
};

//第二次递归
class Solution5 {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head->next)
            return nullptr;
        ListNode *n = head->next;

        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};


//第三次
class Solution6 {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = pre->next;
        while (cur && cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
            pre = cur;
            cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return nullptr;
        ListNode *n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};