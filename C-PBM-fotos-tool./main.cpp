#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/////////////////////////////////////// METHODES ///////////////////////////

// load file 
bool load(string fileToLoad);
// save file
bool save(string fileToSave);
// make nagative
void negative();
// thresholding
void threshold(int thr);
// menuinit
void menuInit();
////////////////////////////////////// GLOBAL VARIABLES ///////////////////

fstream file;
string magicNumber;
string fileName;
int height = 0;
int width = 0;
int greyRange = 1;

int **pixelsTable;

////////////////////////////////////// MAIN ///////////////////////////////
int main()
{
    system("clear");
    string fileTitle;
    cout << "Welcom in the .pgm pictures formating program." << endl;
    cout << "enter the name of fileto work on: ";
    cin >> fileTitle;
    cout << endl << "---------------------------------------------------------" << endl;
    if(!load(fileTitle));
    else
    {
        char program;
        int thr;
        string saveName;
        bool exit=false;
        ///////////// MENU INIT /////////////////////////////////////////
        while(!exit)
        {
            menuInit();
            cin >> program;

            if(program =='1')
            {
                negative();
                system("clear");
                cout << "Enter name for save the file" << endl;
                cin >> saveName;
                save(saveName);
            }
            else if(program == '2')
            {
                system("clear");
                cout << "Threshold lvl: " << endl;
                cin >> thr;
                threshold(thr);
                cout << "Enter name for save the file" << endl;
                cin >> saveName;
                save(saveName);
            }
            else if(program == 'q' || program == 'Q')
            {
                exit = true;
            }
        }
    }

    file.close();
    return 0;
}
//////////////////////////////////////////////////////////////////////////
bool load(string fileToLoad)
{
    bool succes = true;
    string singleLine;

    file.open(fileToLoad, ios::in | ios::out);
    if(!file.good())
    {
        cout << "Program coutn't open this file: " << fileToLoad << endl;
        succes = false;
    }
    else 
    {
        cout << "File loaded succesfull :) " << endl;
        succes = true;

        // get magic number , name and dimensions
        getline(file, magicNumber);
        getline(file, fileName);
        file >> width >> height >> greyRange;
        // generate table of pointers with pointers
        pixelsTable = new int * [height];
        for(int i = 0; i < height; i++)
        {
            pixelsTable[i] = new int [width];  
            for(int j = 0; j < width; j ++)
            {
                // and fill them with pixel color data
                file >> pixelsTable[i][j];
            }
        }
    }
    return succes;
}
//////////////////////////////////////////////////////////////////////////
bool save(string fileToSave)
{
    bool succes = true;

    ofstream newFile(fileToSave);
    newFile << magicNumber << endl;
    newFile << fileName << endl;
    newFile << width << " "<< height << endl;
    newFile << greyRange << endl;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++)
        {
                newFile << pixelsTable[i][j] << " ";
        }
    }

    return succes;
}
///////////////////////////////////////////////////////////////////////////
void negative()
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j ++)
        {
            pixelsTable[i][j] = greyRange - pixelsTable[i][j];
        }
    }
}
///////////////////////////////////////////////////////////////////////////
void threshold(int thr)
{
    greyRange = 1;
    if(thr < 0 && thr > greyRange)
        cout << endl << "---!Wrong lvl!---" << endl;
    else
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j ++)
            {
                if(pixelsTable[i][j] >= thr)
                    pixelsTable[i][j] = 1;
                else pixelsTable[i][j] = 0;
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////
void menuInit()
{
    cout << endl << "---------------------------------------------------------" << endl;
    system("clear");
    cout << "1. Make Negative" << endl;
    cout << "2. Threshold" << endl;
    cout << endl << "---------------------------------------------------------" << endl;
    cout << "Q for quit" << endl;
}