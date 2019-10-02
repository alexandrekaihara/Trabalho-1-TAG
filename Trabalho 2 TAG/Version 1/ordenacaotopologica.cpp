#include "ordenacaotopologica.h"


bool compare (Materia* a, Materia* b)
{
    if(a->grauentrada > b->grauentrada)
    {
        return false;
    }
    else if (a->grauentrada == b->grauentrada)
    {
        // Se a quantidade de creditos for maior, deve vir depois
        if (a->creditos >=  b->creditos) {
             return false;
        }
        else return true;
    }
    else return true;
}


void ordenacaotopologica::exec (Grafo* grafo)
{
    vector<Materia*> fila (grafo->grafo);
   
    while(!fila.empty ())
    {
        ordenacao.push_back (fila[0]);
        fila.erase(0);
        sort (grafo->grafo.begin (), grafo->grafo.end (), compare);
    }
    


}


void ordenacaotopologica::intersection (vetor<Materia*> grafo)
{
    
}