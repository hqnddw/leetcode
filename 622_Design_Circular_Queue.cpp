//
// Created by hqnddw on 2019/7/3.
//
#include <vector>

using namespace std;

class MyCircularQueue {
public:
    vector<int> q;
    int front_point;
    int tail_point;
    int size;

    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        q.resize(k);
        front_point = -1;
        tail_point = -1;
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;

        if (isEmpty())
            front_point = 0;
        tail_point = (tail_point + 1) % size;
        q[tail_point] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
//        if (front_point == tail_point) {
//            front_point = tail_point = -1;
//            return true;
//        }
        front_point = (front_point + 1) % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return q[front_point];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return q[tail_point];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front_point == tail_point;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail_point + 1) % size == front_point;
    }
};
