#include "Point.h"

const std::string Point::sPoint = "+";

Point::Point(const unsigned int index) {
    this->index = index;

    setPositionXY();
}

void Point::setPositionXY() {
    const int offset = 3;

    if(index < 12) {
        positionX = index * offset + offset;
        positionY = 3;
    }
    else if(index >= 12) {
        positionX = (index-12) * offset + offset;
        positionY = 6;
    }
}

const int& Point::getPositionX() const {
    return positionX;
}
        
const int& Point::getPositionY() const {
    return positionY;
}

const std::string& Point::getSymbol() {
    return sPoint;
}