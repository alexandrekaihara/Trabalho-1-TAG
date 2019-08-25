/** \file readfiles.h
 * \brief Arquivo com a biblioteca de funcoes de geracao dos vertices do grafo a partir do arquivo .mtx
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#ifndef READFILES_CPP_INCLUDED
#define READFILES_CPP_INCLUDED

#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


class Readfile
{
public:
    ifstream    inFile;

    vector<int> filecontent;


    bool openfile ();


    void readfile ();


    void closefile ();
};


#endif
