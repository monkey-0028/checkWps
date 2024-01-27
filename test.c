#include <curses.h>
#include <ncurses.h>
#include <stdio.h>

int main(){
		initscr();
		raw();
		noecho();
		keypad(stdscr,TRUE);
		printw("this");
		refresh();
		int m;
		m = getch();
		if(m == 10){
				printw("YES");
		}	
		refresh();
		getch();

		endwin();	
}
