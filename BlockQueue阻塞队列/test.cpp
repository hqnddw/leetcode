#include <iostream>
#include <thread>
#include "BlockQueue.cpp"

using namespace std;

typedef BlockQueue<int> TQueue;

void produce(TQueue &queue) {
    const int num = 9;
    for (int i = 0; i < num; ++i) {
        queue.push(i);
    }
}

void consume(TQueue &queue) {
    while (!queue.empty()) {
        int tmp = queue.pop();
        cout << this_thread::get_id() << " " << tmp << endl;
        std::this_thread::sleep_for(chrono::seconds(1));
    }
}


int main() {
    TQueue queue(2);
    std::thread t1(produce, std::ref(queue));
    std::thread t2(consume, std::ref(queue));
    std::thread t3(consume, std::ref(queue));
    t3.join();
    t2.join();
    t1.join();
    return 0;
}