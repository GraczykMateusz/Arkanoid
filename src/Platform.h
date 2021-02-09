#ifndef PLATFORM_H
#define PLATFORM_H

#define PLATFORM_LENGTH 8

#include <vector>
#include <string>

class Platform {
    //Position
    int positionX;
    int positionY;

    //Right frame position
    int rightFrame;

    //Platform
    std::vector<std::string> platformVec = std::vector<std::string>(PLATFORM_LENGTH, "=");

public:
    //Constructor and destuctor
    Platform(const unsigned int& mapX,
             const unsigned int& mapY);
    ~Platform() = default;

    //Move
    void moveRight();
    void moveLeft();

    //Getters
    const int& getPositionX() const;
    const int& getPositionY() const;

    std::vector<std::string>& getPlatform();
};

#endif /*PLATFORM_H*/