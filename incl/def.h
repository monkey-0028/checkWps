#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include <stdbool.h>



//definations

#define usr_name_len 30

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

#define setNULL \
		temp_user[0]='N';\
		temp_user[1]='U';\
		temp_user[2]='L';\
		temp_user[3]='L';


//
//
//global variable
// usrname len -- 60
char temp_user[usr_name_len]={'\0'};

//
//function declarations
void login_init();
void r_usr();
void login_portal(); 
void login(); 
char read_signal();

