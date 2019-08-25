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
    vector<int> vizinhos;
};


class Grafo
{
public:
    vector<int> sizes;
    vector<int> trios;

    vector<Vertice*> grafo;

    
    void criargrafo (Readfile *file);   

    
    void destruirgrafo ();  


    void printgrafo ();


    void printgrau ();


    void findmaximalclique ();


    void bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x);


    int getindex (Vertice* vert);


    void intersection (vector<int> &vet, vector<int> &vizinhos, vector<int> &ans);


    void triosf ();


    void aglom ();
};

#endif
