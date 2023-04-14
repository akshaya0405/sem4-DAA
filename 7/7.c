#include <stdio.h>
#include <stdbool.h>

void printSolution(int n, int board[n][n]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int n, int board[n][n], int row, int col) {
    int i, j;

    // Check the left side of the row
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

void solveNQueensUtil(int n, int board[n][n], int col) {
    if (col == n) {
        printSolution(n, board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(n, board, i, col)) {
            board[i][col] = 1;
            solveNQueensUtil(n, board, col+1);
            board[i][col] = 0;
        }
    }
}

void solveNQueens(int n) {
    int board[n][n];

    // Initialize the board to all 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    solveNQueensUtil(n, board, 0);
}

int main() {
    int n = 0;
    printf("\nEnter the dimension of the chessboard : ");
    scanf("%d",&n);
    solveNQueens(n);
    return 0;
}