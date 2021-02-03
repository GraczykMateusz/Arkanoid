#ifndef BALL_H
#define BALL_H

#include <string>

class Ball {
    const std::string sBall = "O";
    int positionX, positionY;

    public:
        //Constructor and destuctor
        Ball(const unsigned int xMapSize,
             const unsigned int yMapSize);
        ~Ball() = default;

        //Methods
        void move(const unsigned int xMapSize,
                  const unsigned int yMapSize);

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const std::string& getBallChar() const;
};
#endif /*BALL_H*/