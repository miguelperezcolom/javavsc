#include <iostream>
#include <chrono>


void test(int i);

int main() {
    std::cout << "Hello, World!" << std::endl;


    for (int i = 0; i < 1000; i++) {
        test(i);
    }



    return 0;
}


void test(int pos) {
    auto start = std::chrono::high_resolution_clock::now();

    // operation to be timed ...

    for (int i = 0; i < 10000; i++) {
        i++;
    }


    auto finish = std::chrono::high_resolution_clock::now();

    std::cout << "iteration "
              << pos << " took " <<
              std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count()
              << "ns\n";

}