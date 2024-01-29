#include "TicTacToe.h"
#include "TicTacToe.cpp"

int main() {
    TicTacToe *game = new TicTacToe();
    game->playGame();
    delete game;
    return 0;
}
