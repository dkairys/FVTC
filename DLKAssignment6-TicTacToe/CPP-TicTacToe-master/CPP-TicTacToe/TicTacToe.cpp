#include "TicTacToe.h"
#include <iostream>


//determines if game is over
bool TicTacToe::IsGameOver() const 
{
    return gameOver;
}

//creates the board for play
void TicTacToe::Display() const 
{
    //build the board
    std::cout << "\n";
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";    
    
    //if the game isn't over, prompt for the next player to go
    if (!gameOver) 
    {
        std::cout << "\nPlayer " << currentPlayer << "'s turn.\n";
    }

}

//prompt user to take a turn with values 1 - 9
void TicTacToe::TakeTurn() 
{
    int move;
    while (true) 
    {
        //prompt player to enter a numeric value for where they want to move
        std::cout << "Enter a position (1-9): ";
        std::cin >> move;

        if (std::cin.fail() || move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') 
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid move. Try again.\n";
        }
        else 
        {
            break;
        }
    }

    //put that players marker on that spot they selected
    board[move - 1] = currentPlayer;

    //check if that move generated a win
    if (CheckWin(currentPlayer)) 
    {
        Display();
        std::cout << "Player " << currentPlayer << " wins!\n";
        gameOver = true;        
    }
    //check if the board is full of x or o's
    else if (IsBoardFull()) 
    {
        Display();
        std::cout << "It's a tie!\n";
        gameOver = true;
    }
    //there was no winner and the board isn't full, so switch players
    else 
    {
        SwitchPlayer();
    }
}

//check if that spot selected won the game
bool TicTacToe::CheckWin(char player) const 
{
    const int winPatterns[8][3] = 
    {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };

    for (const auto& pattern : winPatterns) 
    {
        if (board[pattern[0]] == player &&
            board[pattern[1]] == player &&
            board[pattern[2]] == player) 
        {
            return true;
        }
    }
    return false;
}

//determines if board is full
bool TicTacToe::IsBoardFull() const 
{
    for (char c : board) 
    {
        if (c != 'X' && c != 'O') return false;
    }
    return true;
}

//change players
void TicTacToe::SwitchPlayer() 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
