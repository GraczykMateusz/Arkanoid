#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
  /*The class is responsible for everything */
  private:
    //Variables
    int xSize, ySize;
    std::vector<std::vector<char>> map;

  public:
    //Constructor and destuctor
    Map(const unsigned int xSize, const unsigned int ySize);
    ~Map() = default;

    //Methods
    void create();
    void display();

};

#endif /*MAP_H*/
