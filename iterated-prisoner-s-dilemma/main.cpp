#include <iostream>
#include <vector>
#include <algorithm>

#include "player.hpp"

#define players 500

int fight(Player &a, Player &b);
void printPlayers(std::vector <Player*> wek);
bool sortFunction (Player *a ,Player *b);

std::vector <Player*> playerTab;

int main()
{
    srand(time(NULL));
    // inicjalizuje graczy 
    for(int i = 0; i < players; i++)
    {
        playerTab.push_back(new Player);
    }
    // wpuszczam graczy do gry 
    int iloscGier = 0 ;

    do
    {
        for(int i = players - 1; i >= 0; i--)
        {
            for(int j = i - 1 ; j >= 0; j--)
            {
               fight(*playerTab[i], *playerTab[j]);
                iloscGier ++ ;
            }
        }
        // znajdz dwoch najwiekszych i ich usun
        std::sort(playerTab.begin(),playerTab.end(),sortFunction);
        playerTab.erase(playerTab.begin(),playerTab.begin()+1);
    }while(playerTab.size() > 3);
    

    std::cout << "ilosc gier: " << iloscGier << std::endl;
    printPlayers( playerTab );

    return 0;
}

int fight(Player &a, Player &b)
{
    bool aDecision = a.giveReaction();
    bool bDecision = b.giveReaction();

    if( aDecision == 0 && bDecision == 0)
    {
        //std::cout<< "obaj 6 miesiecy" << std::endl;
        a.givePunishment(1);
        b.givePunishment(1);
        a.setRoundEffect(1);
        b.setRoundEffect(1);
    }
    else if( aDecision == 0 && bDecision == 1)
    {
        //std::cout << "a 10 lat b wolny" << std::endl;
        a.givePunishment(20);
        b.givePunishment(0);
        a.setRoundEffect(3);
        b.setRoundEffect(0);
    }
    else if( aDecision == 1 && bDecision == 0)
    {
        //std::cout << "a wolny b 10 lat" << std::endl;
        a.givePunishment(0);
        b.givePunishment(20);
        a.setRoundEffect(0);
        b.setRoundEffect(3);
    }
    else if( aDecision == 1 && bDecision == 1)
    {
        //std::cout << "oboje 5 lat" << std::endl;
        a.givePunishment(10);
        b.givePunishment(10);
        a.setRoundEffect(2);
        b.setRoundEffect(2);
    }
    else std::cout <<"logic error" << std::endl;
}
bool sortFunction(Player *a ,Player *b)
{
    return(a->showJudgmentSum() > b->showJudgmentSum());
}

void printPlayers(std::vector <Player*> wek)
{
    for(int i = 0; i < wek.size(); i++)
    {
        std::cout << wek[i]->playerName << " points: " << wek[i]->showJudgmentSum() << std::endl;
        wek[i]->showDecisionTable();
    }
}