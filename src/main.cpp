#include <ctime>
#include <cstdlib>

#include <string>
using namespace std;

#include "curses.h"

#include "World.h"

int main()
{
	initscr();
	
	noecho(); //pressing a key will not result in printing it
	raw();
	keypad(stdscr, true); //arrow keys can be used
	nodelay(stdscr, true); //getch returns err instead of blocking
	
	int rows=50;
	int cols=50;
	resize_term(rows, cols);
	
	clock_t curTime=clock();
	clock_t prevTime=curTime;
	
	srand(time(NULL));
	
	World world(1, 5, 16, 20, 0, 2, rows, cols);
	
	int c;
	while(true)
	{
		//clear();
		
		c = getch();
		if(c==27)
		{
			break;
		}
		
		prevTime=curTime;
		curTime=clock();
		float deltaTime=(float)(curTime-prevTime)/CLOCKS_PER_SEC;
		
		//UPDATE
		
		//UPDATE
		
		//DRAW
		//mvprintw(9, 0, "Keycode: %d, and the character: %c", c, c);
		world.draw();
		//DRAW
		
		//refresh();
	}
	endwin();
}