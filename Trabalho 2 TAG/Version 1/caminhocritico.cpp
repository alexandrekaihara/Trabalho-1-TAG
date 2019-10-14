/* \file caminhocritico.cpp
 * \brief Implementacao das funcoes em caminhocritico.h
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#include "caminhocritico.h"
#include "graphvizmanager.h"

// Calcula o peso_acumulado para todos os vertices para calcular o caminho critico
void calcular_caminhoscriticos (vector<Materia*> fila)
{
    for(int i = 0; i < fila.size(); i++)
    {   
        /* Uma materia e ignorada se:
         * a) Ela ja foi escolhida em um caminho critico;
         * b) Ela tem como pre-requisito uma materia ignorada.
        */
        for(int j = 0; j < fila[i]->arestachegada.size(); j++)
            if(fila[i]->arestachegada[j]->creditos < 0)
                fila[i]->creditos = -1000;
        if(fila[i]->creditos < 0)
            continue;

        fila[i]->peso_acumulado += fila[i]->creditos;
        for(int j = 0; j < fila[i]->arestaida.size(); j++)
            if(fila[i]->arestaida[j]->creditos >= 0)
                fila[i]->arestaida[j]->peso_acumulado = max(fila[i]->arestaida[j]->peso_acumulado, fila[i]->peso_acumulado);
    }
}

// Detecta e separa o vetor do caminho critico e o passa para o graphviz
void mostrar_caminhoscriticos (vector<Materia*> fila, int index)
{
    int maior = 0;
    Materia* carregado;

    // Pega o ultimo elemento do caminho critico
    for(int i = 0; i < fila.size(); i++){
        if(fila[i]->peso_acumulado > maior){
            maior = fila[i]->peso_acumulado;
            carregado = fila[i];
        }
    }
    
    vector<Materia*> caminho;
    caminho.push_back(carregado);
    
    // Pega os elementos restantes do caminho critico na ordem inversa
    while(carregado->arestachegada.size() != 0){
        maior = 0;
        Materia* proximo;
        for(int i = 0; i < carregado->arestachegada.size(); i++){
            if(carregado->arestachegada[i]->peso_acumulado > maior){
                maior = carregado->arestachegada[i]->peso_acumulado;
                proximo = carregado->arestachegada[i];
            }
        }
        caminho.push_back(proximo);
        carregado = proximo;
    }
    reverse(caminho.begin(), caminho.end());

    // Faz o grafo do caminho critico no graphviz
    graphviz critical_path;
    string arquivo = "criticalpath_" + to_string(index) + ".gv";
    critical_path.generatepath(caminho, arquivo);

    // Impede que os elementos escolhidos sejam escolhidos em outro caminho critico
    for(int i = 0; i < caminho.size(); i++)
        caminho[i]->creditos = -1000;
}

// Calcula o caminho critio num vezes. A cada iteracao, as materias em caminhos criticos ja detectados sao excluidas.
void gerar_caminhoscriticos (vector<Materia*> fila, int num)
{
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < fila.size(); j++)
            fila[j]->peso_acumulado = 0;
        calcular_caminhoscriticos(fila);
        mostrar_caminhoscriticos(fila, i+1);
        printf("Caminho critico %d: criticalpath_%d.gv\n", i+1, i+1);
    } 
}
