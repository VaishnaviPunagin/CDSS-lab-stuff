%{
#include<stdio.h>
#include<stdlib.h>
int valid=1;
%}
%token num
%left '+''-'
%left '*''/'
%%
e: num {$$=$1; yylval=$$;}
|e '+' e {$$=$1+$3; yylval=$$;}
|e '-' e {$$=$1-$3; yylval=$$;}
|e '/' e {$$=$1/$3; yylval=$$;}
|e '*' e {$$=$1*$3; yylval=$$;}
;
%%

int yyerror()
{
	valid=0;
}
int main()
{
	printf("Enter an expression:\n");
	yyparse();
	if(valid)
		printf("The value of expresion is: %d\n",yylval);
	else
		printf("Invalid expression\n");
}
