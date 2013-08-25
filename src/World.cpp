#include "World.h"

World::World(int minRooms, int maxRooms, int minRoomArea, int maxRoomArea, int minMonstersPerRoom, int maxMonstersPerRoom, int rows, int cols)
{
	int roomCount=rand()%(maxRooms-minRooms+1)+minRooms;
	for(int i=1; i<=roomCount; i++)
	{
	
		int roomArea=rand()%(maxRoomArea-minRoomArea+1)+minRoomArea;

		//Generating exact measures from area
		int roomRowDivisor=roomArea/4-4; //4=2 wall and 2 floor tiles
		//Making roomRows minimum 4, maximum roomArea/4 (so that roomCols can be at least 4 as well)
		int roomRows=4;
		if(roomRowDivisor!=0)
		{
			roomRows+=rand()%roomRowDivisor;
		}
		int roomCols=roomArea/roomRows;
		
		/*clear();
		printw((to_string(roomRows)+ " " +to_string(roomCols)+ " " +to_string(roomArea)).c_str());
		refresh();*/
		
		int monsterCount=rand()%(maxMonstersPerRoom-minMonstersPerRoom+1)+minMonstersPerRoom;
		
		int y;
		int x;
		do
		{
			y=rand()%(rows-roomRows);
			x=rand()%(cols-roomCols);
			roomOverlaps(y, x, roomRows, roomCols);
		}
		while(roomOverlaps(y, x, roomRows, roomCols));
		
		rooms_.push_back(Room(y, x, roomRows, roomCols, monsterCount));
	}
	//clear();
	//printw("DONE");
}

void World::draw()
{
	for(auto room : rooms_)
	{
		room.draw();
	}
}

bool World::roomOverlaps(int y, int x, int rows, int cols)
{
	for(auto room : rooms_)
	{
		clear();
		refresh();
		if(y<=room.getY()+room.getRows() &&
		y+rows>=room.getY() &&
		x<=room.getX()+room.getCols() &&
		x+cols>=room.getX())
		{
			//printw((to_string(y)+ " " +to_string(x)+ " " +to_string(rows)+ " " +to_string(cols)+ " - " +to_string(room.getY())+ " " +to_string(room.getX())+ " " +to_string(room.getRows())+ " " +to_string(room.getCols())+ " OVERLAP").c_str());
			return true;
		}
	}
	return false;
}