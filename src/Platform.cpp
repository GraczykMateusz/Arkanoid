#include "Platform.h"

Platform::Platform(const unsigned int& mapX,
                   const unsigned int& mapY) {
    rightFrame = mapX;

    positionX = mapX / 2;
    positionY = mapY - 2;
}

void Platform::moveRight() {
    if(positionX < rightFrame - platformVec.size() - 1)
        ++positionX;
}

void Platform::moveLeft() {
    const int leftFrame = 0;
    
    if(positionX > leftFrame + 1)
        --positionX;
}

std::vector<std::string>& Platform::getPlatform() {
    return platformVec;
}

const int& Platform::getPositionX() const {
    return positionX;
}

const int& Platform::getPositionY() const {
    return positionY;
}