#include <iostream>

extern int runIteratorMethods();
extern int runVectors();

int main() {
    int ret = 0;
    const std::string prefix = std::string(10, '-') + " ";

    std::cout << prefix << "runIteratorMethods BEGIN\n";
    ret = runIteratorMethods();
    std::cout << prefix << "runIteratorMethods END\n\n";
    if (ret) return ret;

    std::cout << prefix << "runVectors BEGIN\n";
    ret = runVectors();
    std::cout << prefix << "runVectors END\n";
    if (ret) return ret;

    return ret;
}
