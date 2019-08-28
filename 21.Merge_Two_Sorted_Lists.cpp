//
// Created by hqnddw on 2019/8/19.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newhead = new ListNode(-1);
        ListNode *dummy = newhead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                newhead->next = l1;
                l1 = l1->next;
            } else {
                newhead->next = l2;
                l2 = l2->next;
            }
            newhead = newhead->next;
        }
        if (l1) newhead->next = l1;
        else newhead->next = l2;
        return dummy->next;
    }
};

//递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
