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


void Grafo::findmaximalclique ()
{
    // Iniciando o vetor P com todos os vértices do grafo
    vector<int> r, p, x;
    for(int i = 0; i < grafo.size(); i++)
        p.push_back(i);

    bronkerbosch(r, p, x);
}


void Grafo::bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x)
{
    // Para debugação. Imprime os vetores R, P e X na chamada atual.
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

    // 
    if(p.empty() && x.empty()){
        cout << "Clique maximal encontrado: R" << endl;
        for(int i = 0; i < r.size(); i++)
            cout << r[i] << " ";
        cout << endl;
        return;
    }
    for(int i = 0; i < p.size(); i++){
        vector<int> r1 = r, p1, x1;

        // Novo R
        r1.push_back(p1[i]);

        // Novo P
        for(int k = 0; k < p.size(); k++)
            for(int l = 0; l < grafo[k]->vizinhos.size(); l++)
                if(p[k] == grafo[k]->vizinhos[l])
                    p1.push_back(k);

        // Novo X
        for(int k = 0; k < x.size(); k++)
            for(int l = 0; k < grafo[k]->vizinhos.size(); l++)
                if(x[k] == grafo[k]->vizinhos[l])
                    x1.push_back(k);

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


void Clique::adicionarclique (vector<int> clique)
{
    subgrafos.push_back (clique);
}


void Clique::printcliques ()
{
    cout << "Cliques maximais: \n\n";
    for (int i = 0; i < subgrafos.size (); i++)
    {
        cout << "Numero de Vertices: " << subgrafos[i].size () << "\tVertices: "; 
       
        for(int j = 0; j < subgrafos[i].size (); j++)
        {
            cout << subgrafos[i][j] << " ";
        }
       
        cout << "\n";
    }
}