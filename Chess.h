#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include "square.h"
#include "SquareMapItem.h"
using namespace std;

#define ROWS_NUM 4

class Chess
{
    int TOTAL_PLAYS_PER_PLAYER = ROWS_NUM * ROWS_NUM;
    int MAX_MOVES_PER_WINNER_PLAY = 6;
    string archivo_ganadores = "jugadas_ganadoras.txt";
    string archivo_todas = "all_plays.txt";
    int q0_1 = 1;
    int q0_2 = 4;
    int finalState1 = 16;
    int finalState2 = 13;
    map<int, SquareMapItem> squaresMap;
    Square squareBoard[ROWS_NUM][ROWS_NUM];
    ofstream wins, all;
    int totalIterations = 0;

public:
    int getTotalIterations();
    void crearTablero();
    void printPlaysFile();
    void abrirArchivos();
    void cerrarArchivos();
    void printPlays(int, int, list<int>, int, list<int>);
    list<int> getNextMoves(int);
    void getSquareMoves();
    void getMoves(int, int);
};

int Chess::getTotalIterations()
{
    return totalIterations;
}

void Chess::abrirArchivos()
{
    wins.open(archivo_ganadores);
    all.open(archivo_todas);
}

void Chess::cerrarArchivos()
{
    wins.close();
    all.close();
}

void Chess::printPlaysFile(void)
{
    list<int> temp = {q0_1};
    printPlays(q0_1, finalState1, getNextMoves(q0_1), 0, temp);
    list<int> temp2 = {q0_2};
    printPlays(q0_2, finalState2, getNextMoves(q0_2), 0, temp2);
}

list<int> Chess::getNextMoves(int actual)
{
    return squaresMap.at(actual).getTotalMoves();
}

void Chess::printPlays(int square, int finalState, list<int> nextMoves, int movesCounter, list<int> path)
{
    if (square == finalState)
    {
        if (path.size() <= MAX_MOVES_PER_WINNER_PLAY)
        {
            path.push_back(square);
            for (int it : path)
            {
                wins << it << " ";
                all << it << " ";
                cout << it << " ";
            }
            cout << endl;
            wins << endl;
            all << endl;
            return;
        }
    }
    else if (movesCounter < TOTAL_PLAYS_PER_PLAYER)
    {
        path.push_back(square);
        for (int it : path)
        {
            if (it != 0)
            {
                totalIterations++;
                movesCounter++;
                printPlays(it, finalState, squaresMap.at(it).getTotalMoves(), movesCounter, path);
            }
        }
    }
    else if (movesCounter == TOTAL_PLAYS_PER_PLAYER)
    {
        for (int it : path)
        {
            all << it << " ";
            cout << it << " ";
        }
        all << endl;
        cout<<endl;
        return;
    }
}

void Chess::crearTablero()
{
    SquareMapItem squareMapItem;
    Square square;
    int counter = 1;
    char color;
    //pendiente de revision de rangos e indices
    for (int i = 0; i < ROWS_NUM; i++)
    {
        for (int j = 0; j < ROWS_NUM; j++)
        {
            squareMapItem.setRow(i);
            squareMapItem.setColumn(j);
            squaresMap.insert(pair<int, SquareMapItem>(counter, squareMapItem));
            if ((counter + i) % 2 == 1)
            {
                color = 'w';
            }
            else
            {
                color = 'b';
            }
            square.setNumber(counter);
            square.setColor(color);
            squareBoard[i][j] = square;
            counter++;
        }
    }
    getSquareMoves();
}

void Chess::getSquareMoves()
{
    for (int i = 0; i < ROWS_NUM; i++)
    {
        for (int j = 0; j < ROWS_NUM; j++)
        {
            getMoves(i, j);
        }
    }
}

