#include "Point.h"

Point::Point(const unsigned int xMapSize,
           const unsigned int yMapSize) {
    positionX = xMapSize/2;
    positionY = yMapSize/2;
}

const int& Point::getPositionX() const {
    return positionX;
}
        
const int& Point::getPositionY() const {
    return positionY;
}

const std::string& Point::getPointChar() const {
    return sPoint;
}