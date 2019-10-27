/** \file main.cpp
 * \brief Arquivo principal.
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 26/10/19
 */

// Para compilar, use: g++ main.cpp -o tag

using namespace std;

#include <vector>
#include <iostream>
#include "readfile.cpp"
#include "pareamento.cpp"
#include "grafo.cpp"

int main(){
    Grafo grafo;

    if(!readfile(grafo, "entradaProj3TAG.txt")){
        return 0;
    }

    gerar_pareamento(grafo);

    mostrar_pareamento(grafo);

}