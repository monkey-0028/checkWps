#include "./incl/def.h"	
#include <curses.h>

int main(){

		initscr();
		start_color();
		raw();
		noecho();
		keypad(stdscr,TRUE);
		curs_set(0);
		//
		init_pair(2,COLOR_WHITE,COLOR_BLACK); //black color for stdscr
		wbkgd(stdscr,COLOR_PAIR(2));
		init_pair(1,COLOR_RED,COLOR_BLACK);
		//--start here
		login_portal();

		//
		curs_set(1);
		endwin();
		return 0;

		
}

#include "./incl/login.h"
