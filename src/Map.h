#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <string>

class Map {
  /*The class is responsible for everything
   connected with creating and displaying map*/
  private:
    //Variables
    int xSize, ySize;
    std::vector<std::vector<std::string>> map;

    //Methods
    void create();

    void display3() const;
    void display2() const;
    void display1() const;

    void waitMillisec(const unsigned int time) const;

  public:
    //Constructor and destuctor
    Map(const unsigned int xSize,
        const unsigned int ySize);
    ~Map() = default;

    //Methods
    void display();
    void setPlatform(const std::vector<std::string> platformVec,
                     const int positionX,
                     const int positionY);

    void removePlatform(const std::vector<std::string> platformVec,
                        const int positionX,
                        const int positionY);

    void setBall(const int positionX, const int positionY);
    void removeBall(const int positionX, const int positionY);

    const int& getXSize() { return xSize; }

    void startTimer() const;

    void controlHelp() const;
};

#endif /*MAP_H*/
