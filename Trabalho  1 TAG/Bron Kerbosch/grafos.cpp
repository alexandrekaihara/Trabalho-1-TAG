/** \file grafos.cpp
 * \brief Arquivo com a implementa��o da manipula��o do grafo
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#include "grafos.h"
#include <algorithm>


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

void Grafo::findmaximalclique ()
{
    vector<int> r, p, x;
    for(int i = 0; i < grafo.size(); i++)
        p.push_back(i);
    bronkerbosch(r, p, x);
}

void Grafo::bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x)
{
    cout << "Instanciação iniciada.\n";
    cout << "R: ";
    for(int i  = 0; i < r.size(); i++)
        cout << r[i] << " ";
    cout << "\nP: ";
    for(int i  = 0; i < p.size(); i++)
        cout << p[i] << " ";
    cout << "\nX: ";
    for(int i  = 0; i < x.size(); i++)
        cout << x[i] << " ";
    cout << "\n\n";
    if(p.size() == 0 && x.size() == 0){
        cout << "Maximal Clique found: R" << endl;
        for(int i = 0; i < r.size(); i++)
            cout << r[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 0; i < p.size(); i++){
        vector<int> r1 = r, p1(sizes[0]), x1(sizes[0]);
        r1.push_back(p1[i]);
        vector<int>::iterator it;
        it = std::set_intersection(p.begin(), p.end(), grafo[i]->vizinhos.begin(), grafo[i]->vizinhos.end(), p1);
        p1.resize(it - p1.begin());
        it = std::set_intersection(x.begin(), x.end(), grafo[i]->vizinhos.begin(), grafo[i]->vizinhos.end(), x1);
        x1.resize(it - x1.begin());
        bronkerbosch(r1, p1, x1);
        p1.erase(p.begin() + i, p.begin() + i);
        for(int j = 0; j < x1.size(); j++)
            if(x1[j] == p1[i]){
                x1.erase(x1.begin() + j, x1.begin() + j);
                break;
            }
    }
}

int Grafo::getindex (Vertice* vert) // Só serve pra debugar, vou apagar ela depois
{
    for(int i = 0; i < sizes[0]; i++)
        if(vert == grafo[i])
            return i;
    return -1;
}