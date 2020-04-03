//
// Created by hqnddw on 2019/10/19.
//
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution1 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pre = nullptr;
        while (pHead) {
            ListNode *next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};

class Solution2 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *cur = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return cur;
    }
};


class Solution3 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pre = nullptr;
        while (pHead) {
            ListNode *next = pHead->next;
            pHead->next = pre;
            pre = pHead;
            pHead = next;
        }
        return pre;
    }
};


class Solution4 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        ListNode *pre = new ListNode(-1);
        pre->next = pHead;
        ListNode *cur = pHead;
        while (cur && cur->next) {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return pre->next;
    }
};


class Solution5 {
public:
    ListNode *ReverseList(ListNode *pHead) {
        if (!pHead || !pHead->next)
            return pHead;
        ListNode *cur = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return cur;
    }
};

