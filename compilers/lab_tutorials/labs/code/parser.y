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

exp:
  NUMBER {$$=$1;}
| NUMBER PLUS exp {$$ = $1 + $3 ;}
;

%%
int main(){
  yyparse();
}
