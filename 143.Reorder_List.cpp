//
// Created by hqnddw on 2019/8/21.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *p = head;
        ListNode *q = getMidNode(head);
        q = reverseList(q);
        mergeList(p, q);
    }

    ListNode *getMidNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow && fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *next_ = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next_;
        }
        return pre;
    }

    void mergeList(ListNode *p, ListNode *q) {
        ListNode *temp;
        while (q) {
            temp = p->next;
            p->next = q;
            p = p->next;
            q = q->next;
            p->next = temp;
            p = p->next;
        }
    }
};