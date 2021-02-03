#ifndef BALL_H
#define BALL_H

#include <string>
#include <vector>

enum Movment {
    left, right, top, bottom
};

class Ball {
    const std::string sBall = "O";
    int positionX, positionY;

    Movment movingX = Movment::left;
    Movment movingY = Movment::top;

    public:
        //Constructor and destuctor
        Ball(const unsigned int xMapSize,
             const unsigned int yMapSize);
        ~Ball() = default;

        //Methods
        void move(const std::vector<std::vector<std::string>> mapFields,
                  unsigned int xMapSize,
                  unsigned int yMapSize);

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const std::string& getBallChar() const;
};
#endif /*BALL_H*/