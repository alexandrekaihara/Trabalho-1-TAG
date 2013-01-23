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
    for (i = 0; i < 3; i++)
    {
        sizes.push_back (file->filecontent[i]);
    }
    // Alocacao dinamica dos vertices
    for(int j = 0; j < sizes[0]; j++)
    {
        grafo.push_back (new Vertice);
    }

    // Criacao das arestas
    for (; i < 2*sizes[2] + 2; i += 2)
    {
        // Subtrai-se - 1 pois os valores reais nao correspondem a posiçao no vetor
        grafo[file->filecontent[i] - 1]->vizinhos.push_back (file->filecontent[i + 1] - 1);
        //(*grafos[(*file).filecontent[i] - 1]).vizinhos.push_back((*file)filecontent[i+1] - 1);

        grafo[file->filecontent[i + 1] - 1]->vizinhos.push_back (file->filecontent[i] - 1);
    }
}


void Grafo::destruirgrafo ()
{
    for (int i = 0; i < this->sizes[0]; i++)
    {
        delete grafo[i];
    }
}


void Grafo::printgrafo ()
{
    for(int i = 0; i < sizes[0]; i++)
    {
        cout << "Vertice: " << (i+1) << " | Vizinhos: ";
        for (int j = 0; j < grafo[i]->vizinhos.size (); j++)
        {
            cout << " " << grafo[i]->vizinhos[j] + 1;
        }
        cout << "\n"; 
    }
}


void Grafo::printgrau ()
{
    cout << "GRAU DOS VERTICES:\n\n";
    for(int i = 0; i < sizes[0]; i++)
    {
        cout << "Vertice: " << (i+1) << "\tNum Vizinhos: " << grafo[i]->vizinhos.size () << endl;   
    }
}