#include <ctime>

#include <string>
using namespace std;

#include "curses.h"

int main()
{
	initscr();
	
	noecho(); //pressing a key will not result in printing it
	raw();
	keypad(stdscr, true); //arrow keys can be used
	nodelay(stdscr, true); //getch returns err instead of blocking
	
	resize_term(10, 81);
	int x, y;
	getmaxyx(stdscr, y, x);
	
	clock_t curTime=clock();
	clock_t prevTime=curTime;
	
	int c;
	while(true)
	{
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
		mvprintw(9, 0, "Keycode: %d, and the character: %c", c, c);
		//DRAW
		
		refresh();
	}
	endwin();
}