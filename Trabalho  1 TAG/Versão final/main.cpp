/** \file golfinho.cpp
 * \brief Arquivo Principal
 * \author Alexandre Mitsuru Kaihara e Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
// Diretiva de compilação: g++ -std=c++11 -o main main.cpp readfiles.cpp grafos.cpp
#include "grafos.h"
#include "readfiles.h"
#include <iostream>
#include <fstream>

int main ()
{
    Readfile a;
    Grafo golfinho;

    // Le as informacoes do arquivo e as transfere para um grafo da classe Grafo
    if(!a.openfile ())
        return 0;
    a.readfile ();
    a.closefile ();
    golfinho.criargrafo (&a);

    golfinho.printgrau (); // Imprime os graus de cada vertice
    golfinho.findmaximalclique (); // Imprime os cliques maximais
    golfinho.triosf (); // Calcula os indices de aglomeracao
    golfinho.aglom (); // Imprime o sindices de aglomeracao

    return 0;
}

