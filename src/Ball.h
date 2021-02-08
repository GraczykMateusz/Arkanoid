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
    const std::string sBall = "O";
    int positionX, positionY;

    bool moveException = false;

    Movment movingX;
    Movment movingY;

    int hitPointPositionX = -1;
    int hitPointPositionY = -1;

    public:
        //Constructor and destuctor
        Ball(const unsigned int& xMapSize,
             const unsigned int& yMapSize);
        ~Ball() = default;

        //Methods
        void move(const std::vector<std::vector<std::string>>& mapFields,
                  const unsigned int& xMapSize,
                  const unsigned int& yMapSize,
                  bool& isGameOver);
        void moveIfPointCollision(const std::vector<std::vector<std::string>>& mapFields,
                                  std::vector<std::shared_ptr<Point>>& points,
                                  unsigned int& pointsCount);

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