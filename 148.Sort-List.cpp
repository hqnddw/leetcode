//
// Created by yida on 2020/4/17.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return divide(head);
    }
    ListNode *divide(ListNode *head){
        if (!head || !head->next) return head;
        ListNode *pre = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *l1 = divide(head);
        ListNode *l2 = divide(slow);
        return merge(l1, l2);
    }
    ListNode *merge(ListNode* l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while (l1 && l2){
            if (l1->val <l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }
};
