/**
    Created by Ritabrata, 22/12/2024
*/

#include <thread>
#include <iostream>
using namespace std;

struct func
{
    int& i;
    func(int& i_) : i(i_) {}
    void operator()()   // Overloaded function call operator
    {
        for (unsigned j = 0; j < 10; ++j)
        {
            i++;
        }
    }
};

int main() {
    int some_local_state = 20;
    func my_func(some_local_state);
    std::thread my_thread(my_func); // Call functor using a thread to execute in a separate process

    // Join the thread to ensure it completes before accessing the shared state
    my_thread.join(); // If not used, program will give Signal abort message varying on multiple run attempts

    std::cout << some_local_state << endl; // Prints 30

    return 0;
}
