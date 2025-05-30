#include <iostream>
#include "Board.h"
#include "Letters.h"
// Tic Tac Toe Extreme

int main() {
    Board board;
    int x;
    int y;

    bool gameStatus = true;
    while (gameStatus) {
        std::cout << "Enter your moves in the form of coordinates ranging from 0 - 2 for x and y"<< std::endl;
        std::cin >> x >> y;
        board.playMove(x,y);

        if (board.checkWin()) {
            std::cout<<board.getWinner()<< " Has won congratulations!\n"<< "Play again? Y/n\n";
            char playAgain;
            std::cin >> playAgain;
            if (playAgain == 'n') {
                gameStatus = false;
            }else {
                board.resetGame();
                board.printBoard();
            }
        }else if (board.checkTie()) {
            std::cout<<board.getWinner()<< " The game has tied! No one wins!\n"<< "Play again? Y/n\n";
            char playAgain;
            std::cin >> playAgain;
            if (playAgain == 'n') {
                gameStatus = false;
            }else {
                board.resetGame();
                board.printBoard();
            }
        }
    }
}