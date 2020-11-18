#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
  /*The class is responsible for everything */
  private:
    //Variables
    int xSize, ySize;
    std::vector<std::vector<char>> map;

    //Methods
    void create();

    void display3() const;
    void display2() const;
    void display1() const;

  public:
    //Constructor and destuctor
    Map(const unsigned int xSize, const unsigned int ySize);
    ~Map() = default;

    //Methods
    void display() const;

    void startTimer() const; 
};

#endif /*MAP_H*/
