/* simplest version of calculator */
%{
#include <stdio.h>
/* The declarations here include C code to be copied to the beginning of the generated C parser, again enclosed in %{ and %} */
%}

/* declare tokens */
%token NUMBER
%token ADD SUB MUL DIV ABS
%token EOL

%%
/* Each symbol in a bison rule has a value; the value of the target symbol (the one to the left of the colon) is called $$ in the action code, and the values on the right are numbered $1, $2, and so forth, up to the number of symbols in the rule. The values of tokens are whatever was in yylval when the scanner returned the token; the values of other symbols are set in rules in the parser. In this parser, the values of the factor, term, and exp symbols are the value of the expression they represent. */
/* matches at beginning of input */
calclist: /* nothing */
 | calclist exp EOL { printf("= %d\n", $2); }
 ;
 /* EOL is end of an expression */

/* The second section contains the rules in simplified BNF. Bison uses a single colon rather than ::=, and since line boundaries are not significant, a semicolon marks the end of a rule. */
exp: factor       /*default $$ = $1*/
 | exp ADD factor { $$ = $1 + $3; }
 | exp SUB factor { $$ = $1 - $3; }
 ;

factor: term       /*default $$ = $1*/
 | factor MUL term { $$ = $1 * $3; }
 | factor DIV term { $$ = $1 / $3; }
 ;

term: NUMBER  /*default $$ = $1*/
 | ABS term   { $$ = $2 >= 0? $2 : - $2; }
;
%%
main(int argc, char **argv)
{
  yyparse();
}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
