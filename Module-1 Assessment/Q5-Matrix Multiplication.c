#include <stdio.h>

void matrix_Multiplication(int rows, int cols, int mat1[][cols], int mat2[][cols], int result[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols, int mat[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int rows, cols;

    printf("Size of Row: ");
    scanf("%d", &rows);

    printf("Size of Column: ");
    scanf("%d", &cols);

    int mat1[rows][cols], mat2[rows][cols], result[rows][cols];

    printf("Matrix 1:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Matrix 2:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &mat2[i][j]);
        }
    }
    matrixMultiplication(rows, cols, mat1, mat2, result);
    printf("Product:\n");
    printMatrix(rows, cols, result);
}
