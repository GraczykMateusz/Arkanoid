#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <string>

#include "Point.h"

typedef std::vector<std::string> vec_str;

class Map {
  /*The class is responsible for everything
   connected with creating and displaying map*/
  private:
    //Size and map
    int xSize, ySize;
    std::vector<vec_str> mapFields;

    //Numbers in a timer
    void display3() const;
    void display2() const;
    void display1() const;

    //Methods
    void create();

    void waitMillisec(const unsigned int& time) const;

  public:
    //Constructor and destuctor
    Map(const unsigned int& xSize,
        const unsigned int& ySize);
    ~Map() = default;
    
    //Platform
    void setPlatform(const vec_str& platformVec,
                     const int& positionX,
                     const int& positionY);

    void removePlatform(const vec_str& platformVec,
                        const int& positionX,
                        const int& positionY);

    //Ball
    void setBall(const std::string& cBall,
                 const int& positionX,
                 const int& positionY);

    void removeBall(const int& positionX,
                    const int& positionY);

    //Points
    void setPoints(std::vector<std::shared_ptr<Point>>& points);

    void removePoint(std::vector<std::shared_ptr<Point>>& points,
                     const int& positionX,
                     const int& positionY);

    //Methods
    void display();

    void displayGameOver() const;

    void startTimer() const;

    void controlHelp() const;

    //Getters
    const int& getXSize() { return xSize; }

    const std::vector<vec_str>& getMapFields() const;
};
#endif /*MAP_H*/
