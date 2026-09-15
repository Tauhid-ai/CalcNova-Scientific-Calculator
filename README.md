# CalcNova – Scientific Calculator

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue.svg" />
  <img src="https://img.shields.io/badge/Features-58-success.svg" />
  <img src="https://img.shields.io/badge/Platform-Windows-lightgrey.svg" />
  <img src="https://img.shields.io/badge/License-MIT-green.svg" />
</p>

CalcNova is a **console-based Scientific Calculator** developed in **C++17**. It provides a wide collection of mathematical, scientific, statistical, matrix, conversion, and number-property utilities through an easy menu-driven interface.

> **Current Version:** v1.0  
> **Total Features:** 58

---

## Features

### Basic Operations
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Modulus

### Scientific & Trigonometry
6. Power
7. Square Root
8. Natural Log
9. Log Base 10
10. Sin
11. Cos
12. Tan

### Other Operations
13. Percentage
14. PI Value
15. e Value
16. Absolute Value
17. Reciprocal
23. Factorial
24. Square
25. Cube
26. Exponential (e^x)

### History & Information
18. View History
19. Clear History
20. About
21. Help
22. Exit

### Answer & Memory
27. Show Previous Answer
28. Toggle Degree/Radian
29. Memory Store (MS)
30. Memory Recall (MR)
31. Memory Add (M+)
32. Memory Clear (MC)
33. Show Memory

### Advanced Calculators
34. Expression Calculator
35. Statistics Calculator

### Scientific Constants
36. Speed of Light (c)
37. Gravitational Constant (G)
38. Planck Constant (h)
39. Avogadro Constant (NA)
40. Electron Charge (e)

### Number & Conversion Utilities
41. GCD & LCM Calculator
42. Binary <-> Decimal Converter
43. Unit Converter
44. Number System Converter
45. Combinations & Permutations (nCr / nPr)

### Equation & Matrix Tools
46. Quadratic Equation Solver
47. Matrix Calculator
48. Determinant Calculator

### Number Property Checkers
49. Prime Number Checker
50. Armstrong Number Checker
51. Palindrome Number Checker
52. Perfect Number Checker
53. Strong Number Checker
54. Automorphic Number Checker
55. Harshad Number Checker

### Number & Factor Utilities
56. Fibonacci Series Generator
57. Divisor / Factor Finder
58. Prime Factors Finder

---

## Highlights

- Clean and menu-driven console interface
- Input validation and error handling
- Persistent calculation history using `history.txt`
- Previous-answer support
- Memory operations similar to a physical calculator
- Degree/Radian mode for trigonometric calculations
- Expression evaluation
- Statistics and matrix utilities
- Number-system and unit conversions
- Mathematical constant utilities
- Number-property checkers
- Professional welcome and exit screens

---

## Technologies Used

- **C++**
- **C++17**
- **C++ Standard Library**
- **File Handling**
- **Vectors**
- **Mathematical Functions**
- **Object-oriented / modular function-based program structure**

---

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/Tauhid-ai/CalcNova-Scientific-Calculator.git
```

### 2. Open the project folder

```bash
cd CalcNova-Scientific-Calculator
```

### 3. Compile

```bash
g++ -std=c++17 main.cpp -o CalcNova.exe
```

### 4. Run

**Windows PowerShell:**

```powershell
.\CalcNova.exe
```

---

## Example

### Prime Factors Finder

```text
Enter your choice: 58

PRIME FACTORS FINDER

Enter a positive integer: 60

Prime Factors of 60:
2 2 3 5

Total prime factors = 4
```

### Fibonacci Series

```text
Enter your choice: 56

FIBONACCI SERIES GENERATOR

Enter number of terms: 10

Fibonacci Series:
0 1 1 2 3 5 8 13 21 34

Total terms = 10
```

---

## Project Structure

```text
CalcNova-Scientific-Calculator/
│
├── main.cpp
├── main_backup.cpp
├── CalcNova.exe
├── history.txt
├── LICENSE
├── README.md
└── .gitignore
```

> `CalcNova.exe` may be generated locally after compilation.

---

## History

CalcNova stores calculation history in:

```text
history.txt
```

The application also provides options to view and clear saved history.

---

## Error Handling

CalcNova validates common invalid inputs such as:

- Division by zero
- Invalid square-root input
- Invalid logarithm input
- Invalid numeric input
- Invalid menu choices
- Invalid number-system input
- Invalid matrix dimensions
- Invalid number-property inputs

---

## Objective

The main objective of CalcNova is to build a practical **C++ console application** while applying programming concepts such as:

- Functions
- Loops
- Conditional statements
- Switch-case
- Vectors
- File handling
- Mathematical algorithms
- Input validation
- Modular programming

---

## Future Improvements

Possible future versions may include:

- Graphical User Interface (GUI)
- More advanced scientific functions
- Improved expression parsing
- More unit categories
- Exportable calculation history
- Additional statistical tools
- Web-based version of CalcNova

---

## Developer

**Tauhid Alam Ansari (T. A. Ansari)**

- C++ Developer
- B.Tech Student
- Scientific Calculator Project Creator

GitHub: **Tauhid-ai**

---

## License

This project is licensed under the **MIT License**.

---

<p align="center">
  If you like this project, don't forget to ⭐ the repository.
</p>
