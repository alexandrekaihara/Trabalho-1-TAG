/** \file utility.cpp
 * \brief Arquivo com a implementacao de funcoes diversas, de utilidade generica.
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 26/10/19
 */

#ifndef UTILITY_CPP
#define UTILITY_CPP

#include "grafo.cpp"
#include <string>

using namespace std;

int string_to_int(string str){
    int valor = 0;
    for(unsigned int i = 0; i < str.size(); i++){
        valor *= 10;
        valor += (str[i] - '0');
    }
    return valor;
}

bool sorthabilitacoes(Professor a, Professor b){
    if(a.habilitacoes < b.habilitacoes)
        return true;
    return false;
}

#endif