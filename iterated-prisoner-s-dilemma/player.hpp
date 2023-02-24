#include <string>

class Player
{
public:

    Player();
    ~Player();

    std::string playerName;    
    static int number;
    void showDecisionTable();
    void showDecision(int dec);
    int showJudgmentSum();
    int giveReaction();
    void givePunishment(int pun);
    void setRoundEffect(int effect);

private:

    int judgmentSum;
    int oneRoundBack = 4;
    int twoRoundBack = 4;

    int reactions[10][3];
};


/*
          B milczy     |  B zeznaje
A milczy | obaj 6 mies | A-10 lat B-wolny
A zeznaje| A-wolny B-10| obaj na 5 lat

W - wolny
 2    1      now 
 W    W      wygwyg
 S1   W      polwyg
 W    S1     wygpol
 S1   S1     polpol
 S10  W      piewyg
 W    S10    wygpie
 S10  S10    piepie
 S20  W      dziwyg
 W    S20    wygdzi
 S20  S20    dzidzi


0 - wolny 
1 - S1
2 - S10
3 - S20

4 - nie było jeszcze ruchu
========================

ruch = 1 jeżeli zeznaje
       0 jeżeli milczy


ruch 0 - wyszedłem na wolnosc bo milczał ja wsypałem
     1 - milczeliśmy oboje 
     10- zeznawaliśmy oboje
     20 - milczałem on mnie wsypał
*/