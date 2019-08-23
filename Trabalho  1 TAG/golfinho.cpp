#include "golfinho.h"
#include <fstream>
#include <vector>

using namespace std;


void criargrafo::openfile ()
{
    this->inFile.open("soc-dolphins.mtx");
}


void criargrafo::readfile ()
{
    string temp;
    while(!inFile.eof())
    {
        inFile >> temp;
        content = content + temp;
    }
}

//bool learquivo(golfinho grafo)
//{
//    int qtd_v;
//    cin >> qtd_v;
//    for(int i = 0; i < qtd_v; i++){
//
//    }
//    int a, b;
//    for(int i = 0; i < 10; i++){
//        cin >> a >> b;
//        grafo[a].vizinhos.push_back(b);
//        grafo[b].vizinhos.push_back(a);
//    }
//}