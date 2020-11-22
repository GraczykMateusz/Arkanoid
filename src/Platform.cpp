#include "Platform.h"

Platform::Platform(const unsigned int mapX) {
    this->mapX = mapX;
}

std::vector<char>& Platform::getPlatform() {
    return platformVec;
}

const int Platform::getPositionX() const {
    return positionX;
}

const int Platform::getPositionY() const {
    return positionY;
}

void Platform::moveRight() {
    if(positionX < mapX - platformVec.size() - 1)
        ++positionX;
}

void Platform::moveLeft() {
    const int leftFrame = 0;
    
    if(positionX > leftFrame + 1)
        --positionX;
}