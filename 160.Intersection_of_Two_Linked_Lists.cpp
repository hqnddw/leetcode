#include <cmath>

//
// Created by hqnddw on 2019/8/28.
//
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        if (!headA || !headB) return nullptr;
        while (headA && headB && headA != headB) {

            headA = headA->next;
            headB = headB->next;
            if (headA == headB)
                return headA;
            if (!headA) headA = nodeB;
            if (!headB) headB = nodeA;

        }
        return headA;
    }
};

//不管A,B是否相交，headA和headB一定会相遇
//如果A，B有交点，会在交点处相遇，返回交点
//如果A，B没有交点，会在null处相遇，返回null
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *nodeA = headA;
        ListNode *nodeB = headB;
        while (headA != headB) {
            headA = (!headA) ? nodeB : headA->next;
            headB = (!headB) ? nodeA : headB->next;
        }
        return headA;
    }
};

//第三次
class Solution3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return nullptr;
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        int count1 = 0;
        int count2 = 0;
        while (node1) {
            node1 = node1->next;
            count1++;
        }
        while (node2) {
            node2 = node2->next;
            count2++;
        }
        int v = abs(count1 - count2);
        ListNode *small = headA;
        ListNode *big = headA;
        if (count1 > count2)
            small = headB;
        else big = headB;
        while (v) {
            big = big->next;
            v--;
        }
        while (big != small) {
            big = big->next;
            small = small->next;
        }
        return small;
    }
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *node1 = headA;
        ListNode *node2 = headB;
        while (headA != headB) {
            headA = (!headA) ? node2 : headA->next;
            headB = (!headB) ? node1:headB->next;
        }
        return headA;
    }
};