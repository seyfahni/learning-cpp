#ifndef tictactoe_h
#define tictactoe_h

#include <string>

using namespace std;

class TicTacToe {
    public:
    TicTacToe();
    ~TicTacToe();

    bool play(int x, int y);

    string formatBoard();

    private:
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '},
    };
    char players[2] = {'X', 'O'};
};

#endif
