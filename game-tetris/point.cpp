#include "point.hpp"

Point::Point()
{
    length_ = POINT_SIZE;

    reserveTheLength(length_);

    bodyPivot.first = spawnX();
    bodyPivot.second = 1;

    setBody(0, bodyPivot.first, bodyPivot.second);


    pivotPointNumb = 0;

    figureChar = POINT_CHAR;
}