#include <iostream>

using namespace std;

// Function prototypes
void initializeBoard(char board[3][3]);
void printBoard(char board[3][3]);
bool isInputValid(char board[3][3], int row, int col);
bool checkWin(char board[3][3], char symbol);
bool isBoardFull(char board[3][3]);

int main() {
    char board[3][3];
    int row, col;
    char currentPlayer = 'X';

    initializeBoard(board);

    do {
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (isInputValid(board, row, col)) {
            // Update the board with the player's move
            board[row - 1][col - 1] = currentPlayer;

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check if the board is full (draw)
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (true);

    return 0;
}

void initializeBoard(char board[3][3]) {
    // Initialize the board with numbers 1 to 9
    char cellValue = '1';

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = cellValue++;
        }
    }
}

void printBoard(char board[3][3]) {
    cout << "\nTic Tac Toe\n\n";

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];

            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;

        if (i < 2) {
            cout << "---------\n";
        }
    }

    cout << endl;
}

bool isInputValid(char board[3][3], int row, int col) {
    // Check if the chosen cell is within the board and not already taken
    return (row >= 1 && row <= 3) && (col >= 1 && col <= 3) && (board[row - 1][col - 1] != 'X' && board[row - 1][col - 1] != 'O');
}

bool checkWin(char board[3][3], char symbol) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
            (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
        (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)) {
        return true;
    }

    return false;
}

bool isBoardFull(char board[3][3]) {
    // Check if any cell is still unoccupied
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }

    return true;
}
