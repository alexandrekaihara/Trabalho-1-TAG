/** \file grafos.cpp
 * \brief Arquivo com a implementacao da manipulacao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */


using namespace std;


#include <vector>
#include "grafos.h"
#include "readfiles.h"


// Transfere os dados pegos do arquivo para um grafo (da classe Grafo) feito com a classe Vertice
void Grafo::criargrafo (Readfile* a)
{   
    // Cria todos os vertices com
    int k = 0;
    for (int i = 0; i < (a->filecontent.size () - 1) ; i++)
    {
        this->grafo.push_back (new Materia ());
        this->grafo[k]->nome = a->nomes[k];
        this->grafo[k]->creditos    = a->filecontent[i];
        this->grafo[k]->codigo      = a->filecontent[i + 1];
        this->grafo[k]->grauentrada = a->filecontent[i + 2];

        i += 2;

        // Gera os vizinhos desse vertice
        int j;
        for (j = 0; j < this->grafo[k]->grauentrada; j++)
        {
            this->grafo[k]->arestachegada.push_back (this->grafo[a->filecontent[i + j + 1]]);
            this->grafo[a->filecontent[i + j + 1]]->arestaida.push_back (this->grafo[k]);
        }
        i += j;
        k++;
    }
    for(int i = 0; i < this->grafo.size (); i++)
        this->grafo[i]->grauida = this->grafo[i]->arestaida.size ();
}


// Realiza uma busca em profundidade no grafo
void Grafo::destruirgrafo ()
{
    for (int i = 0; i < this->grafo.size (); i++)
        delete this->grafo[i];
    grafo.clear ();
}


// Gera o grafo inverso
void Grafo::grafoinverso ()
{
    for (int i = 0; i < grafo.size (); i++)
    {
        grafo[i]->arestachegada.swap (grafo[i]->arestaida);
    }
}


// Printa os vertices e vizinhos do grafo
void Grafo::printgrafo ()
{
    cout << "\n";
    for (int i = 0; i < this->grafo.size (); i++)
    {
        cout << "Nome: " << this->grafo[i]->nome << " Cod: " << this->grafo[i]->codigo << " Credito: " << this->grafo[i]->creditos << " Grau: " << this->grafo[i]->grauentrada << " Prereq: ";
        for(int j = 0; j < this->grafo[i]->arestachegada.size (); j++)
        {
            cout << this->grafo[i]->arestachegada[j]->nome << " ";
        }
        //cout << " ArestaI: ";
        //for(int j = 0; j < this->grafo[i]->arestaida.size (); j++)
        //{
        //    cout << this->grafo[i]->arestaida[j]->codigo << " ";
        //}
        cout << "\n";
    }
}

