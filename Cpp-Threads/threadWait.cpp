/**
    Created by Ritabrata, 22/12/2024
*/

#include <iostream>
#include <thread>

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
class thread_guard
{
 std::thread& t;
public:
 explicit thread_guard(std::thread& t_):
 t(t_) {

 }
 ~thread_guard()
 {
 if(t.joinable())
    {
        t.join();
    }
 }
 thread_guard(thread_guard const&)=delete;
 thread_guard& operator=(thread_guard const&)=delete;
};
int main()
{
 int some_local_state=0;
 func my_func(some_local_state);
 std::thread t(my_func);
 thread_guard g(t);
 std::cout << some_local_state << endl;
 return 0;
} 
