%{
int i=0;
%}
%%
[a-zA-Z][a-zA-Z0-9]* {i++;}
\n ;
. ;
%%
int yywrap()
{
        return 1;
}
main(int argc, char* argv[])
{
        FILE *file;
        file = fopen(argv[1],"r");
        yyin = file;
        yylex();
        printf("Number of identifiers are:: %d\n", i);
}
