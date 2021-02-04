#include "Ball.h"

Ball::Ball(const unsigned int& xMapSize,
           const unsigned int& yMapSize) {
    positionX = xMapSize/2 + 9;
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

void Ball::move(const std::vector<std::vector<std::string>>& mapFields,
                const unsigned int& xMapSize,
                const unsigned int& yMapSize,
                bool& isGameOver) {
    bool isSpace = true;

    //The ball under a platform
    if(positionY == yMapSize - 2)
        isGameOver = true;

    if(movingX == Movment::left && movingY == Movment::top) {
        //Left or top wall
        if(mapFields[positionY][positionX - 1] == "#" || mapFields[positionY - 1][positionX] == "#") {
            //Left-top corner
            if(mapFields[positionY][positionX - 1] == "#" && mapFields[positionY - 1][positionX] == "#") {
                ++positionX;
                ++positionY;
                movingX = Movment::right;
                movingY = Movment::bottom;
            }
            //Left wall
            else if(mapFields[positionY][positionX - 1] == "#") {
                ++positionX;
                --positionY;
                movingX = Movment::right;
            }
            //Top wall
            else if(mapFields[positionY - 1][positionX] == "#") {
                --positionX;
                ++positionY;
                movingY = Movment::bottom;
            }
            isSpace = false;
        }
    }
    else if(movingX == Movment::right && movingY == Movment::top) {
        //Right or top wall
        if(mapFields[positionY][positionX + 1] == "#" || mapFields[positionY - 1][positionX] == "#") {
            //Right-top corner
            if(mapFields[positionY][positionX + 1] == "#" && mapFields[positionY - 1][positionX] == "#") {
                --positionX;
                ++positionY;
                movingX = Movment::left;
                movingY = Movment::bottom;
            }
            //Right wall
            else if(mapFields[positionY][positionX + 1] == "#") {
                --positionX;
                --positionY;
                movingX = Movment::left;
            }
            //Top wall
            else if(mapFields[positionY - 1][positionX] == "#") {
                ++positionX;
                ++positionY;
                movingY = Movment::bottom;
            }
            isSpace = false;
        }
    }
    else if(movingX == Movment::left && movingY == Movment::bottom) {
        //Right platform corner
        if(mapFields[positionY + 1][positionX - 1] == "=" && mapFields[positionY + 1][positionX] == " ") {
            ++positionX;
            --positionY;
            movingX = Movment::right;
            movingY = Movment::top;

            isSpace = false;
        }
        //Left wall or platform
        else if(mapFields[positionY][positionX - 1] == "#" || mapFields[positionY + 1][positionX] == "=") {
            //Left wall-platform corner
            if(mapFields[positionY][positionX - 1] == "#" && mapFields[positionY + 1][positionX] == "=") {
                ++positionX;
                --positionY;
                movingX = Movment::right;
                movingY = Movment::top;
            }
            //Left wall
            else if(mapFields[positionY][positionX - 1] == "#") {
                ++positionX;
                ++positionY;
                movingX = Movment::right;
            }
            //Platform
            else if(mapFields[positionY + 1][positionX] == "=") {
                --positionX;
                --positionY;
                movingY = Movment::top;
            }
            isSpace = false;
        }
    }
    else if(movingX == Movment::right && movingY == Movment::bottom) {
        //Left platform corner
        if(mapFields[positionY + 1][positionX + 1] == "=" && mapFields[positionY + 1][positionX] == " ") {
            --positionX;
            --positionY;
            movingX = Movment::left;
            movingY = Movment::top;

            isSpace = false;
        }
        //Right wall or platform
        else if(mapFields[positionY][positionX + 1] == "#" || mapFields[positionY + 1][positionX] == "=") {
            //(Right wall-platform) corner
            if(mapFields[positionY][positionX + 1] == "#" && mapFields[positionY + 1][positionX] == "=") {
                --positionX;
                --positionY;
                movingX = Movment::left;
                movingY = Movment::top;
            }
            //Right wall
            else if(mapFields[positionY][positionX + 1] == "#") {
                --positionX;
                ++positionY;
                movingX = Movment::left;
            }
            //Platform
            else if(mapFields[positionY + 1][positionX] == "=") {
                ++positionX;
                --positionY;
                movingY = Movment::top;
            }
            isSpace = false;
        }
    }
    //Free space
    if(isSpace) {
        if(movingX == Movment::left && movingY == Movment::top) {
            --positionX;
            --positionY;
        }
        else if(movingX == Movment::right && movingY == Movment::top) {
            ++positionX;
            --positionY;
        }
        else if(movingX == Movment::left && movingY == Movment::bottom) {
            --positionX;
            ++positionY;
        }
        else if(movingX == Movment::right && movingY == Movment::bottom) {
            ++positionX;
            ++positionY;
        }
    }
}