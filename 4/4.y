%{
        #include<stdio.h>
        int valid=1;
%}
%token NUM
%left '+' '-'
%left '*' '/'
%%
        e:NUM{$$=$1;yylval=$$;}
        |e'+'e{$$=$1+$3;yylval=$$;}
        |e'-'e{$$=$1-$3;yylval=$$;}
	|e'*'e{$$=$1*$3;yylval=$$;}
	|e'/'e{if($3==0){ printf("Invalid input"); valid=0;} else $$=$1/$3;yylval=$$;}
	;
%%
int yyerror()
{
        valid=0;
}
main()
{
	printf("Enter an expression: \n");
        yyparse();
        if (valid)
        {
                printf("The value of the entered expression: %d\n",yylval);
        }
        else
        {
                printf("Invalid entered expression\n");
	}
}
