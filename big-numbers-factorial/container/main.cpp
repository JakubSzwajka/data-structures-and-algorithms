#include "kontener.hpp"
#include <iostream>

using namespace std;

int main()
{

    Kontener<string> test("test",10);
    
    cout << test << endl;

    return 0;
}