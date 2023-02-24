#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "macros.hpp"
#include "map.hpp"

#include <vector>
#include <string>

using namespace std; 

class Snake
{
public: 
    Snake();
    ~Snake();

    void updateMovement(string dir);
    string move();
    
    bool isDead_;
    int length_;
    string dir_;
    vector<pair<int,int>> snakeBody_;
    pair<int,int> startCoordinates_; 
};

#endif