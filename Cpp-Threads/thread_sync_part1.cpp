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
#include <algorithm>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum = 0, EvenSum = 0;

void findOdd(ull start, ull end){
    for(ull i = start; i <= end; i++){
        if((i & 1) == 1){
            OddSum += i;
        }
    }
}

void findEven(ull start, ull end){
    for(ull i = start;i <= end; i++){
        if((i & 1) == 0){
            EvenSum += i;
        }
    }
}  
int main(){

    ull lower_limit = 0, upper_limit = 1900000000;
    auto startTime = high_resolution_clock::now();

    std::thread t1(findEven, lower_limit, upper_limit);
    std::thread t2(findOdd, lower_limit, upper_limit);

    t1.join();
    t2.join();

    // findOdd(lower_limit, upper_limit);
    // findEven(lower_limit, upper_limit);    

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum is : " << OddSum << endl;
    cout << "EvenSum is : " << EvenSum << endl;

    cout << "Total time takes : " << duration.count()/1000000 << endl;   

    return 0;
}
