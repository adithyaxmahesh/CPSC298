#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <utility>

class TicTacToe {
public:
    TicTacToe();
    ~TicTacToe();
    void playGame();

private:
    char **grid;
    void initializeGrid();
    void displayGrid() const;
    bool makeMove(int row, int col, char player);
    bool checkWin(char player) const;
    bool checkDraw() const;
    std::pair<int, int> computerMove() const;
};

#endif //
