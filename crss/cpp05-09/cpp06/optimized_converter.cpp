// optimized_converter.cpp
// Learning file — NOT part of the submission.
//
// Compares two approaches to overflow checking in ScalarConverter::convert().
// Compile standalone: c++ -std=c++98 -Wall -Wextra optimized_converter.cpp -o opt

#include <cfloat>
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// ─────────────────────────────────────────────────────────────────────────────
// APPROACH 1 (current submission): independent checks
//
//   Each type checks its own range against the parsed double.
//   Pro: self-contained, easy to read in isolation, evaluator-friendly.
//   Con: slightly repetitive.
// ─────────────────────────────────────────────────────────────────────────────
void convert_independent(double d) {
  std::cout << "[independent]" << std::endl;

  bool float_overflow = (d > static_cast<double>(FLT_MAX) ||
                         d < -static_cast<double>(FLT_MAX));

  bool int_overflow = (d > static_cast<double>(INT_MAX) ||
                       d < static_cast<double>(INT_MIN));

  bool char_overflow = (d < 0 || d > 127);

  // char
  std::cout << "char:   ";
  if (char_overflow)
    std::cout << "impossible" << std::endl;
  else {
    char c = static_cast<char>(d);
    if (!std::isprint(static_cast<unsigned char>(c)))
      std::cout << "Non displayable" << std::endl;
    else
      std::cout << "'" << c << "'" << std::endl;
  }

  // int
  std::cout << "int:    ";
  if (int_overflow)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(d) << std::endl;

  // float
  std::cout << "float:  ";
  if (float_overflow)
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(d) << "f" << std::endl;

  // double always valid at this point
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// APPROACH 2 (optimized): cascade checks
//
//   Exploits the fact that the type ranges nest:
//     double (~±1.8e308) ⊃ float (~±3.4e38) ⊃ int (~±2.1e9) ⊃ char (0–127)
//
//   So float overflow implies int overflow, and int overflow implies char
//   overflow. Each check short-circuits on the result of the one above it.
//
//   Pro: no redundant comparisons, mathematically expressive.
//   Con: the dependency between checks is non-obvious — evaluators may ask why
//        int_overflow references float_overflow.
// ─────────────────────────────────────────────────────────────────────────────
void convert_cascade(double d) {
  std::cout << "[cascade]" << std::endl;

  // float: largest subtype — check first
  bool float_overflow = (d > static_cast<double>(FLT_MAX) ||
                         d < -static_cast<double>(FLT_MAX));

  // int: if float already overflowed, int definitely does too (FLT_MAX >> INT_MAX)
  bool int_overflow = float_overflow ||
                      (d > static_cast<double>(INT_MAX) ||
                       d < static_cast<double>(INT_MIN));

  // char: if int already overflowed, char definitely does too (INT_MAX >> 127)
  bool char_overflow = int_overflow || (d < 0 || d > 127);

  // char
  std::cout << "char:   ";
  if (char_overflow)
    std::cout << "impossible" << std::endl;
  else {
    char c = static_cast<char>(d);
    if (!std::isprint(static_cast<unsigned char>(c)))
      std::cout << "Non displayable" << std::endl;
    else
      std::cout << "'" << c << "'" << std::endl;
  }

  // int
  std::cout << "int:    ";
  if (int_overflow)
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(d) << std::endl;

  // float
  std::cout << "float:  ";
  if (float_overflow)
    std::cout << "impossible" << std::endl;
  else
    std::cout << std::fixed << std::setprecision(1)
              << static_cast<float>(d) << "f" << std::endl;

  // double always valid at this point
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// Helper: parse string to double
// ─────────────────────────────────────────────────────────────────────────────
bool parse(std::string const &s, double &out) {
  std::stringstream ss(s);
  ss >> out;
  return !ss.fail() && ss.eof();
}

int main(void) {
  const char *cases[] = {
    "42",           // normal int
    "3.14",         // normal double
    "97",           // 'a'
    "3000000000",   // int overflow, float fine
    "1e100",        // float overflow, double fine
    "1e400",        // double overflow (parse fails — both print nothing)
    NULL
  };

  for (int i = 0; cases[i] != NULL; ++i) {
    double d;
    std::cout << "=== " << cases[i] << " ===" << std::endl;
    if (!parse(cases[i], d)) {
      std::cout << "parse failed — all impossible" << std::endl;
    } else {
      convert_independent(d);
      std::cout << std::endl;
      convert_cascade(d);
    }
    std::cout << std::endl;
  }
  return 0;
}
