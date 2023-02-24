#ifndef PLANE_HPP
#define PLANE_HPP

#include "macros.cpp"
#include "figure.hpp"
#include <vector>
#include <iostream>

using namespace std; 

class Plane
{
public:
    Plane();
    ~Plane();

    void clearMap();
    void drawMap();
    void updateMap(Figure &figure);
    bool bottomCheck(Figure &figure);
    void figArrayUpdate(Figure &figure);
    bool gameOver();
    bool fullLineChecker();
    int getPoints();
    char getMapChar(int x, int y);

    bool moveLeft(Figure &figure);
    bool moveRight(Figure &figure);

private:
    int points = 0;

    int width_ = PLANE_WIDTH;
    int heigh_ = PLANE_HEIGH;

    char mapArray_[PLANE_HEIGH][PLANE_WIDTH]; 
    char figureArray_[PLANE_HEIGH][PLANE_WIDTH];
    
};
#endif