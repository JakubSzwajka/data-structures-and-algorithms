#ifndef CITIZEN_HPP
#define CITIZEN_HPP

#include <iostream>

#include "macros.hpp"

class Citizen
{
public: 
    Citizen();
    Citizen(bool alive);
    ~Citizen();

    void setMarker();
    void upDateMarker();
    void setNeighbours(int neighbours);
    void setFutureStatus();
    void statusReload();
    bool getStatus();

private:
    bool alive_;
    bool nextRoundStatus_;
    char marker_;

    int neighborus_;


    friend std::ostream& operator << (std::ostream &out, const Citizen &cit);
};

#endif