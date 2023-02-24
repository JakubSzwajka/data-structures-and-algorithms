#include "fig6.hpp"

Fig6::Fig6()
{
    length_ = FIG_6_SIZE;

    reserveTheLength(length_);

    bodyPivot.first = spawnX();
    bodyPivot.second = 1;

    setBody(0, bodyPivot.first - 1, bodyPivot.second - 1);
    setBody(1, bodyPivot.first, bodyPivot.second - 1);
    setBody(2, bodyPivot.first, bodyPivot.second);
    setBody(3, bodyPivot.first + 1, bodyPivot.second);

    pivotPointNumb = 2;

    figureChar = FIG_6_CHAR;
}