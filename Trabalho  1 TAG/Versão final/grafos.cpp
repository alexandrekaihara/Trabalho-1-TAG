/** \file grafos.cpp
 * \brief Arquivo com a implementacao da manipulacao do grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#include "grafos.h"

// Transfere os dados pegos do arquivo para um grafo (da classe Grafo) feito com a classe Vertice
void Grafo::criargrafo (Readfile *file)
{   
    int i;
    
    // Leitura do tamanho do grafo
    for (i = 0; i < 3; i++)
        sizes.push_back (file->filecontent[i]);
    
    // Alocacao dinamica dos vertices
    for(int j = 0; j < sizes[0]; j++)
        grafo.push_back (new Vertice);

    // O vetor trio guarda a quantidade de triângulos fechados que cada vertice forma com outros vertices
    trios.resize(sizes[0]);
    
    // Criacao das arestas
    for (; i < 2*sizes[2] + 2; i += 2)
    {
        // Subtrai-se - 1 pois os valores reais nao correspondem a posiçao no vetor
        grafo[file->filecontent[i] - 1]->vizinhos.push_back (file->filecontent[i + 1] - 1);
        grafo[file->filecontent[i + 1] - 1]->vizinhos.push_back (file->filecontent[i] - 1);
    }
}

// Imprime na tela os graus de cada vertice
void Grafo::printgrau ()
{
    cout << "Grau de cada vertice:\n";
    for(int i = 0; i < sizes[0]; i++)
    {
        cout << "Vertice: " << (i+1) << "\tGrau: " << grafo[i]->vizinhos.size () << endl;   
    }
}

// Acha os cliques maximais atraves do algoritmo de Bron-Kerbosch
void Grafo::findmaximalclique ()
{   
    cout << "\nCliques maximais: \n";
    vector<int> r, p(sizes[0]), x;

    // Iniciando o vetor P com todos os vértices do grafo
    for(int i = 0; i < sizes[0]; i++)
        p[i] = i;

    bronkerbosch(r, p, x);
    cout << "\n";
}

// Implementacao do algoritmo recursivo de Bron-Kerbosch
void Grafo::bronkerbosch (vector<int> &r, vector<int> &p, vector<int> &x)
{   
    // Detecta um clique maximal quando nao ha mais vizinhos em comum para serem analisados
    if (p.empty () && x.empty ()){
        cout << "Numero de Vertices: " << r.size() << "\tVertices: "; 
        
        for (int i = 0; i < r.size(); i++)
            cout << r[i] + 1 << " ";
        
        cout << endl;
    }
    
    
    // Prepara a proxima chamada recursiva do algorito
    int tam = p.size();
    for(int i = 0; i < tam; i++){
        vector<int> r1 = r, p1, x1;

        r1.push_back(p[0]); // r1 = r união com p[0] 
        intersection(p, grafo[p[0]]->vizinhos, p1); // p1 = intersecao de p com vizinhos de p[0]
        intersection(x, grafo[p[0]]->vizinhos, x1); // x1 = intersecao de x com vizinhos de p[0]

        bronkerbosch(r1, p1, x1);
        x.push_back(p[0]);
        p.erase(p.begin()); // Tira p[0] de p e o move para x para que ele nao seja considerado em outros testes de cliques maximais
    }
}

// Projeta a intersecao de dois vetores em um terceiro vetor. Usado no algoritmo de Bron-Kerbosch
void Grafo::intersection (vector<int> &vet, vector<int> &vizinhos, vector<int> &ans)
{
    for (int i = 0; i < vet.size (); i++)
        for (int j = 0; j < vizinhos.size (); j++)
            if (vet[i] == vizinhos[j])
                ans.push_back (vet[i]);
}

// Mostra o algoritmo de aglomeracao de cada vertice conforme dados obtidos no vetor trios
void Grafo::aglom ()
{
    // Soma e utilizado para calcular o coeficiente medio de aglomeracao
    double soma = 0;
    cout << "Indices de aglomeracao: " << endl;

    for (int i = 0; i < sizes[0]; i++){
        double indice, n = grafo[i]->vizinhos.size ();
        indice = trios[i];

        if (n < 2) // Se n tem 1 ou 0 vizinhos, seu indice de aglomeracao e 0
            indice = 0;
        else
            indice /= n*(n - 1);

        /* Normalmente, precisaria-se multiplicar indice por 2
         * mas do jeito que trios[i] e calculado, cada triangulo fechado ja e contado duas vezes */
        soma += indice;
        cout << "Vertice: " << (i+1) << "\tIndice de aglomeracao: " << indice << endl;   
    }

    cout << "\nCoeficiente Medio de Aglomeracao do Grafo: " << soma/sizes[0] << endl;
}

// Calcula a quantidade de trios fechados que cada vertice tem
void Grafo::triosf ()
{
    /* Para os vertices A, B, e C, e tomando como referencia o vertice A,
     * ambos triangulos A-B-C e A-C-B são contados. Assim, é necessario dividir o resultado por 2.
     * Essao divisao e neutralizada pela multiplicacao por 2 que e feita na hora do calculo do indice */
    for (int i = 0; i < sizes[0]; i++){
        for (int j = 0; j < grafo[i]->vizinhos.size (); j++){
            int m = grafo[i]->vizinhos[j];
            for (int k = 0; k < grafo[m]->vizinhos.size (); k++){
                int n = grafo[m]->vizinhos[k];
                if(binary_search(grafo[n]->vizinhos.begin (), grafo[n]->vizinhos.end (), i))
                    trios[i]++;
            }
        }
    }
}