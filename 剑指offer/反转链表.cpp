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