#!/bin/bash
#
# # Colors for output
# RED='\033[0;31m'
# GREEN='\033[0;32m'
# NC='\033[0m' # No color
#
# # Function to run push_swap and check results
# run_test() {
#     numbers="$1"
#     num_count="$2"
#     max_ops="$3"
#
#     result=$(./push_swap $numbers | ./checker_linux $numbers)
#     ops_count=$(./push_swap $numbers | wc -l)
#
#     if [ "$result" == "OK" ] && [ "$ops_count" -le "$max_ops" ]; then
#         echo -e "${GREEN}Test OK: $numbers ($ops_count ops)${NC}"
#         return $ops_count
#     else
#         echo -e "${RED}Test KO: $numbers (Result: $result, Ops: $ops_count)${NC}"
#         return -1
#     fi
# }
#
# # Generate all combinations of n numbers
# generate_combinations() {
#     n="$1"
#     seq=$(seq 1 "$n")
#     python3 -c "import itertools; print('\n'.join(' '.join(map(str, p)) for p in itertools.permutations(range(1, $n+1))))"
# }
#
# # Average operations calculator
# calculate_average() {
#     total="$1"
#     count="$2"
#     if [ "$count" -gt 0 ]; then
#         echo "scale=2; $total / $count" | bc
#     else
#         echo 0
#     fi
# }
#
# # Test specific number sets
# test_set() {
#     n="$1"
#     max_ops="$2"
#     combinations="$3"
#
#     total_ops=0
#     valid_count=0
#
#     for numbers in $combinations; do
#         run_test "$numbers" "$n" "$max_ops"
#         ops=$?
#         if [ $ops -ge 0 ]; then
#             total_ops=$((total_ops + ops))
#             valid_count=$((valid_count + 1))
#         fi
#     done
#
#     avg_ops=$(calculate_average "$total_ops" "$valid_count")
#     echo -e "Average operations for $n numbers: ${GREEN}$avg_ops${NC}"
# }
#
# # Generate difficult combinations for larger sets
# generate_difficult_combinations() {
#     n="$1"
#     python3 -c "import random; print(' '.join(map(str, random.sample(range(0, $n), $n))))"
# }
#
# # Main script execution
# echo "Testing push_swap"
#
# # Test 3 numbers
# echo "Testing 3 numbers..."
# combinations=$(generate_combinations 3)
# test_set 3 3 "$combinations"
#
# # Test 5 numbers
# echo "Testing 5 numbers..."
# combinations=$(generate_combinations 5)
# test_set 5 12 "$combinations"
#
# # Test 100 numbers
# echo "Testing 100 numbers..."
# numbers=$(generate_difficult_combinations 100)
# run_test "$numbers" 100 700
#
# # Test 500 numbers
# echo "Testing 500 numbers..."
# numbers=$(generate_difficult_combinations 500)
# run_test "$numbers" 500 5500
#
# echo "All tests complete."

# Function to generate a sequence of unique random numbers
generate_numbers() {
    local count=$1
    shuf -i 1-"$count" -n "$count" | tr '\n' ' '
}

# Function to run tests for 3 and 5 numbers (all combinations)
run_combinations() {
    local max_ops=$1
    local numbers="$2"
    local num_count=$3
    echo "Testing all combinations of \"$num_count\" numbers..."

    avg_ops=0
    total_tests=0
    echo "$numbers" | while read -r nums; do
        echo -n "Testing: $nums -> "
        output=$(./push_swap "$nums" 2>&1)
        if [[ "$output" == "Error" ]]; then
            echo -e "\033[31mKO\033[0m (Error detected)"
            continue
        fi
        ops=$(echo "$output" | wc -l)
        total_tests=$((total_tests + 1))
        avg_ops=$((avg_ops + ops))

        if [ "$ops" -gt "$max_ops" ]; then
            echo -e "\033[31mKO\033[0m ($ops ops)"
        else
            echo -e "\033[32mTest OK\033[0m ($ops ops)"
        fi
    done

    if [ $total_tests -gt 0 ]; then
        avg_ops=$((avg_ops / total_tests))
        echo -e "Average operations for $num_count numbers: \033[36m$avg_ops\033[0m"
    else
        echo -e "No valid tests executed for $num_count numbers."
    fi
}

# Function to run multiple tests for 100 and 500 numbers
run_multiple_tests() {
    local count=$1
    local max_ops=$2
    local test_count=$3
    echo "Running $test_count tests for $count numbers..."

    avg_ops=0
    valid_tests=0
    for i in $(seq 1 $test_count); do
        nums=$(generate_numbers $count)
        echo -n "Test $i -> "
        output=$(./push_swap $nums 2>&1)
        if [[ "$output" == "Error" ]]; then
            echo -e "\033[31mKO\033[0m (Error detected)"
            continue
        fi
        ops=$(echo "$output" | wc -l)
        avg_ops=$((avg_ops + ops))
        valid_tests=$((valid_tests + 1))

        if [ $ops -gt $max_ops ]; then
            echo -e "\033[31mTest KO\033[0m ($ops ops)"
        else
            echo -e "\033[32mTest OK\033[0m ($ops ops)"
        fi
    done

    if [ $valid_tests -gt 0 ]; then
        avg_ops=$((avg_ops / valid_tests))
        echo -e "Average operations for $count numbers: \033[36m$avg_ops\033[0m"
    else
        echo -e "No valid tests executed for $count numbers."
    fi
}

# Main script
echo "Testing for 3 numbers combinations"
combinations_3=$(echo -e "1 2 3\n1 3 2\n2 1 3\n2 3 1\n3 1 2\n3 2 1")
run_combinations 3 "$combinations_3" 3

echo "Testing for 5 numbers combinations"
combinations_5=$(echo -e "1 2 3 4 5\n1 2 3 5 4\n1 2 4 3 5\n1 2 5 3 4\n1 3 2 4 5\n1 3 2 5 4\n1 3 4 2 5\n1 3 5 2 4")
run_combinations 12 "$combinations_5" 5

echo "Testing for 100 numbers"
run_multiple_tests 100 700 10

echo "Testing for 500 numbers"
run_multiple_tests 500 5500 10
