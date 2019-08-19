//
// Created by hqnddw on 2019/8/19.
//
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


// 两两合并
class Solution1 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]))
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newhead = new ListNode(-1);
        ListNode *dummy = newhead;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                newhead->next = l1;
                l1 = l1->next;
            } else {
                newhead->next = l2;
                l2 = l2->next;
            }
            newhead = newhead->next;
        }
        newhead->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

//优先队列
class Solution2 {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        struct compare {
            bool operator()(ListNode *l1, ListNode *l2) {
                return l1->val > l2->val;
            }
        };
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto i:lists) {
            if (i)
                q.push(i);
        }

        ListNode dummy(-1);
        ListNode *new_head = &dummy;
        while (!q.empty()) {
            ListNode *top = q.top();
            q.pop();
            new_head->next = top;
            new_head = new_head->next;
            if (top->next)
                q.push(top->next);
        }
        return dummy.next;
    }
};

//分而治之
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return divideAndmerge(lists, 0, lists.size() - 1);
    }

    ListNode *divideAndmerge(vector<ListNode *> &lists, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) return lists[start];
        ListNode *left = divideAndmerge(lists, start, (start + end) / 2);
        ListNode *right = divideAndmerge(lists, (start + end) / 2 + 1, end);
        return mergeTwolist(left, right);
    }

    ListNode *mergeTwolist(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwolist(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwolist(l1, l2->next);
            return l2;
        }
    }
};