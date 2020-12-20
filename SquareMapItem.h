#include <list>
using namespace std;

class SquareMapItem
{

    int row;
    int column;
    list<int> moveToW;
    list<int> moveToB;
    list<int> totalMoves;
public:
    int getRow();

    void setRow(int row);

    int getColumn();

    void setColumn(int col);

    list<int> getMoveToW();

    void setMoveToW(list<int> movetoW);

    list<int> getMoveToB();

    void setMoveToB(list<int> movetoB);

    list<int> getTotalMoves();

    void setTotalMoves(list<int> totalmoves);
};

int SquareMapItem::getRow()
{
    return row;
}

void SquareMapItem::setRow(int r)
{
    row = r;
}

int SquareMapItem::getColumn()
{
    return column;
}

void SquareMapItem::setColumn(int col)
{
    column = col;
}

list<int> SquareMapItem::getMoveToW()
{
    return moveToW;
}

void SquareMapItem::setMoveToW(list<int> movetoW)
{
    moveToW = movetoW;
}

list<int> SquareMapItem::getMoveToB()
{
    return moveToB;
}

void SquareMapItem::setMoveToB(list<int> movetoB)
{
    moveToB = movetoB;
}

list<int> SquareMapItem::getTotalMoves()
{
    return totalMoves;
}

void SquareMapItem::setTotalMoves(list<int> totalmoves)
{
    totalMoves = totalmoves;
}