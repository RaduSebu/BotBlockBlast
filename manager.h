#ifndef BOTBLOCKBLAST_MANAGER_H
#define BOTBLOCKBLAST_MANAGER_H


class manager {
public:
    struct Piece {
        bool shape[8][8];
        int lenx, leny;
    };

    struct Move {
        int order[3];
        int x[3];
        int y[3];
    };

    manager();
    static int calculate(bool board[8][8]);
    static void copyBoard(bool from[8][8], bool to[8][8]);
    static void printBoard(bool board[8][8]);
    static bool canPlacePiece(bool board[8][8], int posx, int posy, Piece piece);
    static void placePiece(bool board[8][8], int posx, int posy, Piece piece);
    static void search(
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
        );
    static Move findBestMove(bool board[8][8], Piece piece1, Piece piece2, Piece piece3);
    static void printMove(Move move);
};


#endif //BOTBLOCKBLAST_MANAGER_H