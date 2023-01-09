%{
#include <stdio.h>
%}

%token A B NL

%%
s:
  {printf("1");}
  a
  {printf("2");}
  b
  {printf("3");}
  NL
  {return 0;}
  ;
a:
  {printf("4");}
  A
  {printf("5");}
  ;
b:
  {printf("6");}
  B
  {printf("7");}
  ;
%%
#include "lex.yy.c" int yyerror(char *s) {
printf ("%s\n", s); }
int main(void){ yyparse(); }
