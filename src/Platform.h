#ifndef PLATFORM_H
#define PLATFORM_H

#define PLATFORM_LENGTH 8

#include <vector>
#include <string>

typedef std::vector<std::string> vec_str;

class Platform {
    /*The class is responsible for create a model of platform*/

    //Position
    int positionX;
    int positionY;

    //Right frame position
    int rightFrame;

    //Platform
    vec_str platformVec = vec_str(PLATFORM_LENGTH, "=");

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

    vec_str& getPlatform();
};
#endif /*PLATFORM_H*/