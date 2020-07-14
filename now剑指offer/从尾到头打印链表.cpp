//
// Created by hqnddw on 2019/10/20.
//
#include <vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(nullptr) {
    }
};

class Solution1 {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> res;
        if (!head) return res;
        helper(head, res);
        return res;
    }

    ListNode *helper(ListNode *head, vector<int> &res) {
        if (!head || !head->next) {
            res.push_back(head->val);
            return head;
        }

        ListNode *cur = helper(head->next, res);
        res.push_back(head->val);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};

class Solution2 {
public:
    vector<int> printListFromTailToHead(ListNode *head) {
        vector<int> v;
        if (!head)
            return v;
        ListNode *pre = nullptr;
        while (head) {
            ListNode *next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }

        while (pre) {
            v.push_back(pre->val);
            pre = pre->next;
        }
        return v;
    }
};