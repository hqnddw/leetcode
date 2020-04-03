//
// Created by hqnddw on 2019/9/22.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        int sum = 0;
        ListNode *cur = &dummy;
        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l1) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum < 10) {
                cur->next = new ListNode(sum);
                sum = 0;
            } else {
                cur->next = new ListNode(sum % 10);
                sum = 1;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};


class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int cnt = 0;
        int sum = 0;
        while (l1 || l2 || cnt) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            cnt = sum / 10;
            sum /= sum;
        }
        return dummy.next;
    }
};


class Solution3 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *cur = &dummy;
        int sum = 0;
        while (l1 || l2 || sum) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            sum /= 10;
        }
        return dummy.next;
    }
};