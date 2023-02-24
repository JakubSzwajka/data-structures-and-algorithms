#ifndef MAP_HPP
#define MAP_HPP

#include "macros.hpp"
#include "snake.hpp"

class Map
{
public: 
    Map();
    ~Map();

    void drawMap();
    void cleanMap();

    char mapArray_[MAP_HEIGHT][MAP_WIDTH];
};



#endif