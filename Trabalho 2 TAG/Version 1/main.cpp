/** \file main.cpp
 * \brief Arquivo Principal
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
// Diretiva de compilação: g++ -std=c++11 -o main main.cpp readfiles.cpp grafos.cpp ordenacaotopologica.cpp
#include "grafos.h"
#include "readfiles.h"
#include "ordenacaotopologica.h"

int main ()
{
    Readfile a;
    Grafo fluxo;
    ordenacaotopologica ord;

    // Le as informacoes do arquivo e as transfere para um grafo da classe Grafo
    if(!a.openfile ("grafo-CIC.mtx")) return 0;
    a.readfile  ();
    a.closefile ();

    fluxo.criargrafo (&a);
    ord.exec (&fluxo);
    ord.printordenacao ();
    fluxo.destruirgrafo ();

    fluxo.criargrafo (&a);
    fluxo.destruirgrafo ();

    return 0;
}

