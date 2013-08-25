#include "Room.h"

Room::Room(int y, int x, int rows, int cols, int monsterCount):
y_(y), x_(x), rows_(rows), cols_(cols)
{
	//GENERATE MONSTERS
}

int Room::getY()
{
	return y_;
}

int Room::getX()
{
	return x_;
}

int Room::getRows()
{
	return rows_;
}

int Room::getCols()
{
	return cols_;
}

void Room::draw()
{
	for(int y=y_; y<=y_+rows_; y++)
	{
		string line;
		if(y==y_ || y==y_+rows_)
		{
			for(int x=x_; x<=x_+cols_; x++)
			{
				line+="-";
			}
		}
		else
		{
			for(int x=x_; x<=x_+cols_; x++)
			{
				if(x==x_ || x==x_+cols_)
				{
					line+="|";
				}
				else
				{
					line+=".";
				}
			}
		}
		mvprintw(y, x_, line.c_str());
	}
}