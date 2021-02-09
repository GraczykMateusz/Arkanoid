#include "Map.h"

Map::Map(const unsigned int& xSize,
         const unsigned int& ySize) {
  this->xSize = xSize;
  this->ySize = ySize;
 
  mapFields.resize(ySize, std::vector<std::string>(xSize));

  create();
}

void Map::create() {  
  int row = 0;
  int column = 0;

  for(int y = 0; y < ySize; ++y) {
    for(int x = 0; x < xSize; ++x) {
      //First and last rows
      if(row == 0 || row == ySize -1) {
        mapFields[y][x] = "#";
      } else {
        //First and last columns
        if(column == 0 || column == xSize - 1) {
          mapFields[y][x] = "#";
        } else {
          mapFields[y][x] = " ";
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
        printw(mapFields[y][x].data());
      } else {
        //First and last columns
        if(column == 0 || column == xSize - 1) {
          printw(mapFields[y][x].data());
        } else {
          printw(mapFields[y][x].data());
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

void Map::removePlatform(const std::vector<std::string>& platformVec,
                         const int& positionX,
                         const int& positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    mapFields[positionY][currentPositionX] = " ";
    ++currentPositionX;
  }
}

void Map::setPlatform(const std::vector<std::string>& platformVec,
                      const int& positionX,
                      const int& positionY) {
  int currentPositionX = positionX;

  for(auto& c : platformVec) {
    mapFields[positionY][currentPositionX] = c;
    ++currentPositionX;
  }
}

void Map::removeBall(const int& positionX,
                     const int& positionY) {
  mapFields[positionY][positionX] = " ";
}

void Map::setBall(const std::string& cBall,
                  const int& positionX,
                  const int& positionY) {
  mapFields[positionY][positionX] = cBall;
}

void Map::removePoint(std::vector<std::shared_ptr<Point>>& points,
                      const int& positionX,
                      const int& positionY) {
  if(positionX != -1 && positionY != -1) {
    for(auto it = points.begin(); it != points.end(); it++) {
      if((*it)->getPositionY() == positionY &&
        (*it)->getPositionX() == positionX) {
        points.erase(it);
        break;
      }    
    }
    points.shrink_to_fit();

    mapFields[positionY][positionX] = " ";
  }
}

void Map::setPoints(std::vector<std::shared_ptr<Point>>& points) {
  for(int i = 0; i < points.size(); ++i) {
    auto y = points[i]->getPositionY();
    auto x = points[i]->getPositionX();

    auto symbol = points[i]->getSymbol();

    mapFields[y][x] = symbol;
  }
}

void Map::displayGameOver(unsigned int pointsCount) const {
  clear();

  printw("########################################\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("#  #######  #######  #      #  ######  #\n");
  printw("#  #        #     #  ##    ##  #       #\n");
  printw("#  #        #     #  # #  # #  #       #\n");
  printw("#  #        #     #  #  ##  #  #       #\n");
  printw("#  #   ###  #######  #      #  ######  #\n");
  printw("#  #     #  #     #  #      #  #       #\n");
  printw("#  #     #  #     #  #      #  #       #\n");
  printw("#  #     #  #     #  #      #  #       #\n");
  printw("#  #######  #     #  #      #  ######  #\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("#  #######  #     #  ######  ########  #\n");
  printw("#  #     #  #     #  #       #      #  #\n");
  printw("#  #     #  #     #  #       #      #  #\n");
  printw("#  #     #  #     #  ######  ########  #\n");
  printw("#  #     #  #     #  #       #   #     #\n");
  printw("#  #     #   #   #   #       #    #    #\n");
  printw("#  #     #    # #    #       #     #   #\n");
  printw("#  #######     #     ######  #      #  #\n");
  printw("#                                      #\n");
  printw("#                                      #\n");
  printw("########################################\n");
  printw("Your score: ");
  printw(std::to_string(pointsCount).data());
  printw("\nAny button to exit!");

  refresh();
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

void Map::waitMillisec(const unsigned int& time) const {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}

const std::vector<std::vector<std::string>>& Map::getMapFields() const {
  return mapFields;
}