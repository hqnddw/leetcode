//
// Created by hqnddw on 2019/8/26.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

//迭代
class Solution1 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next) {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        return dummy.next;
    }
};


//递归
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        else return head;
    }
};