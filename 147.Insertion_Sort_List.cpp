//
// Created by hqnddw on 2019/8/26.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        while (head) {
            if (pre->next->val > head->val) pre = &dummy;
            while (pre->next && pre->next->val < head->val)
                pre = pre->next;
            ListNode *temp = head->next;
            head->next = pre->next;
            pre->next = head;
            head = temp;
        }
        return dummy.next;
    }
};


//第二次
class Solution2 {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            if (pre->next && pre->next->val > cur->val)
                pre = temp;
            while (pre->next && pre->next->val < cur->val)
                pre = pre->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp;
        }
        return dummy.next;
    }
};


class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(-1);
        ListNode *pre = &dummy;
        while (head) {
//            if (pre->next &&pre->next->val > head->val) pre = &dummy;
            while (pre->next && pre->next->val < head->val)
                pre = pre->next;

            ListNode *cur = head;
            head = head->next;
            cur->next = pre->next;
            pre->next = cur;
            pre = &dummy;

        }
        return dummy.next;
    }
};