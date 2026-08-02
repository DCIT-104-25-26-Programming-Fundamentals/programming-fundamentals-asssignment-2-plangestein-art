// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// PART A — Transpose a Matrix
void transposeMatrix() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    int matrix[10][10];
    
    // Read matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    
    cout << "\nTransposed Matrix:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART B — Add Two Matrices
void addMatrices() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    int matA[10][10], matB[10][10], result[10][10];
    
    cout << "\nEnter elements for Matrix A:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matA[i][j];
        }
    }
    
    cout << "\nEnter elements for Matrix B:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matB[i][j];
        }
    }
    
    // Compute sum
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
    
    cout << "\nResult of Matrix Addition:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << result[i][j];
        }
        cout << endl;
    }
}

// PART C — Multiply Two Matrices
void multiplyMatrices() {
    int r1, c1, r2, c2;
    
    cout << "Enter rows and columns for Matrix A: ";
    cin >> r1 >> c1;
    
    cout << "Enter rows and columns for Matrix B: ";
    cin >> r2 >> c2;
    
    if (c1 != r2) {
        cout << "Error: Columns of A must match rows of B for multiplication!" << endl;
        return;
    }
    
    int matA[10][10], matB[10][10], result[10][10] = {0};
    
    cout << "\nEnter elements for Matrix A:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matA[i][j];
        }
    }
    
    cout << "\nEnter elements for Matrix B:" << endl;
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matB[i][j];
        }
    }
    
    // Compute multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
    
    cout << "\nResult of Matrix Multiplication (A x B):" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << setw(6) << result[i][j];
        }
        cout << endl;
    }
}

int main() {
    // You can test each function here individually as required by the assignment
    cout << "=== PART A: Transpose ===" << endl;
    transposeMatrix();
    
    cout << "\n=== PART B: Addition ===" << endl;
    addMatrices();
    
    cout << "\n=== PART C: Multiplication ===" << endl;
    multiplyMatrices();

    return 0;
}
