%{
%}
%option noyywrap

digit  [0-9]
nombre {digit}+

identifier [a-zA-Z][_a-zA-Z0-9]*



newline  \n|\r|\f
%%

end {return(END);};
function {return(FUNCTION);};

[ ] {}
{nombre} {yylval.source = yytext;return(NBRE);}
{identifier} {yylval.source = yytext;return(ID);}

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
\[ {return('[');}
\] {return(']');}
= {return('=');}
{newline} {return(NEWLINE);}

%%

