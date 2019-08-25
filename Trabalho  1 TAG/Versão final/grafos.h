/** \file grafos.h
 * \brief Arquivo com a biblioteca de funcoes de manutencao do grafo
 * \author Alexandre Mitsuru Kaihara e Felipe Xavier Barbosa da Silva
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

// Cada objeto dessa classe representa um vertice no grafo
class Vertice
{
public:
    vector<int> vizinhos;
};

// Classe utilizada para realizar operacoes com o grafo lido
class Grafo
{
public:
    // O tamanho do grafo e a quantidade de conexoes nele sao armazenadas em sizes
    // trios armazena a quantidade de triangulos fechados que cada vertice tem
    vector<int> sizes;
    vector<int> trios;

    vector<Vertice*> grafo;

    
    void criargrafo (Readfile *file);  
    

    void printgrau ();


    void findmaximalclique ();


    void bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x);


    void intersection (vector<int> &vet, vector<int> &vizinhos, vector<int> &ans);


    void triosf ();


    void aglom ();
};

#endif
