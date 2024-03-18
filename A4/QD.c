#include <stdio.h>
#include <stdbool.h>
#define N 9
bool isSafe(int row, int col, int sudoku[N][N], int val) {
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == val || sudoku[i][col] == val)
            return false;
    }
    int startRow = 3 * (row / 3), startCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[startRow + i][startCol + j] == val)
                return false;

    return true;
}
bool solve(int sudoku[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (sudoku[row][col] == -1) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, sudoku, val)) {
                        sudoku[row][col] = val;
                        if (solve(sudoku))
                            return true;
                        sudoku[row][col] = -1;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void print(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", sudoku[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int sudoku[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    if (solve(sudoku)) 
        print(sudoku);
    else 
        printf("No solution exists.\n");
    return 0;
}



