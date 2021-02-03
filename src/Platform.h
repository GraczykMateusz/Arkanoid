#ifndef PLATFORM_H
#define PLATFORM_H

#define PLATFORM_LENGTH 8

#include <vector>
#include <string>

class Platform {
    int positionX = 20;
    const int positionY = 20;

    int rightFrame;

    std::vector<std::string> platformVec = std::vector<std::string>(PLATFORM_LENGTH, "=");

public:
    Platform(const unsigned int mapX);
    ~Platform() = default;

    const int getPositionX() const;
    const int getPositionY() const;

    std::vector<std::string>& getPlatform();

    void moveRight();
    void moveLeft();
};

#endif /*PLATFORM_H*/