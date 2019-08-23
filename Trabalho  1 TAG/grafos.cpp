/** \file grafos.cpp
 * \brief Arquivo com a implementa��o da manipula��o do grafo
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#include "grafos.h"


void Grafo::criargrafo (Readfile *file)
{
    int i;
    // Leitura do tamanho do grafo
    for (i = 0; i < 2; i++)
    {
        sizes.push_back (file->filecontent[i]);
    }

    // Alocacao dinamica dos vertices
    for(int j = 0; j < sizes[0]; j++)
    {
       //grafo.push_back(new Vertice);
    }

    // Criacao das arestas
    for (; i < (sizes[2] + sizeof(sizes)); i++)
    {

    }

}


void Grafo::BronKerbosh ()
{

}


void Grafo::destruirgrafo ()
{

}
