#include <iostream>

const int N = 3;

void matrixMultiplication(int A[N][N], int B[N][N], int C[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int B[N][N] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int C[N][N] = { 0 };

    matrixMultiplication(A, B, C);

    std::cout << "Resultant matrix: \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}