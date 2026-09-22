#!/usr/bin/env bash
GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
RESET='\033[0m'

PROGRAM="./convert"
PASS_COUNT=0
FAIL_COUNT=0

if [ ! -x "$PROGRAM" ]; then
  echo "FAIL: $PROGRAM not found or not executable"
  echo "Run: make"
  exit 1
fi

run_test() {
  local name="$1"
  local input="$2"

  if "$PROGRAM" "$input" > /dev/null 2>&1; then
    printf "${GREEN}PASS${RESET}: %s\n" "$name"
    PASS_COUNT=$((PASS_COUNT + 1))
  else
    printf "${RED}FAIL${RESET}: %s\n" "$name"
    FAIL_COUNT=$((FAIL_COUNT + 1))
  fi
}

run_expected_failure() {
  local name="$1"
  shift

  if "$PROGRAM" "$@" > /dev/null 2>&1; then
    printf "${RED}FAIL${RESET}: %s\n" "$name"
    FAIL_COUNT=$((FAIL_COUNT + 1))
  else
    printf "${GREEN}PASS${RESET}: %s\n" "$name"
    PASS_COUNT=$((PASS_COUNT + 1))
  fi
}

# Shows actual output — useful for manual verification of overflow/impossible cases
run_output() {
  local name="$1"
  local input="$2"
  printf "${CYAN}OUT${RESET} [%s] => \"%s\":\n" "$name" "$input"
  "$PROGRAM" "$input" 2>&1 | sed 's/^/    /'
  echo
}

echo "Character literals"

run_test "character a" "a"
run_test "character A" "A"
run_test "quoted character a" "'a'"
run_test "quoted character A" "'A'"
run_test "character +" "+"
run_test "character -" "-"
run_test "character ." "."
run_test "character *" "*"

echo
echo "Integer literals"

run_test "zero" "0"
run_test "one" "1"
run_test "positive integer" "42"
run_test "negative integer" "-42"
run_test "explicit positive integer" "+42"
run_test "ASCII A" "65"
run_test "ASCII DEL" "127"
run_test "character overflow 128" "128"
run_test "integer maximum" "2147483647"
run_test "integer minimum" "-2147483648"
run_test "integer overflow" "2147483648"
run_test "integer underflow" "-2147483649"

echo
echo "Decimal literals"

run_test "decimal zero" "0.0"
run_test "positive decimal" "42.0"
run_test "negative decimal" "-42.0"
run_test "explicit positive decimal" "+42.0"
run_test "fractional decimal" "42.5"
run_test "negative fractional decimal" "-4.2"
run_test "fractional character conversion" "65.5"
run_test "leading decimal point" ".5"
run_test "trailing decimal point" "5."

echo
echo "Scientific notation"

run_test "scientific zero" "1e0"
run_test "scientific positive" "1e1"
run_test "scientific integer" "1e3"
run_test "scientific decimal" "1.5e2"
run_test "scientific negative exponent" "-1.5e-2"
run_test "scientific uppercase" "+2.5E+3"
run_test "large scientific value" "1e10"
run_test "very large scientific value" "1e100"
run_test "negative very large value" "-1e100"

echo
echo "Float literals"

run_test "float positive" "42.0f"
run_test "float negative" "-42.0f"
run_test "float fractional" "42.5f"
run_test "scientific float" "1.5e2f"
run_test "negative scientific float" "-1.5e-2f"
run_test "uppercase scientific float" "+2.5E+3f"

echo
echo "Pseudo-literals"

run_test "nan" "nan"
run_test "nanf" "nanf"
run_test "positive infinity" "+inf"
run_test "negative infinity" "-inf"
run_test "positive float infinity" "+inff"
run_test "negative float infinity" "-inff"

echo
echo "Invalid literals"

run_test "empty input" ""
run_test "letters" "abc"
run_test "word" "hello"
run_test "mixed alphanumeric" "12abc"
run_test "multiple decimal points" "42.5.6"
run_test "multiple dots" "1..2"
run_test "missing exponent digits" "1e"
run_test "missing positive exponent digits" "1e+"
run_test "missing negative exponent digits" "1e-"
run_test "invalid exponent" ".e10"
run_test "double float suffix" "42ff"
run_test "invalid pseudo-literal" "nanff"
run_test "invalid infinity" "infinity"
run_test "invalid quoted character" "'aa'"
run_test "empty quoted character" "''"
run_test "too many quoted characters" "'abc'"
run_test "bare f suffix (no digits)" "f"
run_test "only plus sign" "+"
run_test "only minus sign" "-"

echo
echo "Argument handling"

run_expected_failure "no argument"
run_expected_failure "too many arguments" "42" "extra"

echo
echo "--- Output spot-checks (verify manually) ---"

run_output "char boundary: 127 (max displayable)" "127"
run_output "char boundary: 128 (char: impossible)" "128"
run_output "char boundary: 0 (Non displayable)" "0"
run_output "int max: 2147483647" "2147483647"
run_output "int overflow: 3000000000 (int: impossible)" "3000000000"
run_output "int underflow: -3000000000 (int: impossible)" "-3000000000"
run_output "float overflow: 1e100 (float: impossible)" "1e100"
run_output "float overflow: -1e100 (float: impossible)" "-1e100"
run_output "float max: 3.4e38 (within float range)" "3.4e38"
run_output "double overflow: 1e400 (all impossible)" "1e400"
run_output "pseudo nan" "nan"
run_output "pseudo +inff" "+inff"
run_output "float 3.14f" "3.14f"
run_output "char literal 'a'" "'a'"

echo "================================"
printf "Passed: %d\n" "$PASS_COUNT"
printf "Failed: %d\n" "$FAIL_COUNT"
echo "================================"

if [ "$FAIL_COUNT" -eq 0 ]; then
  exit 0
else
  exit 1
fi
