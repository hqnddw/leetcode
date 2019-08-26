//
// Created by hqnddw on 2019/8/26.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *node1 = new ListNode(-1);
        ListNode *dummy1 = node1;
        ListNode *node2 = new ListNode(-1);
        ListNode *dummy2 = node2;
        while (head) {
            if (head->val < x) {
                node1->next = head;
                node1 = node1->next;
            } else {
                node2->next = head;
                node2 = node2->next;
            }
            head = head->next;
        }
        node2->next = nullptr;
        node1->next = dummy2->next;
        return dummy1->next;
    }
};