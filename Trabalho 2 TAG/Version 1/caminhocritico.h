/** \file caminhocritico.h
 * \brief Arquivo que implementa o caminho critico de um grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#ifndef ORDENACAOTOPOLOGICA_H_INCLUDED
#define ORDENACAOTOPOLOGICA_H_INCLUDED


using namespace std;


#include <algorithm>
#include "grafos.h"
#include "readfiles.h"


class caminhocritico
{
public:
    void exec (Grafo* grafo);

    void intersection (vector<Materia*> grafo);

    void breadthfirstsearch ();

    void printcaminho ();

private:
    vector<Materia*> caminho;
};


#endif
