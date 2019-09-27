/** \file grafos.cpp
 * \brief Arquivo com a implementacao da manipulacao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */

#include <vector>
#include "grafos.h"

Materia::Materia (int codigo, vector<int> vizinhos)
{
    this->codigo = codigo;
    this->vizinhos.insert (vizinhos, 0, vizinhos.size ());
}

// Transfere os dados pegos do arquivo para um grafo (da classe Grafo) feito com a classe Vertice
void Grafo::criargrafo ()
{   
}

// Printa os vertices e vizinhos do grafo
void Grafo::printgrafo ()
{
}

// Projeta a intersecao de dois vetores em um terceiro vetor. Usado no algoritmo de Bron-Kerbosch
void Grafo::intersection ()
{
}

// Realiza uma busca em profundidade no grafo
void Grafo::DepthFirstSearch ()
{
}
