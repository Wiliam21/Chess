#include<list>
using namespace std;

class Square
{
private:
    int number;
    char color;
    bool occupied;
    list<int> moveToW;
    list<int> moveToB;
    list<int> totalMoves;

public:
    int getNumber();
    void setNumber(int);
    char getColor();
    void setColor(char);
    bool isOccupied();
    void setOccupied(bool occupied);
    list<int> getMoveToW();
    void setMoveToW(list<int> movetoW);
    list<int> getMoveToB();
    void setMoveToB(list<int> movetoB);
    void setTotalMoves(list<int> totalmoves);
    list<int> getTotalMoves();
};

int Square::getNumber()
{
    return number;
}

void Square::setNumber(int num)
{
    number = num;
}

char Square::getColor()
{
    return color;
}

void Square::setColor(char c)
{
    color = c;
}

bool Square::isOccupied()
{
    return occupied;
}

void Square::setOccupied(bool oc)
{
    occupied = oc;
}

list<int> Square::getMoveToW()
{
    return moveToW;
}

void Square::setMoveToW(list<int> movetoW)
{
    moveToW = movetoW;
}

list<int>Square::getMoveToB()
{
    return moveToB;
}

void Square::setMoveToB(list<int> movetoB)
{
    moveToB = movetoB;
}

list<int> Square::getTotalMoves()
{
    return totalMoves;
}

void Square::setTotalMoves(list<int> totalmoves)
{
    totalMoves = totalmoves;
}
