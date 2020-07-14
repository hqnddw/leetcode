//
// Created by hqnddw on 2019/11/14.
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
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1 && !pHead2)
            return nullptr;
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }
        if (pHead1) cur->next = pHead1;
        else cur->next = pHead2;
        return dummy.next;
    }
};


class Solution2 {
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        if (pHead1->val < pHead2->val) {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        } else {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};