/*
    Created by Ritabrata, 14/12/2024
*
*/

// mutex.cpp
/*
    This file contains the implementation of mutex in order to lock and unlock a shared resources,
    that is access by two threads. If mutual exclusion is not implemented, it will result to unexpected
    result as multiple threads are accessing same resource.
*/

// C++ program to illustrate the thread synchronization using mutex
#include <iostream>
#include <thread>

using namespace std;

// import mutex from C++ standard library
#include <mutex>

// Create object for mutex
mutex mtx;

// Shared resource
int number = 0;

// function to increment the number
void increment(){
    
    // Lock the thread using lock
    mtx.lock();
    
    // increment number by 1 for 1000000 times
    for(int i=0; i<1000000; i++){
        number++;
    }
    
    // Release the lock using unlock()
    mtx.unlock();
}

int runMutex()
{
    // Create thread t1 to perform increment()
    thread t1(increment);
    
    // Create thread t2 to perform increment()
    thread t2(increment);
    
    // Start both threads simultaneously
    t1.join();
    t2.join();
    
    // Print the number after the execution of both threads
    std::cout<<"Number after execution of t1 and t2 is "<<number<<endl;
    
    return 0;
}
