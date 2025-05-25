#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

int board[MAX];
int N;

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[N][N], int col) {
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid value of N. Must be between 1 and %d.\n", MAX);
        return 1;
    }

    solve(0);

    return 0;
}
