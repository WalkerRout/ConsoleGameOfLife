#include <iostream>
#include <chrono>
#include <thread>
#include "GOL/GOL.h"



void runGame(){
  Life::GameOL gameOfLife;
  gameOfLife.display();
  while(1){
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    printf("\e[1;1H\e[2J");
    gameOfLife.progress();
    gameOfLife.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    std::cout << std::flush;
  }
}



int main() {
  runGame();
  return 0;
}