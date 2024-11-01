#include "maze.hpp"
#include <iostream>

Room::Room() : x_(-1), y_('*') {}
Room::Room(int x, char y) : x_(x), y_(y) {}

void Room::print() const
{
    std::cout << "(" << x_ << ", " << y_ << ")";
}

void Room::pick()
{ // selects a random room within the maze
    x_ = std::rand() % mazeSize_ + 1;
    y_ = static_cast<char>('a' + std::rand() % mazeSize_);
}

bool Room::goodDirection(const char dr) const
{
    switch (dr)
    {
    case 'u':
        return y_ > 'a';
    case 'd':
        return y_ < 'a' + mazeSize_ - 1;
    case 'l':
        return x_ > 1;
    case 'r':
        return x_ < mazeSize_;
    default:
        return false;
    }
}

const Room Room::createAdjacent(const char dr) const
{
    int currx = x_;
    int curry = y_;
    switch (dr)
    {
    case 'u':
        curry--;
        break;
    case 'd':
        curry++;
        break;
    case 'l':
        currx--;
        break;
    case 'r':
        currx++;
        break;
    }
    const Room newRoom = Room(currx, curry);
    return newRoom;
}

const Room Room::pickAdjacent()
{
    char directions[] = {'u', 'd', 'l', 'r'};
    char dr;
    do
    {
        dr = directions[std::rand() % 4];
    } while (!goodDirection(dr));
    return createAdjacent(dr);
}

const Room Room::nextMove() const
{
    char direction;
    std::cout << "Enter move (u, d, l, r, q to quit): ";
    std::cin >> direction;

    if (direction == 'q')
    {
        return Room();
    }

    if (goodDirection(direction))
    {
        return createAdjacent(direction);
    }
    else
    {
        std::cout << "Invalid move." << std::endl;
        return Room(x_, y_);
    }
}

bool matchRoom(const Room &r1, const Room &r2)
{

    return r1.x_ == r2.x_ && r1.y_ == r2.y_;
}

void RoomPair::print() const
{
    one_.print();
    std::cout << "|";
    two_.print();
}

void RoomPair::pick()
{
    Room r1 = Room();
    r1.pick();
    Room r2 = r1.pickAdjacent();
    one_ = r1;
    two_ = r2;
}

bool matchPair(const RoomPair &p1, const RoomPair &p2)
{
    return (matchRoom(p1.one_, p2.one_) && matchRoom(p1.two_, p2.two_)) ||
           (matchRoom(p1.one_, p2.two_) && matchRoom(p1.two_, p2.one_));
}

void Maze::print() const
{
    std::cout << "Current room: ";
    currentRoom_.print();
    std::cout << std::endl;
    for (int i = 0; i < numWalls_; i++)
    {
        walls_[i].print();
    }
}
bool Maze::checkMaze(const RoomPair &rp) const
{
    for (int i = 0; i < numWalls_; ++i)
    {
        if (matchPair(walls_[i], rp))
        {
            return true;
        }
    }
    return false;
}

void Maze::build()
{
    for (int i = 0; i < numWalls_; ++i)
    {
        RoomPair rp = RoomPair();
        rp.pick();
        walls_[i] = rp;
    }
}

bool Maze::move(const Room &r1)
{
    RoomPair rp = RoomPair(r1, currentRoom_);
    if (checkMaze(rp))
        return false;
    currentRoom_ = r1;
    return true;
}
