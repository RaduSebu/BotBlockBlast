#include <iostream>
#include "manager.h"
bool board[8][8] = {
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1},
    {0,0,0,1,1,1,1,0},
    {0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0},
    {1,0,0,0,0,0,0,0}
};

manager::Piece piece1{
            {
                {1, 1},
                {1, 1}
            },
            2, 2
        };

manager::Piece piece2{
            {
                {0, 0, 1},
                {1, 1, 1}
            },
            2, 3
        };

manager::Piece piece3{
            {
                {0, 1, 0},
                {1, 1, 1},
            },
            2, 3
        };

int main() {
    manager::Move move = manager::findBestMove(board, piece1, piece2, piece3);
    manager::printMove(move);
}