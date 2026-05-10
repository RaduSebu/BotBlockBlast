#include "manager.h"
#include <iostream>

bool manager::calculate(bool board[8][8]) {
    bool x[8];
    bool y[8];
    bool isBreaking = false;

    for (int i = 0; i < 8; i++) {
        x[i] = true;
        y[i] = true;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == false) {
                x[i] = false;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[j][i] == false) {
                y[i] = false;
            }
        }
    }

    for (int i = 0; i < 8; i++) {
        if (x[i]) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = false;
            }
            isBreaking = true;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (y[i]) {
            for (int j = 0; j < 8; j++) {
                board[j][i] = false;
            }
            isBreaking = true;
        }
    }

    return isBreaking;
}

void manager::printBoard(bool board[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

bool manager::canPlacePiece(bool board[8][8], int posx, int posy, Piece piece) {
    if (posx + piece.lenx > 8 || posy + piece.leny > 8) {
        return false;
    }

    for (int i = 0; i < piece.lenx; i++) {
        for (int j = 0; j < piece.leny; j++) {
            if (board[posx + i][posy + j] && piece.shape[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void manager::placePiece(bool board[8][8], int posx, int posy, Piece piece) {
    for (int i = 0; i < piece.lenx; i++) {
        for (int j = 0; j < piece.leny; j++) {
            board[posx + i][posy + j] = piece.shape[i][j] || board[posx + i][posy + j];
        }
    }
}

void manager::findBestMove(bool board[8][8], Piece piece1, Piece piece2, Piece piece3) {
    Piece pieces[3] = {piece1, piece2, piece3};

    int bestScore = -1;
    int bestOrder[3];
    int bestX[3];
    int bestY[3];

    int orders[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };

    // de facut pe viitor
}

