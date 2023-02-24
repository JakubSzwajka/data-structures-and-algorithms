#include "plane.hpp"
#include "macros.hpp"

#include <iostream>

Plane::Plane()
{
    emptyPlaneInit();
    centerFigureInit();
}
Plane::~Plane()
{

}
//==================================
void Plane::drawPlane()
{
    for(int i = 0; i < BASIC_MAP_HEIGHT; i++)
    {
        for(int j = 0; j < BASIC_MAP_WIDTH; j++ )
        {
            std::cout << *mapArray_[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}
//==================================
void Plane::emptyPlaneInit()
{
    for(int i = 0; i < BASIC_MAP_HEIGHT; i++)
    {
        for(int j = 0; j < BASIC_MAP_WIDTH; j++ )
        {
            mapArray_[i][j] = new Citizen(false);
        }
    }
}
//==================================
void Plane::centerFigureInit()
{
    mapArray_[centerY_][centerX_] = new Citizen(true);
    mapArray_[centerY_][centerX_+1] = new Citizen(true);
    mapArray_[centerY_+1][centerX_+1] = new Citizen(true);
    mapArray_[centerY_+1][centerX_] = new Citizen(true);
}
//=====================================
void Plane::reloadCitizens()
{
    for(int i = 0; i < BASIC_MAP_HEIGHT; i++)
    {
        for(int j = 0; j < BASIC_MAP_WIDTH; j++ )
        {
            mapArray_[i][j]->statusReload();
        }
    }
}
//==================================
void Plane::checkForNeighbours()
{
    for(int i = 0; i < BASIC_MAP_HEIGHT; i++)
    {
        for(int j = 0; j < BASIC_MAP_WIDTH; j++ )
        {
            int tempNeighbours = 0 ;
            if(i == 0)
            {
                if(j == 0)
                {
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                }
                else if(j == (BASIC_MAP_WIDTH - 1))
                {
                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                }
                else
                {
                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                }
            }
            else if(i == (BASIC_MAP_HEIGHT - 1))
            {
                if(j == 0)
                {
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++;

                }
                else if(j == (BASIC_MAP_WIDTH - 1))
                {
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;
                }
                else
                {
                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                }
            }
            else
            {
                if( j == 0)
                {
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j+1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++; 
                    if(mapArray_[i-1][j+1]->getStatus()) tempNeighbours++;
                }
                else if( j ==( BASIC_MAP_WIDTH - 1))
                {
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;

                }
                else 
                {
                    if(mapArray_[i-1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i-1][j+1]->getStatus()) tempNeighbours++;
 
                    if(mapArray_[i+1][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j]->getStatus()) tempNeighbours++;
                    if(mapArray_[i+1][j+1]->getStatus()) tempNeighbours++;

                    if(mapArray_[i][j-1]->getStatus()) tempNeighbours++;
                    if(mapArray_[i][j+1]->getStatus()) tempNeighbours++; 
                } 
            }
            //std::cout << tempNeighbours << " , ";
            mapArray_[i][j]->setNeighbours(tempNeighbours);
            mapArray_[i][j]->setFutureStatus();
        }
    }
}