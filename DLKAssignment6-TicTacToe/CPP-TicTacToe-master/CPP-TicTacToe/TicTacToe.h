#pragma once
#include "Game.h"
#include <array>

class TicTacToe : public Game {
public:
    //constructor that does some initialization
    TicTacToe()
        : board{ '1','2','3','4','5','6','7','8','9' },
        currentPlayer('X'),
        gameOver(false) {
    }

    //checks if game is over
    bool IsGameOver() const override;

    //used to display the game board
    void Display() const override;

    //allows players to take turns
    void TakeTurn() override;

private:
    //setting up the game board
    std::array<char, 9> board;

    //keeps track of current player - x or y
    char currentPlayer;

    //flag used to tell if game is over or not
    bool gameOver;

    //determine what player has won
    bool CheckWin(char player) const;

    //is the board full and therefore no more moves can be made, resulting in a tie?
    bool IsBoardFull() const;

    //switch from player x to y or vice versa
    void SwitchPlayer();
};
