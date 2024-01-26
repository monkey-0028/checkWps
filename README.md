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
	
	- FIXED ::: 1. for login ,, make the script to write the user_name in the ./user_data/.login
						-- if can't find the usr :: write NULL
						-- else write the usr_name
						-- CAUTION :: usr name can't be NULL
						-- 
						-- so just sytem(script addr) -- it will do all the work

* make the login-portal
	- options :: 
	first check for already login usr-- if true then direct login and call main_display func.

	1. login -- find the usr if not found then return the error message then return back to screen
	2. sign-up -- make a/c

	function : 
	1. login home page
	2. sign-up home page
	3. success screen


### NOTE ### ---
 for now, we are making application that can't be installed and called like any normal call. 
i.e for now, we don't have to worry about which file is where.. 

for later update, we can intrudce it....

for now, just assume that all the fils and folders are inside a dir... ie. checkWps;
