/** \file graphsvizmanager.cpp
 * \brief Implementacao das funcoes em graphvizmanager.h
 * \author 18/0029690 - Alexandre Mitsuru Kaihara
 *         18/0016326 - Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#include "graphvizmanager.h"

std::string string_cvt::num_str (int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str ();
}


int string_cvt::str_num (std::string str)
{
    std::string::size_type sz = sizeof(str);
    return std::stoi (str, &sz, 10);
}

// Gera o grafo do curso
void graphviz::generategraph (Grafo* grafo)
{
    string_cvt cvt;
    string script = "digraph G {\n";

    for (int i = 0; i < grafo->grafo.size (); i++)
    {
        if (grafo->grafo[i]->grauentrada == 0 && grafo->grafo[i]->grauida == 0 )
            script += cvt.num_str (grafo->grafo[i]->codigo) + ";\n";
        else
        {
            for (int j = 0; j < grafo->grafo[i]->grauida; j++)
            {
                script += cvt.num_str (grafo->grafo[i]->codigo) + " -> " + cvt.num_str (grafo->grafo[i]->arestaida[j]->codigo) + ";\n";
            }
        }   
    }
    script += "}\n";

    ofstream myfile;
    myfile.open("grafo.gv");
    myfile << script;
    myfile.close();
    
    printf("DAG do curso: grafo.gv\n");
}

// Gera o gravo da ordenacao topologica
void graphviz::generateordenation (vector<Materia*> ordenacao)
{
    string_cvt cvt;
    string script = "digraph G {\n";
    script += "rankdir = LR;\n";
    
    for(int j = 0; j < 20; j++)
    {
        
        script += "subgraph ordenacao\n";
        script += "{\n";
        script += "node [style=filled,color=lightgrey];\n";
        
        for (int i = 0; i < ordenacao.size (); i++) 
        {
            script += cvt.num_str (ordenacao[i]->codigo);
            if (i != ordenacao.size()-1)
                script += " -> ";
        }
        script += "[color=white, style=dotted];\n}\n";
    }

    for(int i = 0; i < ordenacao.size (); i++)
    {
        for (int j = 0; j < ordenacao[i]->arestaida.size (); j++)
        {
            script += cvt.num_str (ordenacao[i]->codigo) + " -> " + cvt.num_str (ordenacao[i]->arestaida[j]->codigo) + ";\n";
        }
    }
    
    script += "start -> " + cvt.num_str (ordenacao[0]->codigo) + ";\n"; 
    script += cvt.num_str (ordenacao[(ordenacao.size()-1)]->codigo) + " -> end;\n";
    script += "start [shape=Mdiamond];\n";
    script += "end [shape=Msquare];\n";

    script += "}\n";

    ofstream myfile;
    myfile.open("ordenacao.gv");
    myfile << script;
    myfile.close();

    printf("Ordenacao Topologica: ordenacao.gv\n");
}

// Gera o grafico de um caminho critico em um arquivo com nome str.
void graphviz::generatepath (vector<Materia*> caminho, string str)
{
    string_cvt cvt;
    string script = "digraph G {\n";
    script += "rankdir = LR;\n";
    
    for(int j = 0; j < 20; j++)
    {
        
        script += "subgraph critical_path\n";
        script += "{\n";
        script += "node [style=filled,color=lightgrey];\n";
        
        for (int i = 0; i < caminho.size (); i++) 
        {
            script += cvt.num_str (caminho[i]->codigo);
            if (i != caminho.size()-1)
                script += " -> ";
        }
        script += "[color=white, style=dotted];\n}\n";
    }

    script += cvt.num_str (caminho[0]->codigo);
    for(int i = 0; i < caminho.size() - 1; i++)
    {
        script += " -> " + cvt.num_str (caminho[i+1]->codigo);
    }
    
    script += "start -> " + cvt.num_str (caminho[0]->codigo) + ";\n"; 
    script += cvt.num_str (caminho[(caminho.size()-1)]->codigo) + " -> end;\n";
    script += "start [shape=Mdiamond];\n";
    script += "end [shape=Msquare];\n";

    script += "}\n";

    ofstream myfile;
    myfile.open(str);
    myfile << script;
    myfile.close();
}