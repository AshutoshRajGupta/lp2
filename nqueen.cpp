#include <iostream>
#include <vector>
using namespace std;
// Function to check if it is safe to place a queen at the given position
bool isSafe(vector<int> &board, int row, int col)
{
    // Check if there is a queen in the same column or in the diagonal positions
    for (int i = 0; i < row; i++)
    {
        if (board[i] == col || board[i] == col - (row - i) || board[i] == col + (row - i))
        {
            return false;
        }
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(vector<int> &board, int row, int n, int &count)
{
    if (row == n)
    {
        // All queens are successfully placed, print the solution
        count++;
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i] == j)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++)
    {
        //check if the position is safe
        if (isSafe(board, row, col))
        {
            //place the queen in the current column
            board[row] = col;
            // Recursively solve the remaining n - 1 queens
            solveNQueens(board, row + 1, n, count);
            // Backtracking
            board[row] = -1;
        }
    }
}

//Function to solve the N-Queens problem and print all possible solutions
void solveNQueens(int n)
{
    vector<int> board(n, -1); // Initialize the board with all positions as empty

    int count = 0;
    solveNQueens(board, 0, n, count);

    if (count == 0)
    {
        cout << "No solutions found.\n";
    }
    else
    {
        cout << "Total solutions: " << count << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
