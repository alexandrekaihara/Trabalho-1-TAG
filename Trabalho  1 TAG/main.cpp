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

    a.openfile ();
    a.readfile ();
    a.closefile ();

    golfinho.criargrafo (&a);
    golfinho.printgrau ();
    golfinho.destruirgrafo ();
    golfinho.findmaximalclique ();
    return 0;
}

