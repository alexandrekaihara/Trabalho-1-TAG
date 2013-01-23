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
    cout << script << "\n";

    ofstream myfile;
    myfile.open("grafo.gv");
    myfile << script;
    myfile.close();
}


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
            //script += ordenacao[i]->nome;
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
            //script += ordenacao[i]->nome + " -> " + ordenacao[i]->arestaida[j]->nome + ";\n";
        }
    }
    
    script += "start -> " + cvt.num_str (ordenacao[0]->codigo) + ";\n"; 
    script += cvt.num_str (ordenacao[(ordenacao.size()-1)]->codigo) + " -> end;\n";
    script += "start [shape=Mdiamond];\n";
    script += "end [shape=Msquare];\n";

    script += "}\n";

    cout << script << "\n";

    ofstream myfile;
    myfile.open("ordenacao.gv");
    myfile << script;
    myfile.close();
}