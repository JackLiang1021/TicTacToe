//
// Created by darka on 5/29/2025.
//

#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <string>


class Board {
public:
    static constexpr int ROW = 3;
    static constexpr int COL = 3;
    static constexpr int getRows() { return ROW; }
    static constexpr int getCols() { return COL; }

    // Resets
    void resetGame();
    void resetBoard();
    void resetTurn();
    void resetWinner();

    // Game End Check
    bool checkTie();
    bool checkWin();

    // Winner check
    [[nodiscard]] char getWinner() const;

    // Moves
    void playMove(int row, int col);
    [[nodiscard]] bool isValidMove(int row, int col) const;
    void turnChange();
    void applyMove(int row, int col);

    // Graphics
    void logMove(int row, int col) const;
    void printBoard() const;
    Board();


private:
    char winner;
    bool turn = false;
    std::array<std::array<char, COL>, ROW> m_board;

};



#endif //BOARD_H