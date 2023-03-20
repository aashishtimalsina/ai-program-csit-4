#include <stdio.h>

#define N 8 // Change this to the desired number of queens

void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_safe(int board[N][N], int row, int col) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return 0;
        }
    }
    
    // Check if there is a queen in the upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    // Check if there is a queen in the lower diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) {
            return 0;
        }
    }
    
    // If it passes all checks, it is safe to place the queen
    return 1;
}

int solve(int board[N][N], int col) {
    // Base case: if all queens are placed, return 1
    if (col >= N) {
        return 1;
    }
    
    // Try placing the queen in each row of the current column
    for (int i = 0; i < N; i++) {
        if (is_safe(board, i, col)) {
            board[i][col] = 1;
            
            // Recursively place the rest of the queens
            if (solve(board, col+1)) {
                return 1;
            }
            
            // Backtrack by removing the queen and trying the next row
            board[i][col] = 0;
        }
    }
    
    // If no queen can be placed in this column, return 0
    return 0;
}

int main() {
    int board[N][N] = {0};
    
    if (solve(board, 0)) {
        printf("Solution found:\n");
        print_board(board);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}
