#include <iostream>
#define MAX_N 10

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N) {
    // Check if the current column has a queen
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the right side
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[MAX_N][MAX_N], int row, int N) {
    if (row == N) {
        // All queens have been successfully placed
        // Print the solution
        std::cout << "Solution:\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        return true;
    }

    bool foundSolution = false;

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen

            // Recursively solve for the next row
            foundSolution = solveNQueens(board, row + 1, N) || foundSolution;

            board[row][col] = 0; // Backtrack and remove the queen
        }
    }

    return foundSolution;
}

int main() {
    int N;
    int board[MAX_N][MAX_N];

    std::cout << "Enter the value of N for N-Queens problem: ";
    std::cin >> N;

    // Initialize the board
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(board, 0, N)) {
        std::cout << "No solution exists for N = " << N << "\n";
    }

    return 0;
}
