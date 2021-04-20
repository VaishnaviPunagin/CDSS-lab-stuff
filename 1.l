/*** Definition Section***/
%{
	/* Declare variables to track the number of characters, words, spaces and lines.*/
  	int c_count=0,l_count=0, w_count=0,b_count=0;  
%}
/***Rules Section ***/
%%
[  ]	{b_count++; c_count++;}       /* when blank is found increment blank count & character count */	
[^  \t\n]+  	{w_count++; c_count+=yyleng;}   /* when word is found increment  Word count and char  
                                                                                              count is incremented by taking the length of the word 
                                                                                              using yyleng variable */
\n		{ l_count++;}	/* when eol is encountered increment Line count */
		
.		;  		/* ignore all other characters */ 	
%%
int main(int argc, char *argv[])
{
FILE *file;
file=fopen(argv[1],"r"); /* open a file handle to a particular input file*/
yyin=file; // set lex to read from input file instead of defaulting to STDIN*/
yylex(); /* call the lexer */
printf("The Number of Characters :: %d\n",c_count);
printf("The Number of Words :: %d\n",w_count);
printf("The Number of Lines :: %d\n",l_count);
printf("The Number of Blanks :: %d\n",b_count);
return 0;
}

