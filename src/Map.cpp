#include <iostream>
#include <thread>
#include <chrono>

#include "systemClear.h"
#include "Map.h"

Map::Map(const unsigned int xSize, const unsigned int ySize) {
  this->xSize = xSize;
  this->ySize = ySize;
 
  map.resize(xSize, std::vector<char>(ySize));

  create();
}

void Map::create() {  
  int row = 0;
  int column = 0;

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last lines
      if(row == 0 || row == ySize -1) {
        map[y][x] = '#';
      } else {
        //First and last column
        if(column == 0 || column == xSize - 1) {
          map[y][x] = '#';
        } else {
          map[y][x] = ' ';
        }
      }
      ++column;
    }
    column = 0;
    ++row;
  }
}

void Map::display() const {
  system("stty cooked");
  
  std::cout << '\n';

  int row = 0;
  int column = 0;

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last lines
      if(row == 0 || row == ySize -1) {
        std::cout << map[y][x];
      } else {
        //First and last column
        if(column == 0 || column == xSize - 1) {
          std::cout << map[y][x];
        } else {
          std::cout << map[y][x];
        }
      }
      ++column;
    }
    std::cout << '\n';
    column = 0;
    ++row;
  }
  //system("stty raw");
}

void Map::startTimer() const {
  system("stty cooked");
  systemClear();
  waitSec();

  display3();
  waitSec();
  systemClear();

  display2();
  waitSec();
  systemClear();

  display1();
  waitSec();
  systemClear();
}

void Map::setPlatform(const std::vector<char> platformVec, const int positionX, const int positionY) {
  std::cout << positionX << std::endl;
  std::cout << positionX << std::endl;

  for(auto& x : platformVec)
    std::cout << x << std::endl;
}

void Map::display3() const {
  std::cout << "########################################\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#                       ########       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "########################################\n";
}

void Map::display2() const {
  std::cout << "########################################\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "#              ###########             #\n"
            << "#            ###############           #\n"
            << "#           #################          #\n"
            << "#         ######         ######        #\n"
            << "#        ######           ######       #\n"
            << "#        #####             #####       #\n"
            << "#        #####             #####       #\n"
            << "#                         #####        #\n"
            << "#                       #####          #\n"
            << "#                     ######           #\n"
            << "#                   ######             #\n"
            << "#                 ######               #\n"
            << "#              #######                 #\n"
            << "#             ######                   #\n"
            << "#           ######                     #\n"
            << "#          ######                      #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#         ######################       #\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "########################################\n";
            
}

void Map::display1() const {
  std::cout << "########################################\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "#                ###########           #\n"
            << "#              #############           #\n"
            << "#             ##############           #\n"
            << "#           ################           #\n"
            << "#         ##################           #\n"
            << "#        ###################           #\n"
            << "#       ####################           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                 ##########           #\n"
            << "#                                      #\n"
            << "#                                      #\n"
            << "########################################\n";
}

void Map::waitSec(const unsigned int time) const {
    std::this_thread::sleep_for(std::chrono::seconds(time));
}