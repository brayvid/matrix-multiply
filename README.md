# MatrixMultiply
Multiplies two user-inputted matrices. 

This program is written in modern C++ and features dynamically sized matrices (using `std::vector`), input validation, and a cache-optimized loop structure for faster matrix computation.

## Features
* **Dynamic Sizing**: Handles matrices of any size.
* **Cache-Friendly**: Uses an optimized `i, k, j` loop order for significantly faster execution times on large matrices.
* **Precision Handling**: Automatically cleans up floating-point precision errors (rounds values smaller than `1e-8` to `0`).

## Prerequisites
To run this code, you need a C++ compiler installed on your system (such as GCC, Clang, or MSVC) that supports C++11 or higher.

## How to Compile and Run

**1. Clone or download the repository**
Save the source code file as `matrix.cpp`.

**2. Open your terminal / command prompt**
Navigate to the folder where you saved `matrix.cpp`.

**3. Compile the code**
Run the following command to compile the program (the `-O3` flag is optional but recommended for maximum performance):
```bash
g++ -O3 -o matrix matrix.cpp
```

**4. Run the program**
* **Mac / Linux:**
  ```bash
  ./matrix
  ```
* **Windows:**
  ```cmd
  matrix.exe
  ```

## Example Usage

```text
Matrix multiplication:

Enter # rows and cols for matrix A (e.g., 2 3): 2 2
Enter # rows and cols for matrix B (e.g., 3 2): 2 2

Enter element (1, 1) of matrix A: 1
Enter element (1, 2) of matrix A: 2
...
```

**Example Output:**
```text
A = 
1       2
3       4

B = 
5       6
7       8

A*B = 
19      22
43      50
```

---

<p align="center">&copy; Copyright 2026 <a href="https://blakerayvid.com">Blake Rayvid</a>. All rights reserved.</p>