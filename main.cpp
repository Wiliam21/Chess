#include "Chess.h"
#include<iostream>
using namespace std;

int main()
{
    Chess chess;

    chess.crearTablero();
    chess.abrirArchivos();
    chess.printPlaysFile();
    chess.cerrarArchivos();
}