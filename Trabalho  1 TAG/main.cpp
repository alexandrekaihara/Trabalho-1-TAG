/** \file golfinho.cpp
 * \brief Arquivo Principal
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
// Diretiva de compilação: g++ -std=c++11 -o main main.cpp golfinho.cpp grafos.cpp
#include "grafos.h"
#include "readfiles.h"
#include <iostream>
#include <fstream>

int main ()
{
    Readfile a;
    a.openfile ();
    a.readfile ();

    for(int i = 0; i < a.filecontent.size (); i++)
    {
        cout << a.filecontent[i] << endl;
    }

    return 0;
}

