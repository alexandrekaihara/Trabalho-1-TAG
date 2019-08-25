/** \file readfiles.h
 * \brief Arquivo com a implementacao da geracao dos vertices do grafo a partir do arquivo .mtx
 * \author Alexandre Mitsuru Kaihara e Felipe Xavier Barbosa da Silva
 * \since 22/08/19
 */
#include "readfiles.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Abre o arquivo soc-dolphins.mtx, e encerra o programa se a leitura for mal-sucedida
bool Readfile::openfile ()
{
    this->inFile.open("soc-dolphins.mtx");

    if (this->inFile.fail ())
    {
        cout << "Nao foi possivel abrir o arquivo soc-dolphins.mtx." << endl;
        return false;
    }
    return true;
}

// Le o arquivo para o vetor de inteiros filecontent
void Readfile::readfile ()
{
    string temp;
    string::size_type sz;
    
    while(!inFile.eof())
    {
        inFile >> temp;
        filecontent.push_back (stoi(temp, &sz, 10));
    }
}

// Fecha o arquivo apos encerrada a leitura
void Readfile::closefile ()
{
    inFile.close ();
}