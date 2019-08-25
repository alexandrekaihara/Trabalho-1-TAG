/** \file golfinho.cpp
 * \brief Arquivo Principal
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 25/08/19
 */
// Diretiva de compilação: g++ -std=c++11 -o main main.cpp readfiles.cpp grafos.cpp
#include "grafos.h"
#include "readfiles.h"

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

