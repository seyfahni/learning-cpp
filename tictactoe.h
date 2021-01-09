#ifndef tictactoe_h
#define tictactoe_h

#include <string>

using namespace std;

class TicTacToe {
    public:
    TicTacToe();
    ~TicTacToe();

    char getCurrentPlayer();
    void nextPlayer();

    bool play(int row, int column);

    bool hasEnded();

    char getWinner();

    string formatState();
    string formatHelp();
    string formatEmpty();

    private:

    string formatBoard(char data[3][3]);

    char empty[3][3] = {
        {' ', ' ', ' ',},
        {' ', ' ', ' ',},
        {' ', ' ', ' ',},
    };
    char numbered[3][3] = {
        {'7', '8', '9',},
        {'4', '5', '6',},
        {'1', '2', '3',},
    };
    char board[3][3] = {
        {' ', ' ', ' ',},
        {' ', ' ', ' ',},
        {' ', ' ', ' ',},
    };
    char players[2] = {'X', 'O'};
    int currentPlayer = 0;
    char winner = ' ';
    int turn = 0;
};

#endif
