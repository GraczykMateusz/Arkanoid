#ifndef BALL_H
#define BALL_H

#include <string>

class Ball {
    std::string sBall = "O";
    int positionX, positionY;

    public:
        Ball(const int xMapSize, const int yMapSize);
        ~Ball() = default;

        void move();

        int getPositionX() { return positionX; }
        int getPositionY() { return positionY; }
};

#endif /*BALL_H*/