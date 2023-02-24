#include "figure.hpp"

Figure::Figure()
{
    spawnPoint_ = PLANE_WIDTH / 2;
}

Figure::~Figure()
{

}

pair<int, int> Figure::getBody(int position)
{
    return figBody_[position];
}

void Figure::setBody(int position, int x, int y)
{
    figBody_[position].first = x ; 
    figBody_[position].second = y ; 
}

void Figure::reserveTheLength(int length)
{
    figBody_.reserve(length);
}

int Figure::spawnX()
{
    return spawnPoint_;
}

void Figure::moveDown()
{
    for(int i = 0; i < length_ ; i++)
    {
        figBody_[i].second ++ ;
    }
}





void Figure::rotateR()
{
    vector<pair<int,int>> tempBody;
    tempBody.reserve(length_);

    this->bodyPivot = getBody(this->pivotPointNumb);

    for(int i = 0 ; i < length_; ++i)
    {
        tempBody[i].first = this->bodyPivot.first + (this->getBody(i).second - this->bodyPivot.second) * (-1);
        tempBody[i].second = this->bodyPivot.second + (this->getBody(i).first - this->bodyPivot.first) ; 

        this->setBody(i , tempBody[i].first,tempBody[i].second);
    }
}