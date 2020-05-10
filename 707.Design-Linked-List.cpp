//
// Created by hqnddw on 2020/5/3.
//
#include <iostream>

//单向链表
class MyLinkedList1 {
public:
    struct Node {
        int val;
        Node *next;

        Node(int x) : val(x), next(nullptr) {}
    };

    /** Initialize your data structure here. */
    Node *head;
//    ListNode *dummy = new ListNode(-1);
    int size;

    MyLinkedList1() {
        head = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;
        Node *cur = head;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        cur->next = head;
        head = cur;
        size++;
        return;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = new Node(val);
        if (size == 0) head = cur;
        else {
            Node *h = head;
            while (h->next) {
                h = h->next;
            }
            h->next = cur;
        }
        size++;
        return;
    }

    /** Add a node of value val before the index-th node in the linked list.
     * If index equals to the length of linked list,
     * the node will be appended to the end of linked list.
     * If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == 0) addAtHead(val);
        else if (size == index) addAtTail(val);
        else {
            Node *cur = head;
            while (--index) {
                cur = cur->next;
            }
            Node *temp = new Node(val);
            temp->next = cur->next;
            cur->next = temp;
            size++;
        }
        return;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        if (index == 0) head = head->next;
        else {
            Node *cur = head;
            while (--index) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        size--;
        return;
    }
};


//双向链表
class MyLinkedList {
public:
    struct Node {
        int val;
        Node *prev, *next;

        Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    };

    int size;
    Node *head, *tail;

    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size)
            return -1;
        Node *cur = head->next;
        while (--index >= 0) {
            cur = cur->next;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        cur->next = head->next;
        cur->prev = head;
        head->next->prev = cur;
        head->next = cur;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = new Node(val);
        cur->next = tail;
        cur->prev = tail->prev;
        tail->prev->next = cur;
        tail->prev = cur;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index == size) addAtTail(val);
        else if (index == 0) addAtHead(val);
        else {
            Node *cur = head->next;
            while (--index >= 0) {
                cur = cur->next;
            }
            Node *tmp = new Node(val);
            tmp->next = cur;
            tmp->prev = cur->prev;
            cur->prev->next = tmp;
            cur->prev = tmp;
            size++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) return;
        if (index == 0) {
            head = head->next;
        } else if (index == size - 1) {
            tail = tail->prev;
        } else {
            Node *cur = head->next;
            while (--index >= 0) {
                cur = cur->next;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            delete cur;
        }
        size--;
    }
};

//int main() {
//    MyLinkedList list;
//    list.addAtHead(5);
//    list.addAtIndex(1, 2);
//    std::cout << list.get(1) << std::endl;
//    list.addAtHead(6);
//    list.addAtTail(2);
//    std::cout << list.get(3) << std::endl;
//    list.addAtTail(1);
//    std::cout << list.get(5) << std::endl;
//    list.addAtHead(2);
//    std::cout << list.get(2) << std::endl;
//    list.addAtHead(6);
//}