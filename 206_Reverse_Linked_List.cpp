//
// Created by hqnddw on 2019/7/3.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

//迭代
class Solution1 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pred = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp_next = cur->next;
            cur->next = pred;
            pred = cur;
            cur = temp_next;
        }
        return pred;
    }
};

//递归
class Solution2 {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};

//第二次
class Solution3 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

//第二次
class Solution4 {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = pre->next;
        while (cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy.next;
    }
};

//第二次
class Solution5 {
public:
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};


//第三次
class Solution6 {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy.next;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return res;
    }
};