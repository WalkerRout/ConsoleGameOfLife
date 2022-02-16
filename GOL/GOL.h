
#ifndef GOL_H
#define GOL_H

#include <stdio.h>
#include <iostream>

namespace Life{

  class GameOL {
    public:
      const static short ROWS = 25;
      const static short COLS = 25;

      GameOL();
      void initGrid();
      void progress();
      void display();

    private:
      unsigned char grid[ROWS][COLS];
  };

}

#endif