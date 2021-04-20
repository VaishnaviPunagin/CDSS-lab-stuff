%{
#include<stdio.h>
int f = 1;
%}

%%
(" "[aA][nN][dD]" ")|(" "[oO][rR]" ")|(" "[bB][uU][tT]" ") {f = 0;}
. ;
%%

signed main(){
	//printf("Start of exec");
	yylex();
	//printf("%d",f);
	if(f==0) 
		printf("Compund sentence\n");
	else 
		printf("Simple Sentence\n");
	//return 0;
}

