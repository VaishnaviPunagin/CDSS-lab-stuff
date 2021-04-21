%{
#include<stdio.h>
int id=0;
%}
digit[0-9]
letter[a-zA-Z_]
%%
{letter}({letter}|{digit})* {id++;}
%%
int yywrap()
{ 
  return 1;
}
int main()
{
yyin=fopen("a.txt1","r");
yylex();
printf("number of identifiers are %d\n",id);
return 0;
}
