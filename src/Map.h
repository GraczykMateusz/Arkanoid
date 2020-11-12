#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
  /*The class is responsible for everything */
  private:
    //Variables
    int xSize, ySize;
    std::vector<std::vector<int>> map;

  public:
    //Constructor and destuctor
    Map(unsigned int widthX, unsigned int heightY)
      : xSize(widthX), ySize(heightY){};
    ~Map() = default;

    //Methods
    void create();
    void display();

};

#endif /*MAP_H*/
