#include "manager.h"
#include <iostream>

int manager::calculate(bool board[8][8]) {
    bool x[8];
    bool y[8];
    int score = 0;;

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
            score++;
        }
    }

    for (int i = 0; i < 8; i++) {
        if (y[i]) {
            for (int j = 0; j < 8; j++) {
                board[j][i] = false;
            }
            score++;
        }
    }

    return score;
}

void manager::copyBoard(bool from[8][8], bool to[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            to[i][j] = from[i][j];
        }
    }
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

void manager::search(
    bool board[8][8],
    Piece pieces[3],
    int order[3],
    int depth,
    int score,
    int currentX[3],
    int currentY[3],
    int& bestScore,
    int bestOrder[3],
    int bestX[3],
    int bestY[3]
) {
    if (depth == 3) {
        if (score > bestScore) {
            bestScore = score;

            for (int i = 0; i < 3; i++) {
                bestOrder[i] = order[i];
                bestX[i] = currentX[i];
                bestY[i] = currentY[i];
            }
        }
        return;
    }

    Piece piece = pieces[order[depth]];
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if (!canPlacePiece(board, x, y, piece)) {
                continue;
            }
            bool newBoard[8][8];
            copyBoard(board, newBoard);
            placePiece(newBoard, x, y, piece);
            int gainedScore = calculate(newBoard);
            currentX[depth] = x;
            currentY[depth] = y;
            search(
                newBoard,
                pieces,
                order,
                depth + 1,
                score + gainedScore,
                currentX,
                currentY,
                bestScore,
                bestOrder,
                bestX,
                bestY
            );
        }
    }
}

manager::Move manager::findBestMove(
    bool board[8][8],
    Piece piece1,
    Piece piece2,
    Piece piece3
) {
    Piece pieces[3] = {
        piece1,
        piece2,
        piece3
    };

    int orders[6][3] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1},
        {2, 1, 0}
    };

    int bestScore = -1;

    int bestOrder[3] = {-1, -1, -1};
    int bestX[3] = {-1, -1, -1};
    int bestY[3] = {-1, -1, -1};

    for (int i = 0; i < 6; i++) {

        int currentX[3] = {-1, -1, -1};
        int currentY[3] = {-1, -1, -1};

        search(
            board,
            pieces,
            orders[i],
            0,
            0,
            currentX,
            currentY,
            bestScore,
            bestOrder,
            bestX,
            bestY
        );
    }

    Move result;

    for (int i = 0; i < 3; i++) {
        result.order[i] = bestOrder[i];
        result.x[i] = bestX[i];
        result.y[i] = bestY[i];
    }

    return result;
}

void manager::printMove(Move move) {
    for (int i = 0; i < 3; i++) {
        std::cout << "Move " << i + 1 << ": "
                  << "piece = " << move.order[i]
                  << ", x = " << move.x[i]
                  << ", y = " << move.y[i]
                  << std::endl;
    }
}