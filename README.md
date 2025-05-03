#Libili445@gmail.com
# SquareMat

A C++ project that implements a square matrix class (`SquareMat`) supporting a wide range of arithmetic, comparison, and matrix operations through operator overloading. The code features complete memory management without STL and includes an extensive suite of unit tests using Doctest.

---

## Table of Contents

- [Project Overview](#project-overview)
- [File Structure](#file-structure)
- [Build & Run Instructions](#build--run-instructions)
- [Usage Example](#usage-example)
- [Testing](#testing)
- [Dependencies](#dependencies)

---

## Project Overview

This project defines and implements a `SquareMat` class for creating and manipulating square matrices of arbitrary size. The class supports:

- Arithmetic operations: `+`, `-`, `*`, `/`, `%`, scalar operations
- Matrix power `^` and transpose `~`
- Determinant calculation `!`
- Increment/decrement: `++`, `--`
- Comparison: `==`, `!=`, `<`, `<=`, `>`, `>=`
- Input/output via `operator<<`
- Assignment operations: `+=`, `-=`, `*=`, `/=`, `%=`

The implementation handles all memory manually (no STL containers) and ensures exception safety and bounds checking.

---

## File Structure

| File            | Description |
|-----------------|-------------|
| `SquareMat.hpp` | Header file defining the `SquareMat` class interface. |
| `SquareMat.cpp` | Full implementation of the class, including operator overloads and utilities. |
| `main.cpp`      | Sample main function demonstrating the use of `SquareMat`. |
| `test.cpp`      | Doctest-based unit tests for validating the matrix operations. |
| `Makefile`      | Build file for compiling and running the project and tests. |

---

## Build & Run Instructions

### Compile and run main program:

```bash
make run
```

### Compile and run tests:

```bash
make test
```

### Clean build artifacts:

```bash
make clean
```

---

## Usage Example

```cpp
SquareMat A(3), B(3);
A[0][0] = 1; A[1][1] = 2; A[2][2] = 3;
B[0][0] = 3; B[1][1] = 2; B[2][2] = 1;

SquareMat C = A + B;
std::cout << "A + B:\n" << C;

std::cout << "Transpose of A:\n" << ~A;
std::cout << "Determinant of B: " << !B << std::endl;
```

You can also perform compound operations like:

```cpp
A *= B;
A %= 5;
A ^= 2;
```

And access matrix elements directly with `A[row][col]`.

---

## Testing

Unit tests are written using [Doctest](https://github.com/doctest/doctest) and are included in the `test.cpp` file.

Test coverage includes:

- Constructor and copy semantics
- Arithmetic and assignment operators
- Scalar operations
- Comparison operators
- Transpose and determinant
- Exception handling and boundary checks
- Output formatting

To run tests:

```bash
make test
```

---

## Dependencies

- **C++11 or newer** (tested with `g++`)
- **Doctest** header (already included in `test.cpp`, no external install required)
