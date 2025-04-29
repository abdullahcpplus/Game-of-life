#pragma once
#include "grid.hpp"
#include<vector>
using namespace std;
class Simulation{
   Grid grid;
   Grid tempgrid;
    public:
    Simulation(int width, int height, int Cell)
    : grid(width, height, Cell),tempgrid(width,height,Cell){};
    void Drow();
    void setval(int row, int col, int val);
    int checkNei(int row, int col);
    void rules();
    void fillout();
    
};