%{
  /* definition */
  #include<stdio.h>
  void yyerror(const char* msg) {
      fprintf(stderr, "%s\n", msg);
   }
   int yylex();
%}
/* Union tells that the input can be number or character_symbol */
%union{
  int num;
  char sym;
}

%token EOL
%token<num> NUMBER
%token PLUS
%token MINUS
%token DIVIDE
%token MULTIPLY
%type<num> exp

/* rules are here */
%%
input:
| line input
;

line:
  exp EOL {printf("%d\n", $1);}
| EOL
;
/* Extra Steps */
/* exp:
   */
/* exp has been replaced by NUMBER in RHS */
/* Explore when the expression will be replaced in LHS instead */
exp:
  NUMBER {$$=$1;}
| MINUS exp {$$ = -$1;}
| exp PLUS NUMBER {$$ = $1 + $3 ;}
/* | exp MINUS NUMBER {$$ = $1 - $3;} /* Comment this line  */
/* Introduce new hack write different expression for MINUS */
| exp MULTIPLY NUMBER {$$ = $1 * $3;}
| exp DIVIDE NUMBER {$$ = $1 / $3;}
;

%%
int main(){
  yyparse();
}
