/** \file caminhocritico.h
 * \brief Arquivo que implementa o caminho critico de um grafo
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#ifndef CAMINHOCRITICO_H_INCLUDED
#define CAMINHOCRITICO_H_INCLUDED


using namespace std;

#include <algorithm>
#include "grafos.h"
#include "readfiles.h"

void calcular_caminhoscriticos(vector<Materia*> fila);

void mostrar_caminhoscriticos(Grafo* grafo);

void gerar_caminhoscriticos(vector<Materia*> fila, int num);

#endif
