#include <iostream>

extern int runConcurrentHelloWorld();
extern int runMutex();
extern int runThreadCreation();
extern int runThreadWait();
extern int runThreadSyncPart1();

int main() {
    int ret = 0;
    const std::string prefix = std::string(10, '-') + " ";

    std::cout << prefix << "runConcurrentHelloWorld BEGIN\n";
    ret = runConcurrentHelloWorld();
    std::cout << prefix << "runConcurrentHelloWorld END\n\n";
    if (ret) return ret;

    std::cout << prefix << "runMutex BEGIN\n";
    ret = runMutex();
    std::cout << prefix << "runMutex END\n\n";
    if (ret) return ret;

    std::cout << prefix << "runThreadCreation BEGIN\n";
    ret = runThreadCreation();
    std::cout << prefix << "runThreadCreation END\n\n";
    if (ret) return ret;

    std::cout << prefix << "runThreadWait BEGIN\n";
    ret = runThreadWait();
    std::cout << prefix << "runThreadWait END\n\n";
    if (ret) return ret;

    std::cout << prefix << "runThreadSyncPart1 BEGIN\n";
    ret = runThreadSyncPart1();
    std::cout << prefix << "runThreadSyncPart1 END\n";
    if (ret) return ret;

    return ret;
}
