%{
    #include "ex1.tab.h"
%}

%%

[0-9]   {return (yytext[0]);}
[+*()]  {return (yytext[0]);}
\n      {return (0);}
.       {}

%%
