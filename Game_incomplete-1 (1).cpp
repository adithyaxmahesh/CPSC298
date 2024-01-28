/// @file Game.cpp
/// @brief Implementation file for Game class
/// @amahesh@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream> // defines std::cout
#include <tuple>    // defines std::tuple, std::tie
#include <cmath>    // defines std::abs
#include <random>   // defines random number generation functions
#include <ctime>    // defines time()

#include "Game.h"   // defines Game class

//#define TEST  // macro to enable test mode functionality (not used during ordinary gameplay)
// #define DIAG  // macro to enable diagnostic output (not used during ordinary gameplay)

Game::Game() : m_nGridRows(k_nGridRowsDefault), m_nGridColumns(k_nGridColumnsDefault), m_iRowBoat(0), m_iColumnBoat(0), m_nTorpedoes(k_nMaxTorpedoes) {
  initializeGrid();
}

void Game::initializeGrid() {
  for (int iRow = 0; iRow < this->m_nGridRows; ++iRow) {
    for (int iColumn = 0; iColumn < this->m_nGridColumns; ++iColumn) {
      this->a_cGrid[iRow][iColumn] = '~';
    }
  }
}

void Game::displayGrid(bool bShowBoat) {
  for (int iRow = 0; iRow < this->m_nGridRows; ++iRow) {
    std::cout << "|";
    for (int iColumn = 0; iColumn < this->m_nGridColumns; ++iColumn) {
      if ('V' == this->a_cGrid[iRow][iColumn] && !bShowBoat) {
        std::cout << '~' << "|";
      } else {
        std::cout << this->a_cGrid[iRow][iColumn] << "|";
      }
    }
    std::cout << std::endl;
  }
}

std::tuple<int, int> Game::fireTorpedo() {
  --this->m_nTorpedoes;
  int iRow, iColumn;
  std::tie(iRow, iColumn) = promptForGridCoord();
  this->a_cGrid[iRow][iColumn] = '*';
  return std::make_tuple(iRow, iColumn);
}

void Game::placeBoatRandomly() {
  std::random_device randomDevice;
  std::default_random_engine randomNumbreGenerator(randomDevice());

  std::uniform_int_distribution<int> uniformIntegerDistributionRows(0, (this->m_nGridRows - 1));
  this->m_iRowBoat = uniformIntegerDistributionRows(randomNumbreGenerator);

  std::uniform_int_distribution<int> uniformIntegerDistributionColumns(0, (this->m_nGridColumns - 1));
  this->m_iColumnBoat = uniformIntegerDistributionColumns(randomNumbreGenerator);

  this->a_cGrid[this->m_iRowBoat][this->m_iColumnBoat] = 'V';

#if defined(DIAG)
  std::cout << "DIAG: Boat location (Row/Column): " << this->m_iRowBoat << "; " << this->m_iColumnBoat << std::endl;
#endif 
}

void Game::placeBoat() {
  int iRow, iColumn;
  std::tie(iRow, iColumn) = promptForGridCoord();
  this->m_iRowBoat = iRow;
  this->m_iColumnBoat = iColumn;
  this->a_cGrid[iRow][iColumn] = 'V';
}

bool Game::isOnTarget(int iRow, int iColumn) {
  return this->m_iRowBoat == iRow && this->m_iColumnBoat == iColumn;
}

bool Game::isCloseToTarget(int iRow, int iColumn) {
  return std::abs(this->m_iRowBoat - iRow) <= 1 && std::abs(this->m_iColumnBoat - iColumn) <= 1;
}

void Game::showSunk() {
  this->a_cGrid[this->m_iRowBoat][this->m_iColumnBoat] = 'X';
}

std::tuple<int, int> Game::promptForGridCoord() {
  int iRow, iColumn;
  std::cout << "Please enter grid row number: ";
  std::cin >> iRow;
  std::cout << "Please enter grid column number: ";
  std::cin >> iColumn;
  return std::make_tuple(iRow, iColumn);
}

void Game::play() {
  int iRow, iColumn;

  this->reset();
  this->displayGrid(false);
  std::cout << "Magazine: " << this->m_nTorpedoes << " torpedoes" << std::endl;
  std::cout << std::endl;

  bool bSunk = false;
  while ((!bSunk) && (this->m_nTorpedoes > 0)) {
    std::cout << std::endl;
    std::tie(iRow, iColumn) = this->fireTorpedo();

    if (this->isOnTarget(iRow, iColumn)) {
      this->showSunk();
      this->displayGrid(false);
      std::cout << "Hit!  Kaboom!" << std::endl;
      std::cout << "Victory!" << std::endl;
      bSunk = true;
    } else if (this->isCloseToTarget(iRow, iColumn)) {
      this->displayGrid(false);
      std::cout << "Location row: " << iRow << "; column: " << iColumn << " is close!" << std::endl;
    } else {
      this->displayGrid(false);
      std::cout << "Location row: " << iRow << "; column: " << iColumn << " is a miss." << std::endl;
    }

    if (!bSunk) {
      std::cout << "Magazine: " << this->m_nTorpedoes << " torpedoes" << std::endl;
    }

    if (this->m_nTorpedoes == 0 && !bSunk) {
      this->displayGrid(true);
      std::cout << "Torpedoes expended" << std::endl;
      std::cout << "Game over" << std::endl;
    }
  }
}

void Game::reset() {
  this->initializeGrid();
#if defined TEST
  this->placeBoat();
#else
  this->placeBoatRandomly();
#endif
  this->m_nTorpedoes = Game::k_nMaxTorpedoes;
}
