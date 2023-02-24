#include "fig5.hpp"

Fig5::Fig5()
{
    length_ = FIG_5_SIZE;

    reserveTheLength(length_);

    bodyPivot.first = spawnX();
    bodyPivot.second = 1;

    setBody(0, bodyPivot.first - 1, bodyPivot.second);
    setBody(1, bodyPivot.first + 1, bodyPivot.second);
    setBody(2, bodyPivot.first, bodyPivot.second);
    setBody(3, bodyPivot.first, bodyPivot.second - 1);

    pivotPointNumb = 2;

    figureChar = FIG_5_CHAR;
}