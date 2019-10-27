/** \file readfile.cpp
 * \brief Arquivo com a implementacao das funcoes que leem o arquivo.
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 26/10/19
 */

#ifndef READFILE_CPP
#define READFILE_CPP

#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "grafo.cpp"
#include "utility.cpp"

using namespace std;


void readcontent(vector<Professor> &professores, vector<Escola> &escolas, ifstream &infile){
    string s;
    while(getline(infile, s)){
        if(s == "" || s[0] == '/'){
            continue;
        }

        if(s[1] == 'P'){
            Professor pr;
            string entrada;
            unsigned int pt = 2;
            for(; pt < s.size() && s[pt] != ','; pt++){
                entrada += s[pt];
            }
            pr.codigo = string_to_int(entrada);

            entrada = "";
            for(pt += 2; pt < s.size() && s[pt] != ')'; pt++){
                entrada += s[pt];
            }
            
            pr.habilitacoes = string_to_int(entrada);

            pt+=2;
            while(pt+3 < s.size()){
                entrada = "";
                for(pt += 3; pt < (s.size()-1) && s[pt] != ','; pt++){
                    while(s[pt] == ' ' || s[pt] == 'E') pt++;
                    entrada += s[pt];
                }
                pr.preferencias.push_back(string_to_int(entrada));
            }
            pr.escolha = -1;
            professores.push_back(pr);
        }
        
        if(s[1] == 'E'){
            Escola esc;
            string entrada;
            unsigned int pt = 2;
            for(; pt < s.size() && s[pt] != ')'; pt++){
                entrada += s[pt];
            }
            esc.codigo = string_to_int(entrada);

            while(pt+3 < s.size()){
                entrada = "";
                for(pt += 3; pt < s.size() && s[pt] != ')'; pt++){
                    entrada += s[pt];
                }
                esc.vagas.push_back(string_to_int(entrada));
            }
            sort(esc.vagas.begin(), esc.vagas.end());
            escolas.push_back(esc);
        }
    }
}

ifstream openfile(string &file){
    ifstream infile(file);
    if(!infile){
        cout << "Erro ao abrir o arquivo " << file << endl;
    }
    return infile;
}

bool readfile(Grafo &grafo, string file){
    ifstream infile = openfile(file);

    if(!infile){
        return false;
    }

    readcontent(grafo.professores, grafo.escolas, infile);

    infile.close();

    return true;
}

#endif