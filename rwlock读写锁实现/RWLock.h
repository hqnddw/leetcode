//
// Created by hqnddw on 2020/9/9.
//

#ifndef LEETCODE_RWLOCK_H
#define LEETCODE_RWLOCK_H

#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

class RWLock {
public:
    RWLock();

    virtual ~RWLock() = default;

    void read_lock();

    void read_unlock();

    void write_lock();

    void write_unlock();

private:
    condition_variable read_cv;
    condition_variable write_cv;
    atomic<int> read_count;
    atomic<int> write_count;
    atomic<bool> is_writing;
    mutex mutex_;
};

#endif //LEETCODE_RWLOCK_H
