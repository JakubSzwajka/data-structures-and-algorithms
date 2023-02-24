#include "plane.hpp"
#include <iostream>


// init the plane 
Plane::Plane()
{
    for (int i = 0; i < heigh_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            mapArray_[i][j] = PLANE_CHAR;
            figureArray_[i][j] = PLANE_CHAR;
        }
    }
}

Plane::~Plane()
{

}
// draw the map to screen with it's content in specific moment
void Plane::drawMap()
{
    for(int i = 0; i < heigh_; i++)
    {
        for(int j = 0; j < width_; j++)
        {
            std::cout << mapArray_[i][j] << " "; 
        }
        std::cout << endl;
    }
}
// update content of the map with figure and it's body
void Plane::updateMap(Figure &figure)
{
    for(int i = 0 ; i < heigh_; i++)
    {
        for(int j = 0; j < width_; j++)
        {
            for(int x = 0 ; x < figure.length_ ; x++)
            {
                if(figure.getBody(x).first == j && figure.getBody(x).second == i)
                {
                    mapArray_[i][j] = figure.figureChar;
                }

                if(figureArray_[i][j] != PLANE_CHAR)
                {
                    mapArray_[i][j] = figureArray_[i][j];
                }
            }
        }
    }
}
// clear the map content to plane_char
void Plane::clearMap()
{
    for (int i = 0; i < heigh_; i++)
    {
        for (int j = 0; j < width_; j++)
        {
            mapArray_[i][j] = PLANE_CHAR;
        }
    }
}
// check if some figure is on the bottom of the map or on another figure
bool Plane::bottomCheck(Figure &figure)
{

    for(int i = 0; i < PLANE_HEIGH; i++)
    {
        for(int j = 0 ; j < PLANE_WIDTH; j++)
        {
            for(int x = 0; x < figure.length_ ; x++)
            {
                // znalazł się na samym dole albo na coś natrafił 
                if ((figure.getBody(x).second == PLANE_HEIGH - 1) || (figureArray_[figure.getBody(x).second + 1][figure.getBody(x).first] != PLANE_CHAR))
                {
                    figArrayUpdate(figure);
                    return true;
                }
            }
        }
    }
    return false;
}
// uppdate the figure element of the map
void Plane::figArrayUpdate(Figure &figure)
{
    for(int i = 0; i < figure.length_; i++)
    {
        figureArray_[figure.getBody(i).second][figure.getBody(i).first] = figure.figureChar;
    }
}
// check for full line
bool Plane::fullLineChecker()
{
    bool fullFlag = false;
    for(int i = PLANE_HEIGH-1; i >= 0; i--)
    {
        for(int j = 0; j < PLANE_WIDTH; j ++)
        {
            if(figureArray_[i][j] != PLANE_CHAR)
            {
                fullFlag = true;
            }
            else 
            {
                fullFlag = false;
                break;
            }
        }

        if(fullFlag)
        {
            for(int x = 0; x < PLANE_WIDTH; x++)
            {
                figureArray_[i][x] = PLANE_CHAR;
            }
            for(int y = i - 1; y >= 0; y-- )
            {
                for(int p = 0; p < PLANE_WIDTH; p++)
                {
                    if(figureArray_[y][p] != PLANE_CHAR)
                    {
                        char tempChar = figureArray_[y][p];
                        figureArray_[y][p] = PLANE_CHAR;
                        figureArray_[y + 1][p] = tempChar;
                    }
                }
            }
            fullFlag = false;
            this->points = this->points + PLANE_WIDTH;
        }
    }
    return fullFlag;
}
// return the points walue 
int Plane::getPoints()
{
    return points;
}
// get the map char
char Plane::getMapChar(int x, int y)
{
    return mapArray_[x][y];
}
// if the figure tower touch the top
bool Plane::gameOver()
{
    for(int i = 0 ; i < PLANE_WIDTH; i++)
    {
        if(figureArray_[1][i] != PLANE_CHAR)
            return true;
    }
    return false; 
}

bool Plane::moveLeft(Figure &figure)
{
    bool sideMaxFlag = false;
    for(int j = 0 ; j < figure.length_; j++)
    {
        if(figure.getBody(j).first == 0 || figureArray_[figure.getBody(j).second][figure.getBody(j).first -1] != PLANE_CHAR)
        {
            sideMaxFlag = true;
            break;
        }
    }
    if(!sideMaxFlag)
    {
        for (int i = 0; i < figure.length_; i++)
            {
                figure.setBody(i,figure.getBody(i).first -1 ,figure.getBody(i).second);
            }
    }

    return sideMaxFlag;
}

bool Plane::moveRight(Figure &figure)
{
    bool sideMaxFlag = false;
    for (int j = 0; j < figure.length_; j++)
    {
        if (figure.getBody(j).first == PLANE_WIDTH - 1 || figureArray_[figure.getBody(j).second][figure.getBody(j).first + 1] != PLANE_CHAR)
        {
            sideMaxFlag = true;
            break;
        }
        
    }
    if(!sideMaxFlag)
    {
        for (int i = 0; i < figure.length_; i++)
            {
                figure.setBody(i,figure.getBody(i).first +1 ,figure.getBody(i).second);
            }
    }

    return sideMaxFlag;
}