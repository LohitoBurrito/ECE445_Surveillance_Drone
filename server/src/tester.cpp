#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
bool done = false;  // Flag to indicate when the producer is done.

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        std::lock_guard<std::mutex> lock(mtx);
        q.push(i);
        cv.notify_one(); // Notify the consumer
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        done = true;
        cv.notify_one(); // Notify the consumer that production is done
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !q.empty() || done; });

        while (!q.empty()) {
            int item = q.front();
            q.pop();
            std::cout << "Consumed: " << item << std::endl;
        }

        if (done && q.empty()) {
            break; // Exit if production is done and queue is empty
        }
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    return 0;
}
