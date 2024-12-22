/**
    Created by Ritabrata, 22/12/2024
*/

#include <iostream> 
#include <thread>

using namespace std;

void print(){
    std::cout << "Hello world" << std::endl;
}

int main(){
    // Use lambda expression as a way to pass method to thread object 
    std::thread t([] {
        print();
    });
    /**
        std::thread t(print);
    */
    t.join();
    return 0;
}
