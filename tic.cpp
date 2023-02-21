#include <iostream>
#include <vector>
#include <string>

using namespace std;

// function to print the game board
void printBoard(const vector<string>& board) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " " << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " " << endl;
}

// function to check if the game has been won
bool checkWin(const vector<string>& board, char player) {
    // check horizontal rows
    for (int i = 0; i < 3; i++) {
        if (board[i*3] == string(1, player) &&
            board[i*3+1] == string(1, player) &&
            board[i*3+2] == string(1, player)) {
            return true;
        }
    }

    // check vertical rows
    for (int i = 0; i < 3; i++) {
        if (board[i] == string(1, player) &&
            board[i+3] == string(1, player) &&
            board[i+6] == string(1, player)) {
            return true;
        }
    }

    // check diagonal rows
    if (board[0] == string(1, player) &&
        board[4] == string(1, player) &&
        board[8] == string(1, player)) {
        return true;
    }
    if (board[2] == string(1, player) &&
        board[4] == string(1, player) &&
        board[6] == string(1, player)) {
        return true;
    }

    return false;
}

// main function
int main() {
    vector<string> board(9, " ");
    int moveCount = 0;
    char currentPlayer = 'X';

    while (moveCount < 9) {
        // print the board
        printBoard(board);

        // ask for the current player's move
        int move;
        cout << "Player " << currentPlayer << "'s move (1-9): ";
        cin >> move;

        // check if the move is valid
        if (move < 1 || move > 9 || board[move-1] != " ") {
            cout << "Invalid move, try again" << endl;
            continue;
        }

        // update the board
        board[move-1] = string(1, currentPlayer);
        moveCount++;

        // check if the game has been won
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!" << endl;
            printBoard(board);
            return 0;
        }

        // switch to the other player
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    // if we get here, the game is a draw
    cout << "Game is a draw!" << endl;
    printBoard(board);
    return 0;
}
