#include <iostream>
#include "manager.h"
bool board[8][8] = {
    {0,0,0,1,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0}
};

manager::Piece piece1{
            {
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}
            },
            3, 3
        };

manager::Piece piece2{
            {
                {0, 1},
                {1, 1}
            },
            2, 2
        };

manager::Piece piece3{
            {
                {1},
                {1},
                {1}
            },
            3, 1
        };


int main() {
    manager::findBestMove(board, piece1, piece2, piece3);
}