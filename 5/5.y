%{
#include<stdlib.h>
#include<stdio.h>
int valid = 1;
%}
%token L D
%%
var: E {return valid; exit(0);}
E: E L ;
|E D;
|L ;
;
%%
yyerror()
{
	valid=0;
	printf("Invalid variable\n");
}
int main(){
	printf("Type the variable \n");
	yyparse();
	if(valid)
		printf("Valid variable \n");
}

