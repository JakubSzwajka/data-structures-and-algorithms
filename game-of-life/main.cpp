#include "plane.hpp"
#include <unistd.h>


/*
Martwa komórka, która ma dokładnie 3 żywych sąsiadów, 
staje się żywa w następnej jednostce czasu (rodzi się)

Żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa;
przy innej liczbie sąsiadów umiera (z „samotności” albo „zatłoczenia”)

*/

int main()
{
    Plane plane;


    //plane.drawPlane();
    while(1)
    {
        usleep(500000);
        system("clear");
        plane.checkForNeighbours();
        plane.reloadCitizens();
        plane.drawPlane();
    }
        
    return 0;
}