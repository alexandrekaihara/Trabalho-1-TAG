/** \file readfiles.h
 * \brief Arquivo com a implementa��o da gera��o dos v�rtices do grafo a partir do arquivo .mtx
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#ifndef READFILES_CPP_INCLUDED
#define READFILES_CPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class Readfile
{
public:
    ifstream    inFile;

    vector<int> filecontent;


    bool openfile ();


    void readfile ();


};


#endif
