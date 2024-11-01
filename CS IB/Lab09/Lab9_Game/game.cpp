#include "maze.hpp"
#include <iostream>

int main()
{
    Maze maze = Maze();
    maze.start();
    maze.build();
    maze.print();
    std::cout<<std::endl;
    Room cheeseRoom = Room();
    cheeseRoom.makeCheeseRoom();
    Room quitRoom = Room();
    while (!matchRoom(maze.getCurrentRoom(), cheeseRoom) && !matchRoom(maze.getCurrentRoom(), quitRoom))
    {
        Room newRoom = maze.getCurrentRoom().nextMove();
        if (!maze.move(newRoom))
        {
            std::cout << "wall" << std::endl;
        }
        maze.getCurrentRoom().print();
        std::cout << std::endl;
    }
    if (matchRoom(maze.getCurrentRoom(), cheeseRoom))
        std::cout << "You Win!" << std::endl;
    else
        std::cout << "You Quit!" << std::endl;
    return 0;
}
