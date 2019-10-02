#include "ordenacaotopologica.h"


bool compare (Materia* a, Materia* b)
{
    if(a->grauentrada > b->grauentrada)
    {
        return false;
    }
    else if (a->grauentrada == b->grauentrada)
    {
        // Se a quantidade de pre-requisitos de outras materias for maior, deve vir depois
        if (a->grauida > b->grauida) {
             return true;
        }
        // Se a quantidade de creditos for maior, deve vir depois 
        else if (a->grauida == b->grauida)
        {
            if(a->creditos > b->creditos) 
                return true;
            else 
                return false;
        }
        else return false;
    }
    else return true;
}


void ordenacaotopologica::exec (Grafo* grafo)
{
    vector<Materia*> fila (grafo->grafo);

    // Ordenacao inicial
    sort (grafo->grafo.begin (), grafo->grafo.end (), compare);

    while(!fila.empty ())
    {
        // Diminui o grau de chegada e retira o prerequisito das materias vinculadas a materia que sera retirada
        for (int i = 0; i < fila[0]->grauida; i++)
        {    
            // Retira a materia como prerequisito
            for(int j = 0; j < fila[0]->arestaida[i]->grauentrada; j++)
            {        
                if(fila[0] == fila[0]->arestaida[i]->arestachegada[j]){
                    fila[0]->arestaida[i]->arestachegada.erase(fila[0]->arestaida[i]->arestachegada.begin () + j);
                    break;
                }
            }
            // Diminui o grau de prerequisitos
            fila[0]->arestaida[i]->grauentrada--;
        }

        // Adiciona a materia na ordenacao topologica e retira da fila
        ordenacao.push_back (fila[0]);
        fila.erase(fila.begin ());

        // Ordena a fila de acordo com a funcao compare
        sort (grafo->grafo.begin (), grafo->grafo.end (), compare);
    }
}


void ordenacaotopologica::printordenacao ()
{
    for(int i = 0; i < ordenacao.size (); i++)
        cout << "COD: " << ordenacao[i]->codigo << " Creditos: " << ordenacao[i]->creditos << "\n";
}