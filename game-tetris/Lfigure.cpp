#include "Lfigure.hpp"

Lfigure::Lfigure()
{
    length_ = L_FIGURE_SIZE;

    reserveTheLength(length_);

    bodyPivot.first = spawnX();
    bodyPivot.second = 1;

    setBody(0,bodyPivot.first - 1 , bodyPivot.second - 1);
    setBody(1,bodyPivot.first - 1 , bodyPivot.second);
    setBody(2,bodyPivot.first , bodyPivot.second);
    setBody(3,bodyPivot.first + 1, bodyPivot.second);
    setBody(4,bodyPivot.first + 2 , bodyPivot.second);

    pivotPointNumb = 2;

    figureChar = L_FIGURE_CHAR;
}
