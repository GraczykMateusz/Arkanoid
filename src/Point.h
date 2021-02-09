#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
    /*Make a model of a point object*/
    private:
        //Point symbol
        const static std::string sPoint;

        //Index from 0, each point has a different
        int index;

        //Position
        int positionX, positionY;
        void setPositionXY();

    public:
        //Constructor and destuctor
        Point(const unsigned int index);
        ~Point() = default;

        //Getters
        const int& getPositionX() const;
        const int& getPositionY() const;

        const static std::string& getSymbol();
        const int getIndex() const;
};
#endif /*BALL_H*/