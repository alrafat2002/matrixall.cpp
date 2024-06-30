#include<bits/stdc++.h>
using namespace std;


void DisplayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixAddition(int** A, int** B, int rows, int cols, int** result) {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            result[i][j] = A[i][j] + B[i][j];

        }

    }

}


void matrixMultiplication(int** matrixA, int rowsA, int colsA, int** matrixB, int rowsB, int colsB, int** result) {
    if (colsA != rowsB) {
        cout << "Error: Matrix dimensions mismatch for multiplication." << endl;
        return;
    }

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void matrixTranspose(int** matrix, int rows, int cols, int** result) {

    for (int i = 0; i < cols; ++i) {

        for (int j = 0; j < rows; ++j) {

            result[i][j] = matrix[j][i];

        }

    }

}

int main() {

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;


    int** matrixA = new int*[rows];
    int** matrixB = new int*[cols];

    for (int i = 0; i < rows; ++i) {
        matrixA[i] = new int[cols];
    }
    for (int i = 0; i < cols; ++i) {
        matrixB[i] = new int[rows];
    }

    int** matrixSum = new int*[rows];

    for (int i = 0; i < rows; ++i) {

        matrixA[i] = new int[cols];

        matrixB[i] = new int[cols];

        matrixSum[i] = new int[cols];

    }

    int** matrixTransposeB = new int*[cols];

    for (int i = 0; i < rows; ++i) {

        matrixB[i] = new int[cols];

    }

    for (int i = 0; i < cols; ++i) {

        matrixTransposeB[i] = new int[rows];

    }


    cout << "Matrix A:" << endl;
    DisplayMatrix(matrixA, rows, cols);
    cout << endl;

    cout << "Matrix B:" << endl;
    DisplayMatrix(matrixB, cols, rows);
    cout << endl;


    int** matrixResult = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrixResult[i] = new int[rows];
    }

    matrixAddition(matrixA, matrixB, rows, cols, matrixSum);


    cout << "Matrix Sum (A + B):" << endl;

    matrixTranspose(matrixB, rows, cols, matrixTransposeB);

    cout << "Transpose of Matrix B:" << endl;

    matrixMultiplication(matrixA, rows, cols, matrixB, cols, rows, matrixResult);

    cout << "Matrix Multiplication (A * B):" << endl;

    DisplayMatrix(matrixResult, rows, rows);
    cout << endl;


    return 0;
}
