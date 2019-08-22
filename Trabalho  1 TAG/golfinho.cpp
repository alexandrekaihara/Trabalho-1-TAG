#include "golfinho.h"


ifstream criargrafo::openfile ()
{
    ifstream inFile;

    inFile.open("soc-dolphins.mtx");

    return inFile;
}


bool learquivo(golfinho grafo)
{
    int qtd_v;
    cin >> qtd_v;
    for(int i = 0; i < qtd_v; i++){

    }
    int a, b;
    for(int i = 0; i < 10; i++){
        cin >> a >> b;
        grafo[a].vizinhos.push_back(b);
        grafo[b].vizinhos.push_back(a);
    }
}