// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
using namespace std;

// PART A — Print the First N Terms
void printFibonacciSequence() {
    int n;
    cout << "How many terms? ";
    cin >> n;
    
    // check if N is positive
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }
    
    cout << "Fibonacci sequence:";
    
    long long t1 = 0;
    long long t2 = 1;
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            cout << " " << t1;
            continue;
        }
        if (i == 2) {
            cout << " " << t2;
            continue;
        }
        
        long long nextTerm = t1 + t2;
        cout << " " << nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }
    cout << endl;
}

// PART B — Check if a Number Belongs to the Sequence
void checkFibonacciNumber() {
    long long num;
    cout << "Enter a number to check: ";
    cin >> num;
    
    if (num < 0) {
        cout << num << " is NOT a Fibonacci number." << endl;
        return;
    }
    
    long long t1 = 0;
    long long t2 = 1;
    bool isFib = false;
    
    if (num == 0 || num == 1) {
        isFib = true;
    }
    
    while (t2 <= num) {
        if (t2 == num) {
            isFib = true;
            break;
        }
        long long nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        if (t1 > num) break;
    }
    
    if (isFib) {
        cout << num << " is a Fibonacci number." << endl;
    } else {
        cout << num << " is NOT a Fibonacci number." << endl;
    }
}

int main() {
    // calling part a function
    printFibonacciSequence();
    
    cout << endl;
    
    // calling part b function
    checkFibonacciNumber();

    return 0;
}