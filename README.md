
---

# 📚 Simple Calculator with Unit Testing (C++ + Google Test)

A simple calculator application designed for practicing unit testing using **Google Test (gtest)** in C++. This project uses **CMake** and **Ninja** for cross-platform compatibility and ease of building.

---

## ✨ Features

- 🧮 **Arithmetic operations**: Addition, subtraction, multiplication, and division.
- ✅ **Unit tests**: Implemented with Google Test.
- 🔧 **CMake integration**: Easy configuration and build process.
- ⚙️ **Automatic file detection**: Automatically includes files from `src/` and `test/`.
- 🚀 **Google Test auto-download**: Automatically clones and integrates Google Test if not present.
- 🌍 **Cross-platform support**: Works on Linux, macOS, and Windows.

---

## 🛠️ Prerequisites

Make sure the following tools are installed on your system:

- **CMake** (minimum version 3.10)
- **Ninja** build system
- **C++17-compatible compiler**:
  - GCC (Linux)
  - Clang (Linux/macOS)
  - MSVC (Windows)
- **Git** (for cloning the repository and dependencies)

---

## 🚀 Getting Started

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/JoaoBMC/SimpleCalculator.git
cd SimpleCalculator
```

### 2️⃣ Clone the Repository Gtest
add Gtest to the repository for Cmake to find it
```bash
https://github.com/google/googletest.git
```

### 3️⃣ Configure the Build
Create a `build` directory and configure the project using CMake with Ninja:
```bash
mkdir build && cd build
cmake -G Ninja ..
```

### 4️⃣ Build the Project
Run the build process:
```bash
cmake --build .
```

### 5️⃣ Run the Tests
Execute the tests with:
```bash
ctest
```

Or run the test executable directly:
```bash
./SimpleCalculator_tests
```

---
### 🧮 Running the Calculator
To run the calculator, execute the main application:
```bash
./SimpleCalculator_main
```
After running, the calculator will display a help interface. Enter the desired operations, such as addition or subtraction, as prompted in the example below.

```bash
=========================== HELP ===========================
USAGE:
        Calculadora_main.exe {OPERATION} {NUMBER 1} {NUMBER 2}

OPERATIONS:
        -sm     Summation Operation
        -sb     Subtraction Operation
        -ml     Multiplication Operation
        -dv     Division Operation
        -hp     Display Help

EXAMPLES:
        Calculadora_main.exe -sm 10 5   => Output: 10 + 5 = 15
        Calculadora_main.exe -dv 10 0   => Output: Error: Division by zero
===========================================================
```

---
## 📂 Project Structure

```plaintext
simple-calculator-gtest/
├── CMakeLists.txt         # Main CMake configuration file
├── src/                   # Source code
│   ├── operations.cpp     # Calculator implementation
│   └── main.cpp           # Main entry point
├── inc/                   # Header files
│   └── operations.h       # Calculator header
├── test/                  # Unit tests
│   └── calculator_test.cpp # Google Test cases for calculator
├── googletest/            # (Optional) Google Test sources (auto-downloaded if missing)
├── build/                 # Build output directory (created during configuration)
└── README.md              # Project documentation
```

---

## 🔧 Configurations

The `CMakeLists.txt` file automates much of the setup:

1. **Google Test Integration**:
   - If `googletest/` is not present, it will be automatically cloned from the official GitHub repository.

2. **Source and Test File Management**:
   - Files in `src/` are treated as either library or main application code.
   - Files in `test/` are automatically included as unit tests.

3. **Compiler Warnings**:
   - The project enables strict warnings (`-Wall -Wextra`) for high-quality code.

---

## 🏗️ Extending the Project

Feel free to expand the calculator's functionality:
1. Add advanced operations (e.g., trigonometric functions, logarithms).
2. Enhance error handling for invalid inputs.
3. Include additional unit tests for edge cases.

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).

---

## 🤝 Contributing

Contributions are welcome! To contribute:
1. Fork this repository.
2. Create a feature branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m "Add feature"`).
4. Push the branch (`git push origin feature-name`).
5. Open a pull request.

---

## 🙏 Acknowledgments

- [Google Test (gtest)](https://github.com/google/googletest) for the testing framework.
- The open-source community for making this project possible.

---
