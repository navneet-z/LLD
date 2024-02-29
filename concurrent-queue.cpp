#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class ConcurrentQueue {
  private:
    vector<int> queue;
    std::mutex mtx; // Mutex for synchronization

  public:
    void push(int value) {
      std::lock_guard<std::mutex> lock(mtx); // Lock the mutex during the operation
      queue.push_back(value);
    }

    void pop() {
      std::lock_guard<std::mutex> lock(mtx);
      if (!queue.empty()) {
        queue.pop_back();
      }
    }

    int size() {
      std::lock_guard<std::mutex> lock(mtx);
      return queue.size();
    }
};

int main() {
  ConcurrentQueue* queue = new ConcurrentQueue();

  // make this concurrent
  vector<std::thread> threads;

  for (int i = 0; i < 1000; i++) {
    threads.emplace_back([&]() {
      queue->push(i);
    });
  }

  for (auto& thread : threads) {
    thread.join();
  }

  cout << "Queue size: " << queue->size() << endl;

  delete queue;

  return 0;
}
