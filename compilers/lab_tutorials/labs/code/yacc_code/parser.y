/*anbn_0.y */
%token A B
%%
start: anbn '\n' {printf(" is in anbn_0\n");

return 0;}

anbn: empty
| A B
| A anbn B
| A anbn
| anbn B
;
empty: ;
%%
#include "lex.yy.c"
yyerror(char *s) { printf("%s, it is not in anbn_0\n", s); }
main() {
return yyparse();
}
