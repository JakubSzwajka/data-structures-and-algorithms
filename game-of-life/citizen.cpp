#include "citizen.hpp"

Citizen::Citizen():
alive_(false)
{
    this->setMarker();
}
//==================================
Citizen::~Citizen()
{

}
//==================================
Citizen::Citizen(bool alive):
alive_(alive)
{
    this->setMarker();
}
//==================================
void Citizen::setMarker()
{
    if(this->alive_)
    {
        marker_ = ALIVE_CITIZEN_MARKER;
    }
    else if(!this->alive_)
    {
        marker_ = DEAD_CITIZEN_MARKER;
    }
}
//==================================
void Citizen::upDateMarker()
{
    alive_ = nextRoundStatus_;
    setMarker();
}
//==================================
void Citizen::setNeighbours(int neighbours)
{
    neighborus_ = neighbours; 
}
//==================================
bool Citizen::getStatus()
{
    return alive_;
}
//==================================
void Citizen::statusReload()
{
    alive_ = nextRoundStatus_;
    setMarker();
}
//==================================
void Citizen::setFutureStatus()
{
    if(neighborus_ <= 1)
    {
        nextRoundStatus_ = false;
    }
    if(neighborus_ >= 4)
    {
        nextRoundStatus_ = false;
    }
    if(neighborus_ == 3)
    {
        nextRoundStatus_ = true;
    }
    if(neighborus_ == 2)
    {
        nextRoundStatus_ = true;
    }
}
//==================================
std::ostream& operator << (std::ostream &out, const Citizen &cit)
{
    out << cit.marker_ ;
    //out << cit.neighborus_;
    //out << cit.alive_;
    //out << cit.nextRoundStatus_;
}
//==================================
