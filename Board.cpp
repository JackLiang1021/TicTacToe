#include "Board.h"
#include "Letters.h"
#include <iostream>
#include <format>

Board::Board() :winner('e'), m_board{} {
    std::cout << Board::ROW << "x" << Board::COL << std::endl;
    for (int i = 0; i < Board::ROW; i++) {
        for (int j = 0; j < Board::COL; j++) {
            m_board[i][j] = 'e';
        }
    }
}

void Board::resetBoard() {
    for (int i = 0; i < Board::ROW; i++) {
        for (int j = 0; j < Board::COL; j++) {
            m_board[i][j] = 'e';
        }
    }
}

void Board::resetTurn() {
    turn = false;
}

void Board::resetWinner() {
    winner = 'e';
}



void Board::resetGame() {
    resetBoard();
    resetTurn();
    resetWinner();
}


bool Board::checkWin() {
    if (winner == 'e') {
        for (int i = 0; i < ROW; i++) {
            if ((m_board[i][0] == 'x' && m_board[i][1] == 'x' && m_board[i][2] == 'x')
                || (m_board[i][0] == 'o' && m_board[i][1] == 'o' && m_board[i][2] == 'o' )) {
                winner = m_board[i][0];
                return true;
            }
        }

        for (int i = 0; i < COL; i++) {
            if ((m_board[0][i] == 'x' && m_board[1][i] == 'x' && m_board[2][i] == 'x')
                || (m_board[0][i] == 'o' && m_board[1][i] == 'o' && m_board[2][i] == 'o')) {
                winner = m_board[0][i];
                return true;
            }

        }
        if (m_board[0][0] != 'e' &&
        m_board[0][0] == m_board[1][1] &&
        m_board[1][1] == m_board[2][2]) {
            winner = m_board[0][0];
            return true;
        }

        if (m_board[0][2] != 'e' &&
            m_board[0][2] == m_board[1][1] &&
            m_board[1][1] == m_board[2][0]) {
            winner = m_board[0][2];
            return true;
            }
    }


    return false;
}

bool Board::checkTie() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (m_board[i][j] == 'e') {
                return false;
            }
        }
    }
    winner = 't';
    return true;
}


char Board::getWinner() const {
    return winner;
}

bool Board::isValidMove(const int row, const int col) const {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        std::cout<<"Out of Bounds! Try again! \n";
        return false;
    }
    if (m_board[row][col] != 'e') {
        std::cout<<"Someone is already there! Try again! \n";
        return false;
    }
    return true;
}

void Board::turnChange() {
    turn = !turn;
}

void Board::applyMove(const int row, const int col) {
    m_board[row][col] = turn ? 'x' : 'o';

}

void Board::logMove(int row, int col) const {
    const std::string result = std::format("Played {} at {} , {}",turn ? 'x' : 'o', row, col );
    std::cout << result << std::endl;
}


void Board::playMove(const int row, const int col) {
    if (isValidMove(row, col)) {
        applyMove(row, col);
        printBoard();
        logMove(row, col);
        turnChange();
    }
}


void Board::printBoard() const {
    Letters letters;

    for (int i = 0; i < ROW; ++i) {

        std::vector<std::vector<std::string>> rowLetters;

        for (int j = 0; j < COL; ++j) {
            const char c = m_board[i][j];

            rowLetters.push_back(letters.getLetter(c));
        }

        for (int k = 0; k < 4; ++k) {
            for (int j = 0; j < COL; ++j) {
                if (j < 2) {
                    std::cout << rowLetters[j][k] << " | ";
                }else {
                    std::cout << rowLetters[j][k] << " ";
                }
            }
            std::cout << "\n";
        }

        if (i < 2) {
            std::cout << std::string(COL * 12, '-') << "\n";
        }
    }
}


