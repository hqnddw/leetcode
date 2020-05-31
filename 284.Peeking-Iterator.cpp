//
// Created by yida on 2020/5/23.
//


/* Below is the interface for Iterator, which is already defined for you.
DO NOT** modify the interface for Iterator.*/
#include <vector>

using namespace std;

class Iterator {
public:
    struct Data;
    Data *data;

    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    bool hasNext() const;


    Iterator(const vector<int> &nums);
};


class PeekingIterator : public Iterator {
public:
    int m_next;
    bool m_hasnext;

    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return m_next;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int t = m_next;
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
        return t;
    }

    bool hasNext() const {
        return m_hasnext;
    }
};