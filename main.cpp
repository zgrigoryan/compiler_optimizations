/*
Write a simple program with a loop that 
sums elements in an array. Compile it with different 
optimization levels (-O0, -O1, -O2, -O3) and measure execution time. 
Use objdump or godbolt.org to analyze the generated assembly 
and observe the differences in the number of instructions and 
loop structure. Understand how different compiler 
optimization levels impact performance and code size
*/
 
#include <iostream>
#include <chrono>
#include <memory>
#include <fstream>

int main(){
    std::unique_ptr<int[]> arr(new int[1000000]);
    for (int i = 0; i < 1000000; ++i) {
        arr[i] = i;
    }
    long long sum = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000000; ++i) {
        sum += arr[i];
    }   
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Elapsed time: " << elapsed.count() << " seconds\n";
    return 0;
}