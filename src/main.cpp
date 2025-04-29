#include<raylib.h>
#include<iostream>
#include<vector>
#include <random>
#include "simulation.hpp"
int main(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(1, 4);
  Color green={102,191,255,255};
  InitWindow(750,750, "Game of Life");
  SetTargetFPS(12);
  Simulation simu(750,750,25);
  simu.fillout();
    while(WindowShouldClose()==false){
      simu.rules();
      BeginDrawing();
      ClearBackground(green);
      simu.Drow();
      EndDrawing();
    }
    CloseWindow();
    return 0;
}