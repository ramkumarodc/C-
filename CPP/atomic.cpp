#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

//std::atomic<int> counter(0);
int counter =0;

void incrementCounter(int iterations, int id) {
    for (int i = 0; i < iterations; ++i) 
    {
        //cout<<"thread:"<<id<<"-"<<counter.load()<<endl;
        //counter.fetch_add(1, std::memory_order_relaxed);
        int tmp = counter+1;
        counter = tmp;
    }
}

int main() {
    const int numThreads = 4;
    const int iterationsPerThread = 10;

    std::thread threads[numThreads];

    // Launch threads to increment the counter concurrently
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(incrementCounter, iterationsPerThread,i+1);
    }

    // Wait for all threads to finish
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    // Print the final value of the counter
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}
