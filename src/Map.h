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
    std::vector<std::vector<std::string>> mapFields;

    //Numbers in a timer
    void display3() const;
    void display2() const;
    void display1() const;

    //Methods
    void create();

    void waitMillisec(const unsigned int time) const;

  public:
    //Constructor and destuctor
    Map(const unsigned int xSize,
        const unsigned int ySize);
    ~Map() = default;
    
    //Platform
    void setPlatform(const std::vector<std::string> platformVec,
                     const int positionX,
                     const int positionY);

    void removePlatform(const std::vector<std::string> platformVec,
                        const int positionX,
                        const int positionY);

    //Ball
    void setBall(const std::string cBall,
                 const int positionX,
                 const int positionY);

    void removeBall(const int positionX,
                    const int positionY);

    //Methods
    void display();

    const int& getXSize() { return xSize; }

    const std::vector<std::vector<std::string>>& getMapFields() const { return mapFields; }

    void startTimer() const;

    void controlHelp() const;
};
#endif /*MAP_H*/
