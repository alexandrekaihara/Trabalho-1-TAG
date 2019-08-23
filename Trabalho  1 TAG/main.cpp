/** \file golfinho.cpp
 * \brief Arquivo Principal
 * \author Alexandre Mitsuru Kaihara e Felipe Fod�o da Matem�tica
 * \since 22/08/19
 */
#include "golfinho.h"
#include "grafos.h"
#include <iostream>
#include <fstream>

int main ()
{
    criargrafo a;
    a.openfile ();
    a.readfile ();
    cout << "Oi" << a.inFile;

    return 0;
}
