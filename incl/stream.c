#include "def.h"

char * signal(char * addr);

int main(){
	char * me = address("/scipts/file\n");
	printf("%s",me);
	printf("%s",address("/scripts/file\n"));
	char k[90] = me;
	system(k);
	return 0;
}

#include "address.h"

char * signal( char * addr ){
	system(addr);
	return "yes";
}
