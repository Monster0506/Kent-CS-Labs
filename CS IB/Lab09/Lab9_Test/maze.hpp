// class definitions for maze navigation assignment
// Mikhail Nesterenko
// 3/20/2024

#include <cstdlib>
#include <ctime>


#ifndef MAZE_HPP_
#define MAZE_HPP_

// room coordinates
class Room {
public:
    Room(); // void constructor, assigns -1 to X coord, and * to Y coord
            // use initializer list for implementation
    Room(int x, char y);
    void pick(); // selects a random room within the maze

    // selects a random adjacent room
    // uses goodDirection() and createAdjacent()
    const Room pickAdjacent(); 

    // asks the user for the room to move adjacent to this room
    // returns {-1,*} if the user wants to quit
    // uses goodDirection() and createAdjacent()
    const Room nextMove() const; 

    void print() const;   // prints room coordinates in format "a1"

    // make this room the start room
    void makeStartRoom() { x_ = 1; y_ = 'a'; }

    // make this room - the cheese room
    void makeCheeseRoom() { x_ = mazeSize_, y_ = 'a' + mazeSize_ - 1; };

    // predicate returns true if the coordinates of the two rooms match
    friend bool matchRoom(const Room&, const Room&);
private:
    // checks if this direction keeps the mouse inside the maze
    bool goodDirection(const char) const;
 
    // returns the room adjacent to this room in the specified direction
    // assumes the direction is inside the maze
    const Room createAdjacent(const char) const;

    static const int mazeSize_ = 5; // maze is mazeSize * mazeSize
    int x_;  // 1 through mazeSize
    char y_; // 'a' through mazeSize
};


// internal wall or next move
class RoomPair {
public:
    RoomPair() {} // void constructor implicitly invokes void constructors on member variables
    // makes a roomPair out of two rooms
    RoomPair(const Room& one, const Room& two):one_(one), two_(two) {}

    void pick(); //selects a random wall, uses Room::pickAdjacent()

    void print() const; // prints the locations of the two rooms in format a1|b1
                       // uses Room::print()

    // returns true if two pairs of adjacent rooms are the same,
    // returns false otherwise, uses matchRoom() note that r1|r2 matches r2|r1
    friend bool matchPair(const RoomPair&, const RoomPair&);

private:
    Room one_;
    Room two_;
};

class Maze {
public:
    Maze() {} // places every wall between two rooms where x-coordinate is -1
              // and y-coordinate is '*' (a star) to signify that
              // the wall is not built yet

    // prints the locations of all the internal walls of the maze
    // and current mouse location
    void print() const; 

    // places internal walls in random locations of the maze
    // all walls are different
    void build(); 

    // places current mouse location in startRoom_;
    void start() { currentRoom_.makeStartRoom(); }

    // takes the room to move the mouse to
    // moves the mouse there and returns true if no walls (move is possible)
    // does not move the mouse and returns false if wall
    bool move(const Room&);
     
    // returns current mouse location
    const Room getCurrentRoom() { return currentRoom_; }

private:
    // returns true if RoomPair matches one of the walls in the maze
    bool checkMaze(const RoomPair&) const; 

    Room currentRoom_; // current mouse Location

    static const int numWalls_ = 8;  // number of internal walls
    RoomPair walls_[numWalls_]; // array of internal maze walls
};

#endif // MAZE_HPP_