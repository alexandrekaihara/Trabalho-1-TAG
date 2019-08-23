#include "readfiles.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


bool Readfile::openfile ()
{
    this->inFile.open("soc-dolphins.mtx");

    if (this->inFile.fail ())
    {
        cout << "Failed opening file." << endl;
        return -1;
    }
}


void Readfile::readfile ()
{
    string temp;
    string::size_type sz;
    
    while(!inFile.eof())
    {
        inFile >> temp;
        filecontent.push_back (stoi(temp, &sz, 10));
    }
}