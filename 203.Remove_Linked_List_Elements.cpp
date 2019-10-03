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
class Solution2 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        else return head;
    }
};


//第二次
//使用虚拟头节点
class Solution3 {
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

//不使用虚拟头节点
class Solution4 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *cur = head;
        if (!head) return nullptr;
        while (cur->next) {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        if (head->val == val) return head->next;
        else return head;
    }
};

//递归
class Solution5 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head)
            return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        else return head;
    }
};


class Solution6 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        while (pre->next) {
            if (pre->next->val == val)
                pre->next = pre->next->next;
            else pre = pre->next;
        }
        return dummy.next;
    }
};


class Solution7 {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head)
            return nullptr;
        head->next = removeElements(head->next, val);
        if (head->val == val)
            return head->next;
        else return head;
    }
};