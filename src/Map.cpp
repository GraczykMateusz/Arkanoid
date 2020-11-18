#include <iostream>

#include "Map.h"

Map::Map(const unsigned int xSize, const unsigned int ySize) {
  this->xSize = xSize;
  this->ySize = ySize;
 
  map.resize(xSize, std::vector<char>(ySize));

  create();
}

void Map::create() {
  system("stty cooked");
  
  std::cout << '\n';

  int row = 0;
  int column = 0;

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last lines
      if(row == 0 || row == ySize -1) {
        map[y][x] = '#';
        std::cout << map[y][x];
      } else {
        //First and last column
        if(column == 0 || column == xSize - 1) {
          map[y][x] = '#';
          std::cout << map[y][x];
        } else {
          map[y][x] = ' ';
          std::cout << map[y][x];
        }
      }
      ++column;
    }
    std::cout << '\n';
    column = 0;
    ++row;
  }
  std::cin >> row;
  system("stty raw");
}

void Map::display() {

}
