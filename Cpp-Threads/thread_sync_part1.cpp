/*

thread_sync_part1.cpp

Developed by Ritabrata, 2024

REQUIREMENT : 
Find the sum of all odd and even numbers from 1 to 1900000000

Method 1 : Without threading, create two APIs and then find the total time taken
Method 2 : Create 2 threads which will execute the two APIs 
            parallely and will reduce the computation time

*/


#include <iostream> 
#include <thread>
#include <chrono>
#include <cstdint>

std::uint64_t OddSum = 0, EvenSum = 0;

void findOdd(std::uint64_t start, std::uint64_t end) {
    for(std::uint64_t i = start; i <= end; i++) {
        if((i & 1) == 1) {
            OddSum += i;
        }
    }
}

void findEven(std::uint64_t start, std::uint64_t end) {
    for(std::uint64_t i = start;i <= end; i++) {
        if((i & 1) == 0) {
            EvenSum += i;
        }
    }
}

int runThreadSyncPart1() {
    std::uint64_t lower_limit = 0, upper_limit = 1900000000;
    auto startTime = std::chrono::high_resolution_clock::now();

    std::thread t1(findEven, lower_limit, upper_limit);
    std::thread t2(findOdd, lower_limit, upper_limit);

    t1.join();
    t2.join();

    // findOdd(lower_limit, upper_limit);
    // findEven(lower_limit, upper_limit);    

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    std::cout << "OddSum is : " << OddSum << '\n';
    std::cout << "EvenSum is : " << EvenSum << '\n';

    std::cout << "Total time takes : " << duration.count()/1000000 << std::endl;   

    return 0;
}
