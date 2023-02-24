#include "square.hpp"
#include "macros.cpp"


Square::Square()
{
    length_ = SQUARE_SIZE;

    reserveTheLength(length_);

    bodyPivot.first = spawnX();
    bodyPivot.second = 1;

    setBody(0,bodyPivot.first, bodyPivot.second);
    setBody(1, bodyPivot.first + 1, bodyPivot.second);
    setBody(2, bodyPivot.first , bodyPivot.second + 1);
    setBody(3, bodyPivot.first + 1, bodyPivot.second + 1 );

    pivotPointNumb = 0;

    figureChar = SQUARE_CHAR;
}

