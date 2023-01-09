%{
  #include<stdio.h>
  #include "lex.yy.c"
  int lineno=0;
  yyerror(char *s) { printf("%s", s); }
%}

%token NEWLINE INTEGER

%%
lines: /* empty */
| lines NEWLINE
| lines line NEWLINE {printf("%d) %d\n", lineno, $2);}
| error NEWLINE { printf(" in line %d!\nReenter: ", lineno);
yyerrok; }
;
line: INTEGER {$$ = $1;}
// If there is a single item on the right, this assignment is automatic
;
%%
main() {
yyparse();
return 0;
}
