/** \file ordenacaotopolagica.h
 * \brief Arquivo com a biblioteca de funcoes de manutencao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#include "ordenacaotopologica.h"


bool compare (Materia* a, Materia* b)
{
    if(a->grauentrada != b->grauentrada)
    {
        return a->grauentrada < b->grauentrada;
    }
    else
    {
        // Se a quantidade de pre-requisitos de outras materias for maior, deve vir depois
        if (a->grauida != b->grauida) 
             return a->grauida > b->grauida;
        // Se a quantidade de creditos for maior, deve vir depois 
        else
            return a->creditos > b->creditos;
    }
}

// Gera a ordenacao topologica
void ordenacaotopologica::exec (Grafo* grafo)
{
    vector<Materia*> fila (grafo->grafo);

    // Ordenacao inicial
    sort (fila.begin (), fila.end (), compare);

    while(!fila.empty ())
    {
        // Diminui o grau de chegada 
        for (int i = 0; i < fila[0]->grauida; i++)
            fila[0]->arestaida[i]->grauentrada--;

        // Adiciona a materia na ordenacao topologica e retira da fila
        ordenacao.push_back (fila[0]);
        fila.erase(fila.begin ());

        // Ordena a fila de acordo com a funcao compare
        sort (fila.begin (), fila.end (), compare);
    }
}