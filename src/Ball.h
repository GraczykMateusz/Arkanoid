#ifndef BALL_H
#define BALL_H

#include <string>
#include <vector>
#include <random>
#include <memory>

#include "Point.h"

enum Movment {
    left, right, top, bottom
};

class Ball {
    /*The class makes a ball object*/
    private:
        const std::string sBall = "O";
        int positionX, positionY;

        //                                                  ###### 
        //That exception is needed when the ball is moving  #\ $ #
        //for example left-top and the the point is on his  # O  #
        //right-top corner (the slash is a ball move track) #  \ #
        //                                                  ######
        bool moveException = false;

        //Current ball movment
        Movment movingX;
        Movment movingY;

        //The point position to remove
        int hitPointPositionX = -1;
        int hitPointPositionY = -1;

    public:
        //Constructor and destuctor
        Ball(const unsigned int& xMapSize,
             const unsigned int& yMapSize);
        ~Ball() = default;

        //Movement
        void move(const std::vector<std::vector<std::string>>& mapFields,
                  const unsigned int& xMapSize,
                  const unsigned int& yMapSize,
                  bool& isGameOver);
        void moveIfPointCollision(const std::vector<std::vector<std::string>>& mapFields,
                                  std::vector<std::shared_ptr<Point>>& points,
                                  unsigned int& pointsCount);

        //Check collision
        bool isPointCollision(const std::vector<std::vector<std::string>>& mapFields) const;

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const int& getHitPointPositionX() const;
        const int& getHitPointPositionY() const;

        const bool& getMoveException() const;

        const std::string& getBallChar() const;
};
#endif /*BALL_H*/