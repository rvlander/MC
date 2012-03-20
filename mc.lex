%{
%}
%option noyywrap

digit  [0-9]
nombre {digit}+

identifier [a-zA-Z][_a-zA-Z0-9]*



newline  \n|\r|\f
%%

[ ] {}
{nombre} {yylval.source = new string(yytext);return(NBRE);}
{identifier} {yylval.source = new string(yytext);return(ID);}

- {return('-');}
\+ {return('+');}
\* {return('*');}
\.\* {return(TIMES);}
\/ {return('/');}
\.\/ {return(DIVIDE);}
\( {return('(');}
\) {return(')');}
\^ {return('^');}
\.\^ {return(POWER);}
: {return(':');}
; {return(';');}
, {return(',');}
{newline} {return(NEWLINE);}

%%

