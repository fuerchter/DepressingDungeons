#ifndef WORLD
#define WORLD

#include <cstdlib>

#include <vector>
#include <string>
using namespace std;

#include "curses.h"

#include "Room.h"

class World
{
public:
	World(int minRooms, int maxRooms, int minRoomArea, int maxRoomArea, int minMonstersPerRoom, int maxMonstersPerRoom, int rows, int cols);
	void draw();
private:
	bool roomOverlaps(int y, int x, int rows, int cols);
	vector<Room> rooms_;
};

#endif