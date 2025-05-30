# Compiler Optimization Benchmark

This project demonstrates the performance impact of various **C++ compiler optimization levels** using a simple program that:

* Allocates and initializes a large array.
* Calculates the sum of its elements.
* Measures and prints the execution time.

## 🧠 Program Overview

The program creates an array of 1,000,000 integers, initializes it with values from `0` to `999999`, and computes their sum. It measures how long the summation takes and prints the result along with the elapsed time to both standard output and a file (`results.txt`).

## ⚙️ Compilation and Optimization Levels

You can compile the program using `g++` with different optimization levels:

### `-O0` (No Optimization)

* The slowest version.
* Code is compiled almost exactly as written.
* Minimal compiler analysis or performance improvement.

### `-O1` (Basic Optimization)

* Performs simple optimizations like removing redundant operations and function inlining.
* Noticeable improvement over `-O0`.

### `-O2` (Moderate Optimization)

* Enables more aggressive optimizations such as:

  * Loop unrolling
  * Dead code elimination
  * Improved register allocation
* Significantly faster than `-O1`.

### `-O3` (Aggressive Optimization)

* Includes all `-O2` optimizations plus:

  * Vectorization
  * Aggressive inlining
* Usually the fastest, though often only marginally better than `-O2` for simple programs like this.

## ⚡ Why Are `-O2` and `-O3` So Much Faster?

* **Loop unrolling**: Fewer loop control instructions per element.
* **Instruction reordering**: More efficient CPU execution scheduling.
* **Cache-aware code generation**: Better memory access patterns.
* **Function inlining**: Reduces function call overhead.
* **Dead code elimination**: Removes unused or redundant operations.

## 🧪 Why Does Runtime Vary?

Even when running the same binary multiple times, timing results can vary due to:

* OS **CPU scheduling** and current system load.
* Background processes interfering with execution.
* Dynamic CPU frequency scaling (e.g., **Intel Turbo Boost**).
* **Disk I/O** variation when writing to `results.txt`.

## 🧾 Example Output

```bash
Sum: 499999500000
Elapsed time: 0.000301029 seconds
```

## 🛠️ How to Run

Compile and run with a specific optimization level:

```bash
g++ -std=c++20 main.cpp -O2 -o main_O2
./main_O2
```

Compare the elapsed times for different optimization flags: `-O0`, `-O1`, `-O2`, `-O3`.
