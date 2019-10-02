    /** \file grafos.h
 * \brief Arquivo com a biblioteca de funcoes de manutencao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED

#include "readfiles.h"
#include <algorithm>

using namespace std;

// Cada objeto dessa classe representa um vertice no grafo
class Materia
{
public:
    int grauentrada;

    int grauida;

    int codigo;

    int creditos;

    vector<Materia*> arestachegada;

    vector<Materia*> arestaida;
};

// Classe utilizada para realizar operacoes com o grafo lido
class Grafo
{
public:
    vector<Materia*> grafo;
    
    void criargrafo (Readfile* a);  

    void grafoinverso ();

    void printgrafo ();

    void destruirgrafo ();

};

#endif
