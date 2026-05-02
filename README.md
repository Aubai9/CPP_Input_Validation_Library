# C++ Input Validation Library

**A robust C++ utility library for validating numeric ranges and dates while gracefully handling invalid user inputs.**

---

<img width="515" height="287" alt="image" src="https://github.com/user-attachments/assets/df8ff757-81b2-413b-9528-3cc8fc4d3767" />


---

## 🚀 Features
- **Numeric Range Validation:** Overloaded functions for `int` and `double`.
- **Date Range Validation:** Comprehensive checks using `clsDate`.
- **Input Sanitization:** Automatically handles non-numeric input errors (characters/symbols).
- **Static Utility Class:** No need to instantiate objects for validation logic.

## 🛠️ Project Structure
- `clsInputValidation`: Main class for input reading and validation.
- `clsDate`: Supporting class for date operations.
- `main.cpp`: Practical examples and test cases.

## 💻 Usage Example
```cpp
// Validate if a number is between 1 and 10
int num = clsInputValidation::ReadIntNumberBetween(1, 10, "Invalid! Enter 1-10: ");

// Check if a date is valid
bool valid = clsInputValidation::Is_Valid_Date(clsDate(35, 12, 2024));
```
📋 Available Functions
-IsNumberBetween(n1, n2, n3)
-IsDateBetween(date, from, to)
-ReadIntNumber(errorMessage)
-ReadDbNumber(errorMessage)
-Is_Valid_Date(dateObject)
