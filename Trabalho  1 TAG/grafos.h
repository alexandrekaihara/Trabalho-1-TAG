/** \file grafos.h
 * \brief Arquivo com a implementa��o da gera��o dos v�rtices do grafo a partir do arquivo .mtx
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED

#include "readfiles.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


class Vertice
{
public:
    double aglom;

    vector<int> vizinhos;
};


class Grafo
{
public:
    vector<int> sizes;

    vector<Vertice*> grafo;

    
    void criargrafo (Readfile *file);

    
    void destruirgrafo ();


    void BronKerbosh ();


    void printgrafo ();
};


#endif
