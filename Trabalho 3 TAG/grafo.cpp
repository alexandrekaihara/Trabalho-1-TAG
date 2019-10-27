/** \file grafo.cpp
 * \brief Arquivo com a implementacao das classes relacionadas ao grafo.
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 26/10/19
 */

#ifndef GRAFO_CPP
#define GRAFO_CPP

using namespace std;

class Professor{
    public:
        int codigo;
        int habilitacoes;
        int escolha;
        vector<int> preferencias;
};

class Escola{
    public:
        int codigo;
        vector<int> vagas;
        vector<int> emparelhados;
};

class Grafo{
    public:
        vector<Professor> professores;  
        vector<Escola> escolas;
        int pareados;
};

#endif