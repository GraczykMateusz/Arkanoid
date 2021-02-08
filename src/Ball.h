#ifndef BALL_H
#define BALL_H

#include <string>
#include <vector>
#include <random>

enum Movment {
    left, right, top, bottom
};

class Ball {
    const std::string sBall = "O";
    int positionX, positionY;

    Movment movingX;
    Movment movingY;

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

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const std::string& getBallChar() const;
};
#endif /*BALL_H*/