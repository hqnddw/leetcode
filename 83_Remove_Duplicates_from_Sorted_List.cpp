//
// Created by hqnddw on 2019/7/2.
//

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *dummy = head;

        while (dummy && dummy->next) {
            if (dummy->val == dummy->next->val) {
                dummy->next = dummy->next->next;
            } else dummy = dummy->next;
        }
        return head;
    }
};


//第二次
class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = head;
        while (head && head->next) {
            if (head->val == head->next->val)
                head->next = head->next->next;
            else head = head->next;
        }
        return dummy;
    }
};


class Solution3 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        head->next = deleteDuplicates(head->next);
        if (head->val == head->next->val)
            return head->next;
        else return head;
    }
};