#include "simulation.hpp"
#include<vector>
#include<utility>
#include<random>

void Simulation::Drow()
{
    grid.Drow();
}

void Simulation::setval(int row, int col, int val)
{
    grid.setValue(row, col ,val);
}

int Simulation::checkNei(int row, int col)
{
    int countnei=0;
    vector<pair<int,int>> ve;
    ve.emplace_back(1,0);
    ve.emplace_back(-1,0);
    ve.emplace_back(0,-1);
    ve.emplace_back(0,1);
    ve.emplace_back(-1,-1);
    ve.emplace_back(-1,1);
    ve.emplace_back(1,1);
    ve.emplace_back(1,-1);

    for(auto &ofset:ve){
        int new_row=(row+ofset.first+grid.getRows())%grid.getRows();
        int new_col=(col+ofset.second+grid.getcols())%grid.getcols();
        countnei+=grid.getval(new_row,new_col);
    }
    return countnei;
}

void Simulation::rules()
{
for(int i=0; i<grid.getRows(); i++){
    for(int j=0; j<grid.getcols(); j++){
        int liven = checkNei(i,j);
        int currVal=grid.getval(i,j);
        if(currVal==1){
          if(liven<2 || liven>3){
            tempgrid.setValue(i,j,0);
          }else{
            tempgrid.setValue(i,j,1);
          }
        }
        else{
            if(liven==3){
            tempgrid.setValue(i,j,1);
            }else{
            tempgrid.setValue(i,j,0);
            }
        }
    }
}
grid=tempgrid;
}

void Simulation:: fillout()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 4);
    for(int i=0; i<grid.getRows(); i++){
        for(int j=0; j<grid.getcols(); j++){
          int randomval=distrib(gen);
          if(randomval==3){
            setval(i,j,1);
          }
          else{
            setval(i,j,0);
          }
        }
      }
}
