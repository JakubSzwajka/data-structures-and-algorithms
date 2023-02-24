#ifndef FIGURE_HPP
#define FIGURE_HPP

#include "macros.cpp"

#include <vector>
#include <iostream>

using namespace std;

class Figure
{
public:
    Figure();
    ~Figure();

    int length_;
    pair<int,int> bodyPivot; 
    int pivotPointNumb;

    char figureChar; 

    virtual pair<int, int> getBody(int position);
    void setBody(int position, int x, int y);
    void reserveTheLength(int length);
    int spawnX();
    void moveDown();


    virtual void rotateR();

private:

    vector<pair<int,int>> figBody_;
    int spawnPoint_;
};
#endif