#include "Platform.h"

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
    ++positionX;
}

void Platform::moveLeft() {
    --positionX;
}