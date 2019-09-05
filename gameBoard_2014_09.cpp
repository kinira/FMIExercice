#include <iostream>
#include <vector>
using namespace std;

const int fieldSize = 50;
int gamefield[fieldSize][fieldSize];

struct Point
{
    int x, y;

    Point()
    {
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    bool operator==(Point& other)
    {
        return this->x == other.x && this->y == other.y;
    }
};

class GamePlayer
{
private:
    Point current;

public:
    GamePlayer();
    ~GamePlayer();
    GamePlayer(const GamePlayer &);
    GamePlayer &operator=(const GamePlayer);
    Point getPosition() const;
    virtual vector<Point> allowedMoves();
};

Point GamePlayer::getPosition() const
{
    return current;
}

class Knight : public GamePlayer
{
private:
    Point current;
    bool noFiresAround(const Point &);

public:
    Knight();
    Knight(const Point);
    vector<Point> allowedMoves();
};

Knight::Knight()
{
    this->current = Point(0, 0);
}

Knight::Knight(const Point curr)
{
    this->current = curr;
}

bool Knight::noFiresAround(const Point &p)
{
    if (p.x - 1 >= 0 && p.y - 1 >= 0 && gamefield[p.x - 1][p.y - 1] == 1)
    {
        return false;
    }
    if (p.x - 1 >= 0 && gamefield[p.x - 1][p.y] == 1)
    {
        return false;
    }
    if (p.x - 1 >= 0 && p.y + 1 < fieldSize && gamefield[p.x - 1][p.y + 1] == 1)
    {
        return false;
    }
    if (p.y - 1 >= 0 && gamefield[p.x][p.y - 1] == 1)
    {
        return false;
    }
    if (p.y + 1 < fieldSize && gamefield[p.x][p.y + 1] == 1)
    {
        return false;
    }
    if (p.x + 1 < fieldSize && p.y - 1 >= 0 && gamefield[p.x + 1][p.y - 1] == 1)
    {
        return false;
    }
    if (p.x + 1 < fieldSize && gamefield[p.x + 1][p.y] == 1)
    {
        return false;
    }
    if (p.x + 1 < fieldSize && p.y + 1 < fieldSize && gamefield[p.x + 1][p.y + 1] == 1)
    {
        return false;
    }

    return true;
}

vector<Point> Knight::allowedMoves()
{
    vector<Point> moves = vector<Point>();
    if (current.x - 1 >= 0 && current.y - 1 >= 0 && gamefield[current.x - 1][current.y - 1] == 0 && noFiresAround(Point(current.x - 1, current.y - 1)))
    {
        moves.push_back(Point(current.x - 1, current.y - 1));
    }
    if (current.x - 1 >= 0 && gamefield[current.x - 1][current.y] == 0 && noFiresAround(Point(current.x - 1, current.y)))
    {
        moves.push_back(Point(current.x - 1, current.y));
    }
    if (current.x - 1 >= 0 && current.y + 1 < fieldSize && gamefield[current.x - 1][current.y + 1] == 0 && noFiresAround(Point(current.x - 1, current.y + 1)))
    {
        moves.push_back(Point(current.x - 1, current.y + 1));
    }
    if (current.y - 1 >= 0 && gamefield[current.x][current.y - 1] == 0 && noFiresAround(Point(current.x, current.y - 1)))
    {
        moves.push_back(Point(current.x, current.y - 1));
    }
    if (current.y + 1 < fieldSize && gamefield[current.x][current.y + 1] == 0 && noFiresAround(Point(current.x, current.y + 1)))
    {
        moves.push_back(Point(current.x, current.y + 1));
    }
    if (current.x - 1 >= 0 && current.y - 1 >= 0 && gamefield[current.x - 1][current.y - 1] == 0 && noFiresAround(Point(current.x - 1, current.y - 1)))
    {
        moves.push_back(Point(current.x - 1, current.y - 1));
    }
    if (current.x - 1 >= 0 && gamefield[current.x - 1][current.y] == 0 && noFiresAround(Point(current.x - 1, current.y)))
    {
        moves.push_back(Point(current.x - 1, current.y));
    }
    if (current.x - 1 >= 0 && current.y + 1 < fieldSize && gamefield[current.x + 1][current.y] == 0 && noFiresAround(Point(current.x - 1, current.y - 1)))
    {
        moves.push_back(Point(current.x - 1, current.y + 1));
    }
    return moves;
}

class SeaMonster : public GamePlayer
{
private:
    Point current;
    vector<Point> getAllWaterInThisDirection(const Point, vector<Point>, bool, bool);

public:
    SeaMonster();
    SeaMonster(const Point);
    ~SeaMonster();
    vector<Point> allowedMoves();
};

SeaMonster::SeaMonster()
{
    this->current = Point(0, 0);
}

SeaMonster::SeaMonster(const Point curr)
{
    this->current = curr;
}

vector<Point> getAllWaterInThisDirection(const Point waterPoint, vector<Point> currMoves, bool xDirection, bool isPlus)
{
    if (xDirection)
    {
        if (isPlus)
        {
            for (int currX = 0; currX < fieldSize; currX++)
            {
                if (gamefield[currX][waterPoint.y] == 2)
                {
                    currMoves.push_back(Point(currX, waterPoint.y));
                }
            }
        }
        else
        {
            for (int currX = 0; currX >= 0; currX--)
            {
                if (gamefield[currX][waterPoint.y] == 2)
                {
                    currMoves.push_back(Point(currX, waterPoint.y));
                }
            }
        }
    }
    else
    {
        if (isPlus)
        {
            for (int currY = 0; currY < fieldSize; currY++)
            {
                if (gamefield[waterPoint.x][currY] == 2)
                {
                    currMoves.push_back(Point(waterPoint.x, currY));
                }
            }
        }
        else
        {
            for (int currY = 0; currY >= 0; currY--)
            {
                if (gamefield[waterPoint.x][currY] == 2)
                {
                    currMoves.push_back(Point(waterPoint.x, currY));
                }
            }
        }
    }
    return currMoves;
}

vector<Point> SeaMonster::allowedMoves()
{
    vector<Point> moves = vector<Point>();

    if (current.x - 1 >= 0 && gamefield[current.x - 1][current.y] == 2)
    {
        Point currPoint = Point(current.x - 1, current.y);
        moves.push_back(currPoint);
        moves = getAllWaterInThisDirection(currPoint, moves, true, false);
    }
    if (current.y - 1 >= 0 && gamefield[current.x][current.y - 1] == 2)
    {
        Point currPoint = Point(current.x, current.y - 1);
        moves.push_back(currPoint);
        moves = getAllWaterInThisDirection(currPoint, moves, false, false);
    }
    if (current.y + 1 < fieldSize && gamefield[current.x][current.y + 1] == 2)
    {
        Point currPoint = Point(current.x, current.y + 1);
        moves.push_back(currPoint);
        moves = getAllWaterInThisDirection(currPoint, moves, false, true);
    }
    if (current.x + 1 < fieldSize && gamefield[current.x + 1][current.y] == 2)
    {
        Point currPoint = Point(current.x + 1, current.y);
        moves.push_back(currPoint);
        moves = getAllWaterInThisDirection(currPoint, moves, true, true);
    }

    return moves;
}

bool contains (Point p, vector<Point> points)
{
    for (int i = 0; i < points.size(); i++)
    {
        if (points[i] == p)
        {
            return true;
        }
        
    }
    return false;
}

void allMoves(vector<GamePlayer> players)
{
    for (int i = 0; i < players.size(); i++)
    {
        vector<Point> currPlauyerMoves =  players[i].allowedMoves();
        for (int j = i + 1; j < players.size(); j++)
        {
            vector<Point> nextPlayerMoves = players[j].allowedMoves();
           for (int move = 0; move < nextPlayerMoves.size(); move++)
           {
                if (contains(nextPlayerMoves[move], currPlauyerMoves))
                {
                    cout<< "(" << players[i].getPosition().x << ", " <<  players[i].getPosition().y << ")" << endl;
                }
                
           }           
            
        }        
    }    
}



int main()
{
    int gamefield[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0},
        {0, 0, 0, 7, 7, 7, 7, 0, 0, 0}};
    Knight k = Knight();
    SeaMonster s = SeaMonster();
    vector<GamePlayer> player = vector<GamePlayer>();
    player.push_back(k);
    player.push_back(s);
}