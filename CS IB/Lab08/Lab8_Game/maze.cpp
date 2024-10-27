#include "maze.hpp"
#include <iostream>

void clearWalls(RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        walls[i].one = { -1, '*' };
        walls[i].two = { -1, '*' };
    }
}

bool goodDirection(const Room &rm, const char dr) {
    switch (dr) {
        case 'u': return rm.y > 'a';
        case 'd': return rm.y < 'a' + mazeSize - 1;
        case 'l': return rm.x > 1;
        case 'r': return rm.x < mazeSize;
        default: return false;
    }
}

Room createAdjacent(const Room &rm, const char dr) {
    Room adjacentRoom = rm;
    switch (dr) {
        case 'u': adjacentRoom.y--; break;
        case 'd': adjacentRoom.y++; break;
        case 'l': adjacentRoom.x--; break;
        case 'r': adjacentRoom.x++; break;
    }
    return adjacentRoom;
}

const Room pickAdjacent(const Room &rm) {
    char directions[] = { 'u', 'd', 'l', 'r' };
    char dr;
    do {
        dr = directions[std::rand() % 4]; 
    } while (!goodDirection(rm, dr));    
    return createAdjacent(rm, dr);
}

const RoomPair pickPair() {
    RoomPair pair;
    Room randomRoom = { std::rand() % mazeSize + 1, static_cast<char>('a' + std::rand() % mazeSize) };
    pair.one = randomRoom;
    pair.two = pickAdjacent(randomRoom);
    return pair;
}

bool matchRoom(const Room &r1, const Room &r2) {
    return r1.x == r2.x && r1.y == r2.y;
}

bool matchPair(const RoomPair &p1, const RoomPair &p2) {
    return (matchRoom(p1.one, p2.one) && matchRoom(p1.two, p2.two)) ||
           (matchRoom(p1.one, p2.two) && matchRoom(p1.two, p2.one));
}

bool checkMaze(const RoomPair walls[], const RoomPair &rp) {
    for (int i = 0; i < numWalls; ++i) {
        if (matchPair(walls[i], rp)) {
            return true;
        }
    }
    return false;
}

void build(RoomPair walls[]) {
    clearWalls(walls);
    for (int i = 0; i < numWalls; ++i) {
        RoomPair rp = pickPair();
        walls[i] = rp;
    }
}

void printRoom(const Room &rm) {
    std::cout << "(" << rm.x << ", " << rm.y << ")";
}

void printPair(const RoomPair &rp) {
    printRoom(rp.one);
    std::cout << " | ";
    printRoom(rp.two);
    std::cout << std::endl;
}

void printMaze(const RoomPair walls[]) {
    for (int i = 0; i < numWalls; ++i) {
        printPair(walls[i]);
    }
}

const Room nextMove(const Room &currentRoom) {
    char direction;
    std::cout << "Enter move (u, d, l, r, q to quit): ";
    std::cin >> direction;

    if (direction == 'q') {
        return { -1, '*' }; 
    }

    if (goodDirection(currentRoom, direction)) {
        return createAdjacent(currentRoom, direction);
    } else {
        std::cout << "Invalid move." << std::endl;
        return currentRoom;
    }
}
