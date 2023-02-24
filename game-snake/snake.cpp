#include "snake.hpp"
#include "map.hpp"
#include "macros.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <unistd.h>   //_getcher
#include <termios.h>  //_getcher

using namespace std;
//////////// this part of a code comes from:
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux/7469410#7469410
char getcher()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 0;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
    return buf;
}
///////////////////////////////////////////////
Snake::Snake()
{
    length_ = START_SNAKE_LENGTH; 
    snakeBody_.reserve(1000);
    startCoordinates_.first = 7;
    startCoordinates_.second = 7;
    isDead_ = false; 
    dir_ = "Right";

    for(int i = 0 ; i < length_; i++)
    {
       snakeBody_[i].first = startCoordinates_.first;
       snakeBody_[i].second = startCoordinates_.second - i;
    }
}
//////////////////////////////////////////////
Snake::~Snake()
{

}
//////////////////////////////////////////////
void Snake::updateMovement(string  dirToMove)
{
    dir_ = move();

    for(int i = length_ - 1 ; i > 0 ; i--)
    {
        snakeBody_[i].first = snakeBody_[i-1].first;
        snakeBody_[i].second = snakeBody_[i-1].second;
    }


     if(dirToMove == "Right")
     {
            snakeBody_[0].second ++ ; 
            if(snakeBody_[0].second >= MAP_WIDTH)
                snakeBody_[0].second = 0 ;
     }
     else if (dirToMove == "Left")
     {
         snakeBody_[0].second--;
         if (snakeBody_[0].second < 0)
             snakeBody_[0].second = MAP_WIDTH - 1;
     }
     else if (dirToMove == "Up")
     {
         snakeBody_[0].first--;
         if (snakeBody_[0].first < 0)
             snakeBody_[0].first = MAP_HEIGHT - 1;
     }
     else if(dirToMove == "Down")
     {
         snakeBody_[0].first++;
         if (snakeBody_[0].first >= MAP_HEIGHT)
             snakeBody_[0].first = 0;
     } 
}
/////////////////////////////////////////////////////
string Snake::move()
{
    string result = dir_;

    switch (getcher())
    {
        case 'd':
            if(dir_ != "Left")
                result = "Right";
            break;
        case 'a':
            if (dir_ != "Right")
                result = "Left";
            break;
        case 'w':
            if (dir_ != "Down")
                result = "Up";
            break;
        case 's':
            if (dir_ != "Up")
                result = "Down";
            break;
        default:
            result;
    }
    return result;
}