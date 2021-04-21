%{
	int flag =0;
%}
%%
(" "[aA][nN][dD]" ")|(" "[oO][rR]" ")|(" "[bB][uU][tT]" ") {flag=1;}
. ;
%%
int main()
{
	yylex();
	if(flag)
		printf("This is a compound sentence\n");
	else
		printf("This is not a compund sentence, It is simple\n\n");
	return 0;
}

