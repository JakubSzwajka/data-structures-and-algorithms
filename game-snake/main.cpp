#include <iostream>
#include <unistd.h> // for usleep
#include <cstdlib> // for rand
////////////////////////////////////////////////////////
#include "macros.hpp"
#include "snake.hpp"
#include "map.hpp"
/////////////// NAMESPACES /////////////////////////////
using namespace std;
////// DECLARATIONS ////////////////////////////////////
void mapContentUpdate(Snake *snake, Map *map);
void fruitSpawn(Map *map);
void tacticTerminalSpace(int heigth);
void ifEat(Map *map, Snake *snake);
void ifDead(Map *map, Snake *snake);
////////////// VARIABLES ///////////////////////////////
Map *snakeMap; 
Snake *snake;
bool fruitToEat = false;
///////////////////////// MAIN /////////////////////////
int main()
{

    snakeMap = new Map;
    snake = new Snake;

    while(!snake->isDead_)
    {
        mapContentUpdate(snake, snakeMap);
        if (!fruitToEat)
            fruitSpawn(snakeMap);

        cout << "Points: " << snake->length_ - START_SNAKE_LENGTH << endl;
        snakeMap->drawMap();
        snake->updateMovement(snake->dir_);
        ifDead(snakeMap, snake);
        ifEat(snakeMap, snake);

        usleep(PAUSE_LENGTH);
    }
    cout << "Game Over! Points: " << snake->length_ - START_SNAKE_LENGTH << endl;

    return 0; 
}
///////////////////////////////////////////////////////
// check if snake eats some fruit 
void ifEat(Map *snakemap, Snake *snake)
{
    if (snakemap->mapArray_[snake->snakeBody_[0].first][snake->snakeBody_[0].second] == FRUIT_CHAR)
    {
        snake->length_++;
        fruitToEat = false;
    }
}
///////////////////////////////////////////////////////
// fill the map for display
void mapContentUpdate(Snake *snake, Map *map)
{
    map->cleanMap();

    for(int i = 0 ; i < MAP_HEIGHT; i++)
    {
        for(int j = 0 ; j < MAP_WIDTH; j++)
        {
            for(int x = 0 ; x < snake->length_; x++)
            {
                if(i == snake->snakeBody_[x].first && j == snake->snakeBody_[x].second)
                {
                    if(x == 0)
                    {
                        if(snake->dir_ == "Up")
                        {
                            map->mapArray_[i][j] = SNAKE_HEAD_UP;
                        }
                        else if(snake->dir_ == "Down")
                        {
                            map->mapArray_[i][j] = SNAKE_HEAD_DOWN;
                        }
                        else if(snake->dir_ == "Right")
                        {
                            map->mapArray_[i][j] = SNAKE_HEAD_RIGHT;
                        }
                        else
                        {
                            map->mapArray_[i][j] = SNAKE_HEAD_LEFT;
                        }
                        
                        
                    }
                    else
                    {
                        map->mapArray_[i][j] = SNAKE_CHAR;
                    }
                }
            }
        }
    }
}
///////////////////////////////////////////////////////
// spawning some fruit 
void fruitSpawn(Map *map)
{
    bool spawnedRight = false;
    while(!spawnedRight)
    {
    int fruitX = rand() % MAP_WIDTH;
    int fruitY = rand() % MAP_HEIGHT;

        if(map->mapArray_[fruitX][fruitY] == MAP_CHAR)
        {
            map->mapArray_[fruitX][fruitY] = FRUIT_CHAR;
            spawnedRight = true;
        }
    }
    fruitToEat = true;
}
///////////////////////////////////////////////////////
// checking if he eats himself
void ifDead(Map *snakeMap,Snake  *snake)
{
    if (snakeMap->mapArray_[snake->snakeBody_[0].first][snake->snakeBody_[0].second] == SNAKE_CHAR)
        snake->isDead_ = true;
}