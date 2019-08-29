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
class Solution {
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