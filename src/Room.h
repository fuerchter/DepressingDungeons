#ifndef ROOM
#define ROOM

#include <cstdlib>

#include <string>
using namespace std;

#include "curses.h"

class Room
{
public:
	Room(int y, int x, int rows, int cols, int monsterCount);
	int getY();
	int getX();
	int getRows();
	int getCols();
	void draw();
private:
	int y_;
	int x_;
	int rows_;
	int cols_;
};

#endif