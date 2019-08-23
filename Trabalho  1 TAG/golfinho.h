/** \file golfinho.cpp
 * \brief Arquivo com a implementa��o da gera��o dos v�rtices do grafo a partir do arquivo .mtx
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#ifndef GOLFINHO_CPP_INCLUDED
#define GOLFINHO_CPP_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class golfinho
{
public:
    double aglom;

    vector<int> vizinhos;
};


class criargrafo
{
public:
    ifstream inFile;

    string content;


    void openfile ();


    void readfile();

    //bool learquivo (golfinho grafo);
};


#endif
