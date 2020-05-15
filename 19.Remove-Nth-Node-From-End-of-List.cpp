//
// Created by hqnddw on 2020/5/4.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

//two pass
class Solution1 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *cur = head;
        int k = 0;
        while (cur) {
            cur = cur->next;
            k++;
        }
        if (k == n) return head->next;
        cur = head;

        while (k - n - 1) {
            cur = cur->next;
            k--;
        }
        cur->next = cur->next->next;
        return head;
    }
};


//one pass 快慢指针
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *dummy = new ListNode(-1);
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            dummy = head->next;
            return dummy;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};