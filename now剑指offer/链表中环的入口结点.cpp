//
// Created by hqnddw on 2019/11/13.
//
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution {
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead) {
        ListNode *slow = pHead;
        ListNode *fast = pHead;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = pHead;
                while (slow2 != fast) {
                    slow2 = slow2->next;
                    fast = fast->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};