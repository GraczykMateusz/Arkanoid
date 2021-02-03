#include "Platform.h"

Platform::Platform(const unsigned int mapX) {
    rightFrame = mapX;
}

std::vector<std::string>& Platform::getPlatform() {
    return platformVec;
}

const int Platform::getPositionX() const {
    return positionX;
}

const int Platform::getPositionY() const {
    return positionY;
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