void Chess::getMoves(int row, int col)
{
    int wMoves[4], bMoves[4], totalMoves[8], wMovesCounter = 0, bMovesCounter = 0, totalMovesCounter = 0;
    if (row > 0)
    {
        // Top left
        if (col > 0)
        {
            if (squareBoard[row - 1][col - 1].getColor() == 'w')
            {
                wMoves[wMovesCounter++] = squareBoard[row - 1][col - 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row - 1][col - 1].getNumber();
            }
            else
            {
                bMoves[bMovesCounter++] = squareBoard[row - 1][col - 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row - 1][col - 1].getNumber();
            }
        }
        // Top right
        if (col < ROWS_NUM - 1)
        {
            if (squareBoard[row - 1][col + 1].getColor() == 'w')
            {
                wMoves[wMovesCounter++] = squareBoard[row - 1][col + 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row - 1][col + 1].getNumber();
            }
            else
            {
                bMoves[bMovesCounter++] = squareBoard[row - 1][col + 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row - 1][col + 1].getNumber();
            }
        }
        // Top
        if (squareBoard[row - 1][col].getColor() == 'w')
        {
            wMoves[wMovesCounter++] = squareBoard[row - 1][col].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row - 1][col].getNumber();
        }
        else
        {
            bMoves[bMovesCounter++] = squareBoard[row - 1][col].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row - 1][col].getNumber();
        }
    }
    // Check bottom boundary
    if (row < ROWS_NUM - 1)
    {
        // Bottom left
        if (col > 0)
        {
            if (squareBoard[row + 1][col - 1].getColor() == 'w')
            {
                wMoves[wMovesCounter++] = squareBoard[row + 1][col - 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row + 1][col - 1].getNumber();
            }
            else
            {
                bMoves[bMovesCounter++] = squareBoard[row + 1][col - 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row + 1][col - 1].getNumber();
            }
        }
        // Bottom right
        if (col < ROWS_NUM - 1)
        {
            if (squareBoard[row + 1][col + 1].getColor() == 'w')
            {
                wMoves[wMovesCounter++] = squareBoard[row + 1][col + 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row + 1][col + 1].getNumber();
            }
            else
            {
                bMoves[bMovesCounter++] = squareBoard[row + 1][col + 1].getNumber();
                totalMoves[totalMovesCounter++] = squareBoard[row + 1][col + 1].getNumber();
            }
        }
        // Bottom
        if (squareBoard[row + 1][col].getColor() == 'w')
        {
            wMoves[wMovesCounter++] = squareBoard[row + 1][col].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row + 1][col].getNumber();
        }
        else
        {
            bMoves[bMovesCounter++] = squareBoard[row + 1][col].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row + 1][col].getNumber();
        }
    }
    // Check left boundary
    if (col > 0)
    {
        // Left
        if (squareBoard[row][col - 1].getColor() == 'w')
        {
            wMoves[wMovesCounter++] = squareBoard[row][col - 1].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row][col - 1].getNumber();
        }
        else
        {
            bMoves[bMovesCounter++] = squareBoard[row][col - 1].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row][col - 1].getNumber();
        }
    }
    // Check right boundary
    if (col < ROWS_NUM - 1)
    {
        // Right
        if (squareBoard[row][col + 1].getColor() == 'w')
        {
            wMoves[wMovesCounter++] = squareBoard[row][col + 1].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row][col + 1].getNumber();
        }
        else
        {
            bMoves[bMovesCounter++] = squareBoard[row][col + 1].getNumber();
            totalMoves[totalMovesCounter++] = squareBoard[row][col + 1].getNumber();
        }
    }
    list<int> wmoves(wMoves, wMoves + sizeof(wMoves) / sizeof(int));
    list<int> bmoves(bMoves, bMoves + sizeof(bMoves) / sizeof(int));
    list<int> totalmoves(totalMoves, totalMoves + sizeof(totalMoves) / sizeof(int));
    squareBoard[row][col].setMoveToW(wmoves);
    squareBoard[row][col].setMoveToB(bmoves);
    squareBoard[row][col].setTotalMoves(totalmoves);
    squaresMap.at(squareBoard[row][col].getNumber()).setMoveToW(wmoves);
    squaresMap.at(squareBoard[row][col].getNumber()).setMoveToB(bmoves);
    squaresMap.at(squareBoard[row][col].getNumber()).setTotalMoves(totalmoves);
}
