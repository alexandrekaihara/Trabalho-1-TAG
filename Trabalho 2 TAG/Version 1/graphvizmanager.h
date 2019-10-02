    /** \file grafos.h
 * \brief Arquivo com a biblioteca de funcoes de manutencao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#ifndef GRAPHVIZMANAGER_H_INCLUDED
#define GRAPHVIZMANAGER_H_INCLUDED

#include "grafos.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Cada objeto dessa classe representa um vertice no grafo
class graphviz
{
public:
    void generategraph (Grafo* grafo);

    void generateordenation (vector<Materia*> ordenacao);
};


class string_cvt
{
public:
    std::string num_str (int num);

    int str_num (std::string str);
};


#endif
