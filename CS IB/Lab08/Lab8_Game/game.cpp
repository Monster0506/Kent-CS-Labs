#include "maze.hpp"
#include <iostream>

bool has_won(Room user_room, Room end_room);

int main()
{
    RoomPair myMaze[numWalls];
    clearWalls(myMaze);
    build(myMaze);
    Room myRoom = startRoom;
    // printMaze(myMaze);
    while (!matchRoom(myRoom, cheeseRoom) && !matchRoom(myRoom, {-1, '*'}))
    {
        printRoom(myRoom);
        std::cout << std::endl;
        Room newMoveRoom = nextMove(myRoom);
        RoomPair myMove;
        myMove.one = myRoom;
        myMove.two = newMoveRoom;
        if (checkMaze(myMaze, myMove))
        {
            std::cout << "wall" << std::endl;
        }
        else
        {
            myRoom = newMoveRoom;
        }
    }

    std::cout << "Thanks for playing" << std::endl;
    if (matchRoom(myRoom, cheeseRoom))
    {
        std::cout << "You Win!" << std::endl;
    }

    return 0;
}
