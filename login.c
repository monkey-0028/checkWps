#include "./incl/def.h"
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>

#define clearr(len) \
		for(int i=0;i<len;i++){\
				printw("%c",' ');\
		}


// usrname len -- 60
char temp_user[usr_name_len];

void login_init(); // checks if already exit any usrname;
void r_usr(); // set defalut val of temp_user;
int login_portal(); // This concludes the whole screen of login 
					// it internally calls the other login fucntion like sign-up
					// it modify the temp_user
					// return 0 -- for success 
					// return 1 -- for failure


int main(){
		initscr(); 
		start_color();
		raw();
		noecho();
		keypad(stdscr, TRUE);
		curs_set(0);
		//
		init_pair(2, COLOR_WHITE, COLOR_BLACK);
		wbkgd(stdscr, COLOR_PAIR(2)); // changed background color of stdscr to black

		login_portal();
		//
		curs_set(1);
		endwin();
		return 0;
}

void login_init(){
		FILE *file;
		file = fopen("./user_data/.login","r");
		if(file == NULL){
				printf("\nCan't open ./user_data/.login\n");
				fclose(file);
		}
		else{
				char ch;
				int ptr=0;
				ch = fgetc(file);
				while(ch  != EOF){
						temp_user[ptr]= ch;
						ch = fgetc(file);
						ptr++;
				}
		}
}

void r_usr(){
		int ptr=0;
		while(temp_user[ptr] != '\0'){
				temp_user[ptr] = '\0';
				ptr++;
		}
}

int login_portal(){
		init_pair(1,COLOR_RED,COLOR_BLACK);
		int input='1';
		
		//f1 to exit
		attron(COLOR_PAIR(1));
		attron(A_BOLD);
		printw("exit <f1>");
		attroff(COLOR_PAIR(1));
		attroff(A_BOLD);
		
		int option=0; // defalut selected option
		
		char *option1 = "LOGIN";
		char *option2 = "SIGN-UP";

		char *Selected_option1 = "L O G I N";
		char *Selected_option2 = "S I G N - U P";
		
		int x = getmaxx(stdscr);

		while(input != KEY_F(1)){
				if(option == 0){
						attron(COLOR_PAIR(1));
						move(2,(x/2)-strlen(Selected_option1));
						printw("%s",Selected_option1);
						attroff(COLOR_PAIR(1));
						printw(" |");

						move(3,(x/2)-strlen(Selected_option2));
						clearr(strlen(Selected_option2));

						move(3,(x/2)-strlen(option2));
						printw("%s |",option2);

						refresh();
				}
				else{
						move(2,(x/2)-strlen(Selected_option1));
						clearr(strlen(Selected_option1));

						move(2,(x/2)-strlen(option1));
						printw("%s |",option1);
						

						attron(COLOR_PAIR(1));
						move(3,(x/2)-strlen(Selected_option2));
						printw("%s",Selected_option2);
						attroff(COLOR_PAIR(1));
						
						printw(" |");

						refresh();

				}
				

				input = getch();
				if(input == KEY_DOWN || input == KEY_UP){
						option = (option+1)%2;
				}

		}
		return 0;
}









