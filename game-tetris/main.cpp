#include <iostream>
#include <stdlib.h>

#include "plane.hpp"
#include "figure.hpp"

#include "square.hpp"
#include "Lfigure.hpp"
#include "LfigureInvert.hpp"
#include "line.hpp"
#include "point.hpp"
#include "fig5.hpp"
#include "fig6.hpp"

#include "unistd.h"
#include <unistd.h>  //_getcher
#include <termios.h> //_getcher


using namespace std; 

bool gameOver = false; 

int score = 0 ;

void turn(Plane &plane, Figure &figure, char dir);
char getcher();
void randFigure();

Plane *plansza;
Figure *figPointer;
char dir = 'n';

int main()
{
    plansza = new Plane;

    int pointsAdd = PLANE_WIDTH;

    figPointer = new Lfigure; 

    while (!plansza->gameOver())
    {

        dir = getcher(); // get control char

        turn(*plansza, *figPointer, dir);

        plansza->updateMap(*figPointer);

        figPointer->moveDown();

        plansza->fullLineChecker();

        if (plansza->bottomCheck(*figPointer))
        {
            delete figPointer;
            randFigure();
            cout << " BOTTOM ! " << endl;
        }

        system("clear");

        plansza->drawMap();
        plansza->clearMap();
        //cout << "(" << figPointer->getBody(figPointer->pivotPointNumb).first << "," << figPointer->getBody(figPointer->pivotPointNumb).second << ")" << endl;
        cout << "SCORE: " << plansza->getPoints() << endl;

        usleep(PAUSE_LENGTH );
    }
    cout << "Your total score: " << plansza->getPoints() << endl;

    delete plansza;

    return 0;
}

void randFigure()
{
    int random = rand() % 7;

    switch (random)
    {
    case 0:
        figPointer = new Square;
        break;
    case 1:
        figPointer = new Lfigure;
        break;
    case 2:
        figPointer = new LfigureInvert;
        break;
    case 3:
        figPointer = new Line;
        break;
    case 4:
        figPointer = new Point;
        break;
    case 5:
        figPointer = new Fig5;
        break;
    case 6:
        figPointer = new Fig6;
        break;
    }
}



void turn(Plane &plane,Figure &figPointer, char dir)
{
    switch (dir)
    {
    case 'a':
    case 'A':

    plane.moveLeft(figPointer);
        break;

    case 'd':
    case 'D':
        
    plane.moveRight(figPointer);
        break;
    
    case 'r':
    case 'R':
    figPointer.rotateR();
        break;
    }

    dir = 'n';
}



//////////// this part of a code comes from:
// https://stackoverflow.com/questions/7469139/what-is-the-equivalent-to-getch-getche-in-linux/7469410#7469410
char getcher()
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 0;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
 

    return buf;
} 
