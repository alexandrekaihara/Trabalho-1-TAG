/** \file ordenacaotopolagica.h
 * \brief Arquivo com a biblioteca de funcoes de manutencao do grafo
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


class ordenacaotopologica
{
public:
    void exec (Grafo* grafo);

    void intersection (vetor<Materia*> grafo);

    vector<Materia*> ordenacao;
};


#endif
