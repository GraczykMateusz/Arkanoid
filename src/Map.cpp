#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>

#include "Map.h"

Map::Map(const unsigned int xSize,
         const unsigned int ySize) {
  this->xSize = xSize;
  this->ySize = ySize;
 
  map.resize(xSize, std::vector<const char*>(ySize));

  create();
}

void Map::create() {  
  int row = 0;
  int column = 0;

  const char* hash = "#";
  const char* blank = " ";

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last rows
      if(row == 0 || row == ySize -1) {
        map[y][x] = hash;
      } else {
        //First and last columns
        if(column == 0 || column == xSize - 1) {
          map[y][x] = hash;
        } else {
          map[y][x] = blank;
        }
      }
      ++column;
    }
    column = 0;
    ++row;
  }
}

void Map::display() const {
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  printw("\n");

  int row = 0;
  int column = 0;

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last rows
      if(row == 0 || row == ySize -1) {
        printw(map[y][x]);
      } else {
        //First and last columns
        if(column == 0 || column == xSize - 1) {
          printw(map[y][x]);
        } else {
          printw(map[y][x]);
        }
      }
      ++column;
    }
    printw("\n");
    column = 0;
    ++row;
  }
  printw("Move (Left -> 4 / Right -> 6):");
  std::this_thread::sleep_for(std::chrono::seconds(1000));
}

void Map::startTimer() const {
  clear();
  waitSec();

  display3();
  refresh();
  waitSec();
  clear();

  display2();
  refresh();
  waitSec();
  clear();

  display1();
  refresh();
  waitSec();
  clear();  
}

void Map::removePlatform(const std::vector<const char*> platformVec,
                         const int positionX,
                         const int positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    map[positionY][currentPositionX] = " ";
    ++currentPositionX;
  }
}

void Map::setPlatform(const std::vector<const char*> platformVec,
                      const int positionX,
                      const int positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    map[positionY][currentPositionX] = c;
    ++currentPositionX;
  }
}

void Map::display3() const {
  printw("########################################\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#                       ########       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("########################################\n");
}

void Map::display2() const {
  printw("########################################\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("#              ###########             #\n");
  printw("#            ###############           #\n");
  printw("#           #################          #\n");
  printw("#         ######         ######        #\n");
  printw("#        ######           ######       #\n");
  printw("#        #####             #####       #\n");
  printw("#        #####             #####       #\n");
  printw("#                         #####        #\n");
  printw("#                       #####          #\n");
  printw("#                     ######           #\n");
  printw("#                   ######             #\n");
  printw("#                 ######               #\n");
  printw("#              #######                 #\n");
  printw("#             ######                   #\n");
  printw("#           ######                     #\n");
  printw("#          ######                      #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#         ######################       #\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("########################################\n");
            
}

void Map::display1() const {
  printw("########################################\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("#                ###########           #\n");
  printw("#              #############           #\n");
  printw("#             ##############           #\n");
  printw("#           ################           #\n");
  printw("#         ##################           #\n");
  printw("#        ###################           #\n");
  printw("#       ####################           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                 ##########           #\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("########################################\n");
}

void Map::waitSec(const unsigned int time) const {
    std::this_thread::sleep_for(std::chrono::seconds(time));
}