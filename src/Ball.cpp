#include "Ball.h"

Ball::Ball(const unsigned int& xMapSize,
           const unsigned int& yMapSize) {
    std::random_device rd;
	std::mt19937 gen(rd());
    std::bernoulli_distribution randBool(0.5);
	
    //Generate position
	std::uniform_int_distribution<> randPosX(2, xMapSize-2);

    positionX = randPosX(gen);
    positionY = yMapSize/2;

    //Generate move
    std::uniform_int_distribution<> randMove(0, 1);

    movingY = Movment::top;

    if(randMove(gen)) {
        movingX = Movment::right;
    }
    else {
        movingX = Movment::left;
    }
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

bool Ball::isPointCollision(const std::vector<std::vector<std::string>>& mapFields) const {
    bool isCollision = false;
    auto symbol = Point::getSymbol();

    if(mapFields[positionY - 1][positionX] == symbol || //Top
       mapFields[positionY + 1][positionX] == symbol || //Bottom
       mapFields[positionY][positionX - 1] == symbol || //Left
       mapFields[positionY][positionX + 1] == symbol || //Right
       mapFields[positionY - 1][positionX - 1] == symbol || //Top-left
       mapFields[positionY - 1][positionX + 1] == symbol || //Top-right
       mapFields[positionY + 1][positionX - 1] == symbol || //Bottom-left
       mapFields[positionY + 1][positionX + 1] == symbol) { //Bottom-right
           isCollision = true;
    }
    return isCollision;
}

void Ball::moveIfPointCollision(const std::vector<std::vector<std::string>>& mapFields,
                        unsigned int& pointsCount) {
    auto symbol = Point::getSymbol();

    if(movingX == Movment::left && movingY == Movment::top) {
        //Point on the left-top
        if(mapFields[positionY - 1][positionX - 1] == symbol) {
            ++positionX;
            ++positionY;
            movingX = Movment::right;
            movingY = Movment::bottom;
            
            ++pointsCount;
        }
        //Point on the left
        else if(mapFields[positionY][positionX - 1] == symbol) {
            ++positionX;
            --positionY;
            movingX = Movment::right;

            ++pointsCount;
        }
        //Point on the top
        else if(mapFields[positionY - 1][positionX] == symbol) {
            --positionX;
            ++positionY;
            movingY = Movment::bottom;

            ++pointsCount;
        }
    }
    else if(movingX == Movment::right && movingY == Movment::top) {
        //Point on the right-top
        if(mapFields[positionY - 1][positionX + 1] == symbol) {
            --positionX;
            ++positionY;
            movingX = Movment::left;
            movingY = Movment::bottom;

            ++pointsCount;
        }
        //Point on the right
        else if(mapFields[positionY][positionX + 1] == symbol) {
            --positionX;
            --positionY;
            movingX = Movment::left;

            ++pointsCount;
        }
        //Point on the top
        else if(mapFields[positionY - 1][positionX] == symbol) {
            ++positionX;
            ++positionY;
            movingY = Movment::bottom;

            ++pointsCount;
        }
    }
    else if(movingX == Movment::left && movingY == Movment::bottom) {
        //Point on the left-bottom
        if(mapFields[positionY + 1][positionX - 1] == symbol) {
            ++positionX;
            --positionY;
            movingX = Movment::right;
            movingY = Movment::top;

            ++pointsCount;
        }
        //Point on the left
        else if(mapFields[positionY][positionX - 1] == symbol) {
            ++positionX;
            ++positionY;
            movingX = Movment::right;

            ++pointsCount;
        }
        //Point on the bottom
        else if(mapFields[positionY + 1][positionX] == symbol) {
            --positionX;
            --positionY;
            movingY = Movment::top;

            ++pointsCount;
        }
    }
    else if(movingX == Movment::right && movingY == Movment::bottom) {
        //Point on the right-bottom
        if(mapFields[positionY + 1][positionX + 1] == symbol) {
            --positionX;
            --positionY;
            movingX = Movment::left;
            movingY = Movment::top;

            ++pointsCount;
        }
        //Point on the right
        else if(mapFields[positionY][positionX + 1] == symbol) {
            ++positionX;
            ++positionY;
            movingX = Movment::right;

            ++pointsCount;
        }
        //Point on the bottom
        else if(mapFields[positionY + 1][positionX] == symbol) {
            ++positionX;
            --positionY;
            movingY = Movment::top;

            ++pointsCount;
        }
    }
}