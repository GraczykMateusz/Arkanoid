#include "Map.h"

Map::Map(const unsigned int xSize,
         const unsigned int ySize) {
  this->xSize = xSize;
  this->ySize = ySize;
 
  map.resize(ySize, std::vector<std::string>(xSize));

  create();
}

void Map::create() {  
  int row = 0;
  int column = 0;

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

void Map::display() {
  int row = 0;
  int column = 0;

  clear();

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last rows
      if(row == 0 || row == ySize -1) {
        printw(map[y][x].data());
      } else {
        //First and last columns
        if(column == 0 || column == xSize - 1) {
          printw(map[y][x].data());
        } else {
          printw(map[y][x].data());
        }
      }
      ++column;
    }
    printw("\n");
    column = 0;
    ++row;
  }
  refresh();
  waitMillisec(100);
}

void Map::controlHelp() const {
  clear();

  printw("Move LEFT  -> 4\n");
  printw("Move RIGHT -> 6\n");
  printw("Any other button -> Pause platform\n");
  printw("Exit -> Esc 2x");

  refresh();
  waitMillisec(4000);
}

void Map::startTimer() const {
  display3();
  waitMillisec(1000);

  display2();
  waitMillisec(1000);

  display1();
  waitMillisec(1000);
}

void Map::removePlatform(const std::vector<std::string> platformVec,
                         const int positionX,
                         const int positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    map[positionY][currentPositionX] = " ";
    ++currentPositionX;
  }
}

void Map::setPlatform(const std::vector<std::string> platformVec,
                      const int positionX,
                      const int positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    map[positionY][currentPositionX] = c;
    ++currentPositionX;
  }
}

void Map::display3() const {
  clear();

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
  
  refresh();
}

void Map::display2() const {
  clear();

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

  refresh();
}

void Map::display1() const {
  clear();

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

  refresh();
}

void Map::waitMillisec(const unsigned int time) const {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}