#include "grid.hpp"
#include<raylib.h>
#include<random>
void Grid::Drow()
{
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            Color color=vec[row][col]?Color{255,161,0,255} :Color{0,82,172,255};
            DrawRectangle(col*cellSize, row*cellSize,cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::setValue(int row, int col, int value)
{
    if(row>=0 && row<rows && col>=0 && col<cols)
    vec[row][col]=value;
}

int Grid::getval(int row, int col)
{
   if(isbound(row,col)){
    return vec[row][col];
   }
   return 0;
}


bool Grid::isbound(int row, int col)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols)
    {
        return true;
    }
    return false;
}
