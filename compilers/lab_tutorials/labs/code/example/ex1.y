%{
  #include <stdio.h>
 void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
 }
 int yylex();
%}

%%

expr : expr '+' term {printf(" + ");}
    | term
    ;

term : term '*' fact {printf(" * ");}
    | fact
    ;

fact : "(" expr ")"
    | '0' {printf("0");}
    | '1' {printf("1");}
    | '2' {printf("2");}
    | '3' {printf("3");}
    | '4' {printf("4");}
    | '5' {printf("5");}
    | '6' {printf("6");}
    | '7' {printf("7");}
    | '8' {printf("8");}
    | '9' {printf("9");}

%%
/* int main(){
  yyparse();
} */
