//
// Created by lwl on 2020/8/26.
//
#include <functional>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <thread>
#include <queue>

class ThreadPool {
public:
    static const int threadPoolSize = 3;
    enum taskPriority {
        level0, level1, level2
    };
    typedef std::function<void()> task;
    typedef std::pair<taskPriority, task> taskPair;

    ThreadPool();

    ~ThreadPool();

    void start();

    void stop();

    void addTask(const task &);

    void addTask(const taskPair &);

private:
    ThreadPool(const ThreadPool &);

    ThreadPool &operator=(const ThreadPool &);

    struct taskPriorityCmp {
        bool operator()(taskPair t1, taskPair t2) {
            return t1.first > t2.first;
        }
    };

    typedef std::vector<std::thread *> threads;
    typedef std::priority_queue<taskPair, std::vector<taskPair>, taskPriorityCmp> tasks;
    threads m_threads;
    tasks m_tasks;

    void threadLoop();

    task take();

    std::mutex m_mutex;
    std::condition_variable m_cond;
    bool m_isStarted;
};

ThreadPool::ThreadPool()
        : m_mutex(), m_cond(), m_isStarted(false) {

}

ThreadPool::~ThreadPool() {
    if (m_isStarted)
        stop();
}

void ThreadPool::start() {
    m_isStarted = true;
    m_threads.reserve(threadPoolSize);
    for (int i = 0; i < threadPoolSize; ++i) {
        m_threads.emplace_back(new std::thread(std::bind(&ThreadPool::threadLoop, this)));
    }
}

void ThreadPool::stop() {
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_isStarted = false;
        m_cond.notify_all();
    }
    for (threads::iterator it = m_threads.begin(); it != m_threads.end(); it++) {
        (*it)->join();
        delete *it;
    }
}

void ThreadPool::threadLoop() {
    while (m_isStarted) {
        task task1 = take();
        if (task1)
            task1();
    }
}

void ThreadPool::addTask(const task &task) {
    std::unique_lock<std::mutex> lock(m_mutex);
    taskPair taskPair1(level2, task);
    m_tasks.push(taskPair1);
    m_cond.notify_one();
}

void ThreadPool::addTask(const taskPair &taskPair) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_tasks.push(taskPair);
    m_cond.notify_one();
}

ThreadPool::task ThreadPool::take() {
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_tasks.empty() && m_isStarted)
        m_cond.wait(lock);
    task task1;
    if (!m_tasks.empty() && m_isStarted){
        task1 = m_tasks.top().second;
        m_tasks.pop();
    }
    return task1;
}



