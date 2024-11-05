#include <iostream>
#include <vector>
using namespace std;

#define N 8

// Function to print the board with 'Q' for queens and '.' for empty spaces
void printBoard(vector<vector<int>> &board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueens(vector<vector<int>> &board, int col) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return true;

    // Consider this column and try placing queens in all rows one by one
    for (int i = 0; i < N; i++) {
        // Check if it's safe to place the queen at board[i][col]
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1))
                return true;

            // If placing the queen in board[i][col] doesn't lead to a solution,
            // then backtrack and remove the queen from board[i][col]
            board[i][col] = 0;
        }
    }

    // If the queen cannot be placed in any row in this column, return false
    return false;
}

// Function to initialize the board with the first queen placed
void solveWithFirstQueenPlaced(int row, int col) {
    // Create an 8x8 chessboard initialized to 0
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen at the given position
    board[row][col] = 1;

    // Use backtracking to solve the rest of the board
    if (!solveNQueens(board, col + 1)) 
        return ;
    

    // Print the solution board
    printBoard(board);
}

int main() {
    int row, col;

    // Input the row and column of the first queen
    cout << "Enter the row and column of the first queen (0-based index): ";
    cin >> row >> col;

    // Solve the problem with the first queen placed
    solveWithFirstQueenPlaced(row, col);

    return 0;
}
