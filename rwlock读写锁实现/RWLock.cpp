//
// Created by hqnddw on 2020/9/9.
//
#include "RWLock.h"

RWLock::RWLock() :
        read_count(0),
        write_count(0),
        is_writing(false) {}

void RWLock::read_lock() {
    unique_lock<mutex> guard(mutex_);
    read_cv.wait(guard, [=] { return write_count == 0; });
    ++read_count;
}

void RWLock::read_unlock() {
    unique_lock<mutex> guard(mutex_);
    --read_count;
    if (read_count == 0 && write_count > 0)
        write_cv.notify_one();
}

void RWLock::write_lock() {
    unique_lock<mutex> guard(mutex_);
    ++write_count;
    write_cv.wait(guard, [=] { return read_count == 0 && !is_writing; });
    is_writing = true;
}

void RWLock::write_unlock() {
    unique_lock<mutex> guard(mutex_);
    write_count--;
    if (write_count == 0) {
        read_cv.notify_all();
    } else {
        write_cv.notify_one();
    }
}