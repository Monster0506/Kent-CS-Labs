// structure definitions and function prototypes for maze navigation assignment
// Mikhail Nesterenko
// 3/13/2024

#include <cstdlib>
#include <ctime>


#ifndef MAZE_HPP_
#define MAZE_HPP_

const int mazeSize = 5; // maze is mazeSize * mazeSize
const int numWalls = 8;  // number of internal walls

//
// data structures definitions
//

struct Room {
    int x;  // 1 through mazeSize
    char y; // 'a' through mazeSize
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize-1 };

// internal maze wall
struct RoomPair{
    Room one;
    Room two;
};



//
// initialization functions
//

// initializes the array of walls by placing every RoomPair to connect
// two non-existant rooms where x-coordinate is -1 and y-coordinate is '*' (a star)
// to signify that the walls are not built yet
void clearWalls(RoomPair[]);


// checks if direction dr ('u', 'd', 'l', or 'r')
// applied to Room rm keeps the mouse inside the maze
bool goodDirection(const Room &rm, const char dr);
 
// returns the room adjacent to room rm
// in the specified direction dr 
// assumes the direction is inside the maze
Room createAdjacent(const Room &rm, const char dr);


// selects a random room adjacent to Room rm
// uses goodDirection() and createAdjacent()
const Room pickAdjacent(const Room &rm); 


// selects a random wall, uses pickAdjacent()
const RoomPair pickPair(); 


// predicate returns true if the coordinates of the two rooms match
bool matchRoom(const Room&, const Room&); 

// returns true if two pairs of adjacent rooms are the same, 
// returns false otherwise, uses matchRoom()
// note that r1|r2 matches r2|r1
bool matchPair(const RoomPair&, const RoomPair&); 

// returns true if rp matches one of the wall in the array
// false otherwise
// uses matchPair()
bool checkMaze(const RoomPair[], const RoomPair &rp);


// places internal walls in random locations of the maze
void build(RoomPair[]); 

//
// display functions
//
void printRoom(const Room&); // prints the location of the room
void printPair(const RoomPair&); // prints the locations of the adjacent rooms
void printMaze(const RoomPair[]); // prints the locations of all the internal 
                                  //walls of the maze
                                  // uses printPair

//
// game functions
//

// asks the user for the direction and generates the next room
// to move to
// uses goodDirection() to valid (does not go outside external walls) and
//      createAdjacent() to generate the room for the next move
// returns {-1,*} if the user wants to quit
const Room nextMove(const Room& currentRoom); 

// note that checkMaze() is also used in the game

#endif // MAZE_HPP_
