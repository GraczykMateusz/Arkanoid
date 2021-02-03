#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
    const std::string sPoint = "+";
    int positionX, positionY;

    public:
        //Constructor and destuctor
        Point(const unsigned int xMapSize,
             const unsigned int yMapSize);
        ~Point() = default;

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const std::string& getPointChar() const;
};
#endif /*BALL_H*/