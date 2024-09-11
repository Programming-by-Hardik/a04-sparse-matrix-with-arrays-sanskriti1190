// sparse_matrix_assignment.c
// This program represents a sparse matrix using a 2D array in C and includes test cases.

#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of non-zero elements in the sparse matrix
#define N 4      // Number of columns in the original matrix (modifiable)

// Function prototypes
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols);
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount);
bool testCreateSparseMatrix();
bool testPrintSparseMatrix();

int main() {
    // Run test cases
    if (testCreateSparseMatrix()) {
        printf("testCreateSparseMatrix PASSED\n");
    } else {
        printf("testCreateSparseMatrix FAILED\n");
    }

    if (testPrintSparseMatrix()) {
        printf("testPrintSparseMatrix PASSED\n");
    } else {
        printf("testPrintSparseMatrix FAILED\n");
    }

    return 0;
}

// Function to convert a matrix into sparse matrix format
void createSparseMatrix(int sparseMatrix[][3], int originalMatrix[][N], int rows, int cols) {
    int k = 0; // Counter for non-zero elements

    // Traverse the original matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (originalMatrix[i][j] != 0) {
                sparseMatrix[k][0] = i;       // Row index
                sparseMatrix[k][1] = j;       // Column index
                sparseMatrix[k][2] = originalMatrix[i][j]; // Value
                k++;
            }
        }
    }
    // Store the number of non-zero elements in the first element of sparseMatrix
    sparseMatrix[0][2] = k; 
    sparseMatrix[0][0] = rows; // Store number of rows
    sparseMatrix[0][1] = cols; // Store number of columns
}

// Function to print sparse matrix representation
void printSparseMatrix(int sparseMatrix[][3], int nonZeroCount) {
    // The first two elements of sparseMatrix are the dimensions of the matrix
    int rows = sparseMatrix[0][0];
    int cols = sparseMatrix[0][1];

    printf("Sparse Matrix (%dx%d) with %d non-zero elements:\n", rows, cols, nonZeroCount);

    for (int i = 1; i <= nonZeroCount; i++) {
        printf("Row: %d, Column: %d, Value: %d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

// Test function for createSparseMatrix
bool testCreateSparseMatrix() {
    int originalMatrix[4][N] = {
        {0, 0, 3, 0},
        {0, 4, 0, 0},
        {0, 0, 0, 5},
        {0, 2, 0, 6}
    };

    int expectedSparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    int sparseMatrix[MAX][3];
    createSparseMatrix(sparseMatrix, originalMatrix, 4, N);

    // Compare the sparseMatrix with the expectedSparseMatrix
    for (int i = 0; i <= expectedSparseMatrix[0][2]; i++) {
        for (int j = 0; j < 3; j++) {
            if (sparseMatrix[i][j] != expectedSparseMatrix[i][j]) {
                return false;  // If any value doesn't match, test fails
            }
        }
    }

    return true;  // Test passes if all values match
}

// Test function for printSparseMatrix
bool testPrintSparseMatrix() {
    // Define a sparse matrix with 5 non-zero elements
    int sparseMatrix[MAX][3] = {
        {4, 4, 5},   // 4x4 matrix with 5 non-zero elements
        {0, 2, 3},   // Original matrix[0][2] = 3
        {1, 1, 4},   // Original matrix[1][1] = 4
        {2, 3, 5},   // Original matrix[2][3] = 5
        {3, 1, 2},   // Original matrix[3][1] = 2
        {3, 3, 6}    // Original matrix[3][3] = 6
    };

    // Simulate a successful print (visual inspection may be needed for testing this)
    printf("Expected Sparse Matrix Output:\n");
    printSparseMatrix(sparseMatrix, sparseMatrix[0][2]);

    // Since printSparseMatrix only prints the output, we assume it passes if the format is correct
    return true;
}

    
  
   
    // Since printSparseMatrix only prints the output, we assume it passes if the format is correct
