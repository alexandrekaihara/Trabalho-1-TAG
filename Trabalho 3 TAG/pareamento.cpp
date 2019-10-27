/** \file pareamento.cpp
 * \brief Arquivo com a implementacao das funcoes de pareamento.
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 26/10/19
 */

#ifndef PAREAMENTO_CPP
#define PAREAMENTO_CPP

#include "grafo.cpp"
#include "utility"

using namespace std;

int compativel(Professor &professor, Escola &escola){
    for(int i = 0; i < escola.vagas.size(); i++){
        if(escola.vagas[i] <= professor.habilitacoes){
            return i+1;
        } 
    }
    return 0;
}

void gerar_pareamento(Grafo &grafo){
    grafo.pareados = 0;
    for(int i = 0; i < grafo.professores.size(); i++){
        for(int j = 0; j < grafo.professores[i].preferencias.size(); j++){
            int check = compativel(grafo.professores[i], grafo.escolas[grafo.professores[i].preferencias[j]]); 
            if(check){
                grafo.escolas[grafo.professores[i].preferencias[j]].vagas[check-1] = 1000;
                grafo.escolas[grafo.professores[i].preferencias[j]].emparelhados.push_back(i);
                grafo.professores[i].escolha = grafo.professores[i].preferencias[j];
                grafo.pareados++;
                break;
            }
        }
    }
}

void mostrar_pareamento(Grafo &grafo){
    cout << "Pareamentos feitos: " << grafo.pareados << endl;
    cout << "Pareamentos por escola: " << endl;
    for(int i = 0; i < grafo.escolas.size(); i++){
        cout << "Escola " << grafo.escolas[i].codigo << ": ";
        for(int j = 0; j < grafo.escolas[i].emparelhados.size(); j++){
            cout << "P" << grafo.escolas[i].emparelhados[j] << " ";
        }
        cout << "(" << grafo.escolas[i].emparelhados.size() << "/" << grafo.escolas[i].vagas.size() << " vagas preenchidas)" << endl;
    }

    cout << "\nPareamentos por professor: " << endl;
    for(int i = 0; i < grafo.professores.size(); i++){
        cout << "Professor " << grafo.professores[i].codigo << ": ";
        if(grafo.professores[i].escolha == -1){
            cout << "Nao foi pareado." << endl;
        }
        else{
            cout << "E" << grafo.professores[i].escolha << endl;
        }
    }
}

#endif