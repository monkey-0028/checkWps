# checkWps

algo used: : solve small problem then link each file

* make file system
	- make address changeable so that you can easily make changes after project is done.
	- make an init-script that checks all the files and folders. if can't find then created one.

FILE and FOLDERS : 
main.c
./user_data -- login user data and .login file to check status of login.
./incl -- contain all the header files for main.c
./scripts -- contain bash scripts
./signals -- THis dir will be used as communication channel between c-files and scripts

* make sytem to communicate script file and c file easily and effeciently.
	- make func that takes filename to exeute and return char *

