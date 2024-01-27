#include "./incl/def.h"
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>

#define clearr(len) \
		for(int i=0;i<len;i++){\
				printw("%c",' ');\
		}

#define warning(string) \
		attron(COLOR_PAIR(1));\
        attron(A_BOLD);\
        printw(string);\
        attroff(COLOR_PAIR(1));\
        attroff(A_BOLD);



// usrname len -- 60
char temp_user[usr_name_len];

void login_init();
void r_usr();
void login_portal(); 
void login(); 


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

void login_portal(){
		init_pair(1,COLOR_RED,COLOR_BLACK);
		int input='1';
		warning("exit <f1>")
		
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
				if(input == 10 || input == KEY_ENTER){ //here 10 means Enter
						login();
				}
				if(input == KEY_DOWN || input == KEY_UP){
						option = (option+1)%2;
				}

}
}



void login(){
		char *display_username = "Username : ";
		char *display_password = "Password : ";
		int ch;
		int len=0;
		int x = getmaxx(stdscr);
		
		char f_username[usr_name_len]={'\0'};

		clear();
		warning("exit <f1>")
		
		move(2,(x/2)-strlen(display_username)-20);
		printw("%s",display_username);

		while(ch!=10){
				ch = getch();
				if(ch == KEY_END || ch == KEY_HOME || ch == KEY_F(2) || ch == KEY_F(3) ||ch ==  KEY_F(4)){
						len+=0;
				}
				else if(ch == KEY_F(5) || ch == KEY_F(5) || ch == KEY_F(6)  || ch == KEY_F(7) || ch == KEY_F(8)){
						len+=0;
				}
				else if(ch==KEY_F(9) || ch == KEY_F(10) || ch == KEY_F(11) || ch == KEY_F(12)){
						len+=0;
				}
				else if(ch == KEY_ENTER){
						break;
				}
				else if(ch == KEY_BACKSPACE){
						if(len != 0){
								if(len==31){
										move(1,x/2);
										clearr(strlen("Length of username can't exceed 30"));
								}
								len--;
								f_username[len]='\0';
								move(2,(x/2)-strlen(display_username)-20);
								clearr(strlen(display_username)+len+1);

								move(2,(x/2-strlen(display_username)-20));
								printw("%s%s",display_username,f_username);
						}
				}
				else{
						if(len > usr_name_len){
								move(1,x/2);
								warning("Length of username can't exceed 30");
						}
						else{
								printw("%c",ch);
								f_username[len]=ch;
								len++;
						}		
				}
						

		}
		move(5,5);
		printw("%s",f_username);
		refresh();
		getch();
		clear();
		refresh();
		

}















