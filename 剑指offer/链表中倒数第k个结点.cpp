//
// Created by hqnddw on 2019/11/7.
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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        ListNode *head = pListHead;
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        int n = count - k;
        if (n < 0) return nullptr;
        while (n--) {
            pListHead = pListHead->next;
        }
        return pListHead;
    }
};


class Solution2 {
public:
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
        ListNode *slow = pListHead;
        ListNode *fast = pListHead;
        while (k--) {
            if (fast)
                fast = fast->next;
            else return nullptr;
        }
        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};