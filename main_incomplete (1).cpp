/// @file main_incomplete.cpp
/// @amahesh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>   
#include "Game.h"     

int main() {
    bool bPlay = true;
    Game game;

    while (bPlay) {
        game.play();

        std::cout << std::endl;
        char cPlay = 'n';
        std::cout << "Play another game? (y/n)" << std::endl;
        std::cin >> cPlay;
        if (cPlay != 'y') {
            bPlay = false;
        }
    }

    return 0;
}
