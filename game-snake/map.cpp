#include "map.hpp"

#include <iostream>
//////////////////////////////////////////////////////
Map::Map()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            mapArray_[i][j] = MAP_CHAR;
        }
    }
}
//////////////////////////////////////////////////////
Map::~Map()
{

}
//////////////////////////////////////////////////////
void Map::drawMap()
{
    
    for(int i = 0; i < MAP_HEIGHT; i++)
    {
        for(int j = 0 ; j < MAP_WIDTH; j++)
        {
            cout << mapArray_[i][j] << " "; 
        }
        cout << endl;
    }
}
//////////////////////////////////////////////////////
void Map::cleanMap()
{
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            if (!(mapArray_[i][j] == FRUIT_CHAR))
                 mapArray_[i][j] = MAP_CHAR;
        }
        cout << endl;
    }
}