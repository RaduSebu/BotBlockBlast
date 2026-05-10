#ifndef BOTBLOCKBLAST_MANAGER_H
#define BOTBLOCKBLAST_MANAGER_H


class manager {
public:
    struct Piece {
        bool shape[8][8];
        int lenx, leny;
    };

    manager();
    static bool calculate(bool board[8][8]);
    static void printBoard(bool board[8][8]);
    static bool canPlacePiece(bool board[8][8], int posx, int posy, Piece piece);
    static void placePiece(bool board[8][8], int posx, int posy, Piece piece);
    static void findBestMove(bool board[8][8], Piece piece1, Piece piece2, Piece piece3);
};


#endif //BOTBLOCKBLAST_MANAGER_H