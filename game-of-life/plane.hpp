#ifndef PLANE_HPP
#define PLANE_HPP 

#include "macros.hpp"
#include "citizen.hpp"


class Plane
{

public:
    Plane();
    ~Plane();

    void drawPlane();
    
    void checkForNeighbours();
    void reloadCitizens();

private:

    void emptyPlaneInit();
    void centerFigureInit();

    int centerX_ = BASIC_MAP_WIDTH / 2;
    int centerY_ = BASIC_MAP_HEIGHT / 2;
    
    Citizen* mapArray_[BASIC_MAP_HEIGHT][BASIC_MAP_WIDTH];
};

#endif