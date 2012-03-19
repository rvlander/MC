%{
%}
%option noyywrap

digit  [0-9]
nombre {digit}+
newline  \n|\r|\f
%%

[ ] {}
{nombre} {yylval.source = new string(yytext);return(NBRE);}

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

; {return(';');}
{newline} {return(NEWLINE);}

%%

