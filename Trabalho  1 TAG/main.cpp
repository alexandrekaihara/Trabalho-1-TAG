/** \file golfinho.cpp
 * \brief Arquivo Principal
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
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
    Clique b;

    a.openfile ();
    a.readfile ();
    a.closefile ();
    golfinho.criargrafo (&a);
    golfinho.printgrafo ();
    //golfinho.destruirgrafo ();
    golfinho.findmaximalclique ();

    std::vector<int> v{2,5,8,11,14};
    b.adicionarclique (v);

    v = {1,2,3};
    b.adicionarclique (v);

    b.printcliques ();

    return 0;
}

