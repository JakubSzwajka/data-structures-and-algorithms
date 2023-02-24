#include "player.hpp"

#include <cstdlib>
#include <iostream>
#include <ctime>

int Player::number = 0 ;

Player::Player()
{
    judgmentSum = 0;
    number ++;
    playerName = "Player" + std::to_string(number);

    reactions[0][0] = 0;
    reactions[0][1] = 0;
    reactions[1][0] = 1;
    reactions[1][1] = 0;
    reactions[2][0] = 0;
    reactions[2][1] = 1;
    reactions[3][0] = 1;
    reactions[3][1] = 1;
    reactions[4][0] = 2;
    reactions[4][1] = 0;
    reactions[5][0] = 0;
    reactions[5][1] = 2;
    reactions[6][0] = 2;
    reactions[6][1] = 2;
    reactions[7][0] = 3;
    reactions[7][1] = 0;
    reactions[8][0] = 0;
    reactions[8][1] = 3;
    reactions[9][0] = 3;
    reactions[9][1] = 3;

    for(int i = 0; i < 10; i ++)
    {
        int react = std::rand();
        if(react % 2 == 0) react = 0;
        else react = 1 ;
        reactions[i][2] = react;
    }
}

Player::~Player()
{

}

void Player::showDecisionTable()
{
   for(int i = 0 ; i < 10; i++)
   {

        std::cout<< "["<< reactions[i][0] << "] " << " ["
        << reactions[i][1] << "] - [" << reactions[i][2] << "]" << std::endl; 
   }
}

int Player::giveReaction()
{
    bool reactionFlag;
    if(oneRoundBack == 4 || twoRoundBack == 4) 
    {
        int random = rand();
        reactionFlag = random % 2;
    }
    else 
    {
        for(int i = 0; i < 10; i ++)
        {
            if(oneRoundBack == reactions[i][1] && twoRoundBack == reactions[i][0])
            {
                reactionFlag = reactions[i][2];
                break;
            }
        }
    }
    return reactionFlag;
}

void Player::setRoundEffect(int effect)
{
    twoRoundBack = oneRoundBack;
    oneRoundBack = effect;
}

void Player::showDecision(int dec)
{
    if(dec == 1) std::cout << " zeznaje " << std::endl;
    else if(dec == 0) std::cout << " milcze " << std::endl;
    else std::cout << "logic error" << std::endl;
}

void Player::givePunishment(int pun)
{
    judgmentSum += pun;
}

int Player::showJudgmentSum()
{
    return judgmentSum;
}