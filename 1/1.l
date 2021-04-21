/*** Definition Section***/
%{
 	/* Declare variables to track the number of characters, words, spaces and lines. */
  	int ccount = 0, lcount = 0, wcount = 0, bcount = 0;
%}

/***Rules Section ***/
%%
[ ] {bcount++; ccount++;}
[^ \t\n]+ {wcount++; ccount+=yyleng;}
\n {lcount++;}
.;
%%

int main (int argc, char *argv[])
{
  	FILE *file;
  	file = fopen (argv[1], "r");	
  	yyin = file;			
  	yylex ();			
  	printf ("The Number of Characters :: %d\n", ccount);
  	printf ("The Number of Words :: %d\n", wcount);
  	printf ("The Number of Lines :: %d\n", lcount);
  	printf ("The Number of Blanks :: %d\n", bcount);
  	return 0;
}
