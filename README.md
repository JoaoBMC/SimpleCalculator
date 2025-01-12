Simple Calculator with Unit Testing (C++ + Google Test)
This project is a simple calculator designed to practice unit testing with Google Test (gtest) in C++. It uses CMake and Ninja to simplify the build process and ensure cross-platform compatibility.

Features
Basic arithmetic operations: addition, subtraction, multiplication, and division.
Automated unit tests with Google Test.
Automated download and integration of Google Test if not present.
Automatic file detection for src/, test/, and main.cpp.
Configured to work with C++17 and generate warnings for better code quality.
Prerequisites
To build and run the project, ensure you have the following tools installed:

CMake (minimum version 3.10)
Ninja (build system generator)
A C++17-compatible compiler:
GCC (Linux)
Clang (Linux/macOS)
MSVC (Windows)
Getting Started
Clone the Repository
bash
Copiar código
git clone https://github.com/yourusername/simple-calculator-gtest.git
cd simple-calculator-gtest
Build the Project
Create a build directory and navigate to it:

bash
Copiar código
mkdir build && cd build
Configure the project with CMake and specify the Ninja generator:

bash
Copiar código
cmake -G Ninja ..
Build the project:

bash
Copiar código
cmake --build .
Run the Tests
After building, execute the unit tests:

bash
Copiar código
ctest
Alternatively, you can run specific test executables, such as:

bash
Copiar código
./build/Calculator_tests
Project Structure
plaintext
Copiar código
simple-calculator-gtest/
├── CMakeLists.txt         # Main CMake configuration
├── src/
│   ├── calculator.cpp     # Calculator implementation
│   └── main.cpp           # Entry point for the application
├── inc/
│   └── calculator.h       # Calculator header file
├── test/
│   └── calculator_test.cpp # Unit tests for the calculator
├── googletest/            # (Optional) Google Test source (downloaded automatically if not found)
├── build/                 # Build output directory (created during configuration)
└── README.md              # Documentation
Notes on Configuration
The CMakeLists.txt file is designed to handle different situations automatically:

Google Test Download:

If the googletest/ directory is missing, the project will automatically clone it from the official GitHub repository.
Automatic File Detection:

All .cpp files in src/ are treated as library or main files.
Files in test/ are considered test files.
Warnings Enabled:

The -Wall -Wextra flags are added for better code quality.
Extending the Project
You can enhance the project by:

Adding more mathematical operations (e.g., exponentiation, logarithms).
Improving error handling.
Adding performance benchmarks.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Contributing
Feel free to submit issues or pull requests for improvements or bug fixes!

