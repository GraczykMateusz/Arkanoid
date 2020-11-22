#ifndef PLATFORM_H
#define PLATFORM_H

#include <vector>

class Platform {
    int positionX = 20;
    const int positionY = 20;

    int mapX;

    std::vector<char> platformVec = std::vector<char>(8, '=');

public:
    Platform(const unsigned int mapX);
    ~Platform() = default;

    const int getPositionX() const;
    const int getPositionY() const;

    std::vector<char>& getPlatform();

    void moveRight();
    void moveLeft();
};

#endif /*PLATFORM_H*/