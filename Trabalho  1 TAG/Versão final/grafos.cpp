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
    trios.resize(sizes[0]);
    // Criacao das arestas
    for (; i < 2*sizes[2] + 2; i += 2)
    {
        // Subtrai-se - 1 pois os valores reais nao correspondem a posiçao no vetor
        grafo[file->filecontent[i] - 1]->vizinhos.push_back (file->filecontent[i + 1] - 1);
        //(*grafos[(*file).filecontent[i] - 1]).vizinhos.push_back((*file)filecontent[i+1] - 1);

        grafo[file->filecontent[i + 1] - 1]->vizinhos.push_back (file->filecontent[i] - 1);
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
    cout << "Grau de cada vertice:\n";
    for(int i = 0; i < sizes[0]; i++)
    {
        cout << "Vertice: " << (i+1) << "\tGrau: " << grafo[i]->vizinhos.size () << endl;   
    }
}


void Grafo::findmaximalclique ()
{
    cout << "\nCliques maximais: \n";
    // Iniciando o vetor P com todos os vértices do grafo
    vector<int> r, p(sizes[0]), x;
    for(int i = 0; i < sizes[0]; i++)
        p[i] = i;
    bronkerbosch(r, p, x);
    cout << "\n";
}


void Grafo::bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x)
{   
    if(p.empty() && x.empty()){
        cout << "Numero de Vertices: " << r.size() << "\tVertices: "; 
        for(int i = 0; i < r.size(); i++)
            cout << r[i] + 1 << " ";
        cout << endl;
        return;
        
    }
    
    for(int i = 0; i < p.size(); i++){
        vector<int> r1 = r, p1, x1;
        r1.push_back(p[0]);
        intersection(p, grafo[p[0]]->vizinhos, p1);
        intersection(x, grafo[p[0]]->vizinhos, x1);
        bronkerbosch(r1, p1, x1);
        p.erase(p.begin());
        x.push_back(p[0]);
    }
}

void Grafo::intersection (vector<int> &vet, vector<int> &vizinhos, vector<int> &ans)
{
    for(int i = 0; i < vet.size(); i++)
        for(int j = 0; j < vizinhos.size(); j++)
            if(vet[i] == vizinhos[j])
                ans.push_back(vet[i]);
}

void Grafo::aglom ()
{
    double soma = 0;
    cout << "Índices de aglomeração: " << endl;
    for(int i = 0; i < sizes[0]; i++){
        double indice, n = grafo[i]->vizinhos.size();
        indice = trios[i];
        if(n < 2)
            indice = 0;
        else
            indice /= n*(n - 1);
        soma += indice;
        cout << "Vertice: " << (i+1) << "\tIndice de aglomeracao: " << indice << endl;   
    }
    cout << "\nCoeficiente Médio de Aglomeração do Grafo: " << soma/sizes[0] << endl;
}

void Grafo::triosf ()
{
    for(int i = 0; i < sizes[0]; i++){
        for(int j = 0; j < grafo[i]->vizinhos.size(); j++){
            int m = grafo[i]->vizinhos[j];
            for(int k = 0; k < grafo[m]->vizinhos.size(); k++){
                int n = grafo[m]->vizinhos[k];
                if(binary_search(grafo[n]->vizinhos.begin(), grafo[n]->vizinhos.end(), i))
                    trios[i]++;
            }
        }
    }
}