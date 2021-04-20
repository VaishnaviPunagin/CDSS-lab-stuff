%{
	int s=0,m=0;
%}
%%
"/*"[a=zA-Z0-9?!''\t\n]*"*/"       { m++;}
"//".* {s++;}
%%
int main(int argc,char *argv[])
{
FILE *fin, *fout;
fin=fopen(argv[1],"r");
fout=fopen(argv[2],"w");
yyin=fin;
yyout=fout;
yylex();
printf("The number of comments in this file are::\nSingle line :: %d\nMultiple lines :: %d\n\n",s,m);
return 0;
}

