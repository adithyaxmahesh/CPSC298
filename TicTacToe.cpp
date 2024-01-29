#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe() {
    grid = new char*[3];
    for (int i = 0; i < 3; ++i) {
        grid[i] = new char[3];
    }
    initializeGrid();
}

TicTacToe::~TicTacToe() {
    for (int i = 0; i < 3; ++i) {
        delete[] grid[i];
    }
    delete[] grid;
}

void TicTacToe::initializeGrid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = '~';
        }
    }
}

void TicTacToe::displayGrid() const {
    
}

bool TicTacToe::makeMove(int row, int col, char player) {
    
}

bool TicTacToe::checkWin(char player) const {

}

bool TicTacToe::checkDraw() const {
  
}

std::pair<int, int> TicTacToe::computerMove() const {
   
}

void TicTacToe::playGame() {
    
}
