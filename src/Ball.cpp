#include "Ball.h"

Ball::Ball(const unsigned int xMapSize,
           const unsigned int yMapSize) {
    positionX = xMapSize/2;
    positionY = yMapSize/2;
}

const int& Ball::getPositionX() const {
    return positionX;
}
        
const int& Ball::getPositionY() const {
    return positionY;
}

const std::string& Ball::getBallChar() const {
    return sBall;
}

void Ball::move(const unsigned int xMapSize,
                const unsigned int yMapSize) {

}