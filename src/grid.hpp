#pragma once
#include<vector>
using namespace std;
class   Grid{
int rows, cols, cellSize;
vector<vector<int>> vec;
public:
Grid(int width, int height, int Cell)
: rows(width/Cell), cols(height/Cell), cellSize(Cell), vec(rows, vector<int>(cols,0)){};
void Drow();
void setValue(int row, int col, int value);
int getval(int row, int col);
bool isbound(int row, int col);
int getRows(){return rows;}
int getcols(){return cols;}
};
