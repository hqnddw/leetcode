//
// Created by lwl on 2020/8/15.
//

#include <condition_variable>
#include <thread>
#include <mutex>
#include <queue>
#include <exception>
template<typename T>
class BlockQueue {
public:
    BlockQueue(int capacity = -1) : capacity(capacity) {}

    size_t getSize() {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue.size();
    }

    void push(const T &value) {
        std::unique_lock<std::mutex> lock(mutex_);
        if (hasCapacity()) {
            while (queue.size() >= capacity) {
                cv_noFull.wait(lock);
            }
        }
        queue.push(value);
        cv_noEmpty.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (queue.empty()){
            cv_noEmpty.wait(lock);
        }
        T tmp = queue.front();
        queue.pop();
        cv_noFull.notify_one();
        return tmp;
    }


    bool empty() {
        std::unique_lock<std::mutex> lock(mutex_);
        return queue.empty();
    }

    bool full() {
        if (!hasCapacity()) return false;
        std::unique_lock<std::mutex> lock(mutex_);
        return queue.size() >= capacity;
    }

    bool hasCapacity() {
        return capacity > 0;
    }

private:
    int capacity;
    std::condition_variable cv_noFull;
    std::condition_variable cv_noEmpty;
    std::mutex mutex_;
    std::queue<T> queue;
};