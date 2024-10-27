// Mikhail Nesterenko
// tests maze function implementation
// 3/25/2023

#include "maze.hpp"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

    // srand(time(nullptr)); // random seed
    srand(1); // fixed seed

    //
    // first part: checking Room functions
    //

    Room myRoom; // create a room
    myRoom.x = 2;
    myRoom.y = 'b';

    // print Room
    cout << "myRoom, fixed location: "; printRoom(myRoom); cout << endl;

    // make sure to implement goodDirection() and createAdjacent() first
    Room newMoveRoom = nextMove(myRoom); // asks user for new adjacent room
    cout << "user selected adjacent room: "; printRoom(newMoveRoom); cout << endl;
   
    Room randomRoom = pickAdjacent(myRoom);
    cout << "randomly selected adjacent room: "; printRoom(randomRoom); cout << endl;

    
    if(matchRoom(randomRoom, newMoveRoom))
        cout << "randomRoom is the same as newMoveRoom" << endl;

    //
    // second part: checking wall functions
    //
    
    // select a fixed wall
    RoomPair myWall = { {2,'b'}, {2,'c'} };

    // print wall 
    cout << "myWall, fixed location: "; printPair(myWall); cout << endl;

    // select and print a random wall
    myWall = pickPair();
    cout << "myWall, random location: "; printPair(myWall); cout << endl;

    RoomPair myMove; myMove.one = myRoom; myMove.two = newMoveRoom;

    if (matchPair(myWall, myMove))
        cout << "there is a wall between these two rooms" << endl;
    else
       cout << "there is no wall between these two rooms" << endl;
    
    //
    // third part: check maze functions
    //
   
    RoomPair myMaze[numWalls]; // array of walls in the maze

    clearWalls(myMaze); //assigning -1 and '*' to all rooms of the walls 

    // printing walls of the maze
    cout << "uninitialized maze walls: ";  printMaze(myMaze); cout << endl;

    if (checkMaze(myMaze, myMove))
       cout << "checkMaze returned true" << endl;
    else
       cout << "checkMaze returned false" << endl;

    build(myMaze); // placing walls at random locations in the maze
    cout << "built maze: ";  printMaze(myMaze); cout << endl;
    
}
