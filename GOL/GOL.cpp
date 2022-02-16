#include "GOL.h"

namespace Life {

  GameOL::GameOL(){
    initGrid();
  }



  void GameOL::initGrid(){
    srand(time(0));

    for(int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){

        if(((double) rand() / RAND_MAX) < 0.2){
          grid[i][j] = 0b1;
        } else {
          grid[i][j] = 0b0;
        }

      }
    }

  } // end of GameOL::initGrid



  void GameOL::progress(){
    unsigned char newGrid[ROWS][COLS];

    for(int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){

        unsigned char neighbours = 0;

        for(int y = -1; y <= 1; y++){
          for(int x = -1; x <= 1; x++){
            neighbours += grid[i + y][j + x] & 1;
          }
        }

        neighbours -= grid[i][j] & 1;

        if ((grid[i][j] == 1) && (neighbours < 2)) newGrid[i][j]      = 0;
        else if ((grid[i][j] == 1) && (neighbours >  3)) newGrid[i][j] = 0;
        else if ((grid[i][j] == 0) && (neighbours == 3)) newGrid[i][j] = 1;
        else newGrid[i][j] = grid[i][j];
      }
    }

    for(int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){
        grid[i][j] = newGrid[i][j];
      }
    }

  } // end of GameOL::progress



  void GameOL::display(){

    for(int i = 0; i < ROWS; i++){
      for(int j = -1; j < COLS + 1; j++){

        if(j == -1 || j == COLS){
          std::cout << "|";
        } else {

          if((grid[i][j] & 1) == 1){
            printf(" 0 ");
          } else {
            printf("   ");
          }

        }
      }

      std::cout << "\n";
    }
    
  } // end of GameOL::display

}