/* actions.l */
%%
a return A;
b return B;
\n return NL;
.;
%%
int yywrap() { return 1; }
