#ifndef tictactoe_cpp
#define tictactoe_cpp

#include <string>
#include <iostream>
#include <stdio.h>
#include "tictactoe.h"

using namespace std;

TicTacToe::TicTacToe() {

};

char TicTacToe::getCurrentPlayer() {
    return players[currentPlayer];
}

void TicTacToe::nextPlayer() {
    currentPlayer ^= 1;
    turn++;
}

bool TicTacToe::play(int row, int column) {
    if (board[row][column] != ' ') {
        return false;
    }
    board[row][column] = getCurrentPlayer();
    nextPlayer();
    return true;
};

char TicTacToe::getWinner() {
    return winner;
}

bool TicTacToe::hasEnded() {
    if (getWinner() != ' ') {
        return true;
    }
    for (int row = 0; row < 3; row++) {
        if (board[row][0] != ' ' && board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            winner = board[row][0];
            return true;
        }
    }
    for (int column = 0; column < 3; column++) {
        if (board[0][column] != ' ' && board[0][column] == board[1][column] && board[0][column] == board[2][column]) {
            winner = board[0][column];
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        winner = board[0][0];
        return true;
    }
    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
        winner = board[2][0];
        return true;
    }
    if (turn == 9) {
        return true;
    }
    return false;
}

string TicTacToe::formatEmpty() {
    return formatBoard(empty);
}

string TicTacToe::formatHelp() {
    return formatBoard(numbered);
}

string TicTacToe::formatState() {
    return formatBoard(board);
}

string TicTacToe::formatBoard(char data[3][3]) {
    string formatted = "";
    for (int row = 0; row < 3; row++) {
        if (row != 0) {
            formatted += "-+-+-\n";
        }
        for (int column = 0; column < 3; column++) {
            if (column != 0) {
                formatted += '|';
            }
            formatted += data[row][column];
        }
        formatted += '\n';
    }
    return formatted;
};


int main() {
    TicTacToe* game = new TicTacToe();

    cout << "TicTacToe" << endl << endl;
    cout << "How to play:" << endl;
    cout << "Enter number as follows to place your token at that position:" << endl;
    cout << game->formatHelp() << endl;
    cout << "Rules:" << endl;
    cout << "Player X and player O take turns placing their tokens. First to get three tokens in a row, column or large diagonal wins. You cannot overwrite already existing tokens." << endl << endl;

    while (!game->hasEnded()) {
        cout << game->formatState() << endl;
        cout << "Player " << game->getCurrentPlayer() << "'s turn: ";
        int location;
        if (cin >> location) {
            if (location < 1 || location > 9) {
                cout << "Invalid input! Choose a number between 1 to 9!" << endl;
            } else if (!game->play(2 - (location - 1) / 3, (location - 1) % 3)) {
                cout << "You can't play at this location." << endl;
            }
        } else if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Choose a number between 1 to 9!" << endl;
        } else {
            return 1;
        }
        cout << endl;
    }
    
    cout << game->formatState() << endl;

    char winner = game->getWinner();
    if (winner == ' ') {
        cout << "The game ended in a draw!" << endl;
    } else {
        cout << "Player " << winner << " won the game!" << endl;
    }
    return 0;
}

#endif
