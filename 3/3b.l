%{
#include<stdio.h>
int sf=0;int pf=0;
%}
%%
"scanf" {sf++; fprintf(yyout, "readf");}
"printf" {pf++; fprintf(yyout, "writef");}
%%
int main(int argc,char *argv[]){
	yyin=fopen("one.c","r");
	yyout=fopen("copyOfOne.c","w");
	yylex();
	printf("Number of scanf statements in the file :: %d \nNumber of printf statements in the file ::%d\n",sf,pf);
	return 0;
}
