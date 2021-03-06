%{

bool verb = false;

void verbose(string token){
	if(verb){	
		cout << token;
	}
	return;
}


%}
%option noyywrap
%s QuoteSC


digit  [0-9]
virgule \.{digit}+
nombre {digit}+{virgule}?
identifier [a-zA-Z][_a-zA-Z0-9]*


newline  \n|\r|\f
%%

return {verbose("RETURN");return(RETURN);};
for {verbose("FOR");return(FOR);};
end/\ *{newline} {verbose("END");return(END);};
end {verbose("EXEND");return(EXEND);};
if {verbose("IF");return(IF);};
elseif {verbose("ELSEIF");return(ELSEIF);};
else {verbose("ELSE");return(ELSE);};
while {verbose("WHILE");return(WHILE);};
function {verbose("FUNCTION");return(FUNCTION);};


\  {BEGIN(INITIAL);
if(in_matrix>0){
	verbose("MSPACE");return(MSPACE);
}
}
\%[^\n\r\f]* {BEGIN(INITIAL);}
{nombre} {BEGIN(QuoteSC);verbose("NBRE");yylval.source = yytext;return(NBRE);}
{identifier} {BEGIN(QuoteSC);verbose("ID");

yylval.source = yytext;
if(yylval.source.compare("class")==0){
yylval.source += "_reserved";
}

return(ID);}

\[/[^=;\n\t\f]*]\ *=[^=] {BEGIN(INITIAL);verbose("LD");return(LD);}
\]/\ *=[^=] {BEGIN(INITIAL);verbose("RD");return(RD);}


- {BEGIN(INITIAL);verbose("-");return('-');}
\+ {BEGIN(INITIAL);verbose("+");return('+');}
\* {BEGIN(INITIAL);verbose("*");return('*');}
\.\* {BEGIN(INITIAL);verbose("TIMES");return(TIMES);}
\/ {BEGIN(INITIAL);verbose("/");return('/');}
\\ {BEGIN(INITIAL);verbose("\\");return('\\');}
\.\/ {BEGIN(INITIAL);verbose("DEVIDE");return(DIVIDE);}
\.\\ {BEGIN(INITIAL);verbose("LDEVIDE");return(LDIVIDE);}
\( {BEGIN(INITIAL);verbose("(");return('(');}
\) {BEGIN(INITIAL);verbose(")");return(')');}
\} {BEGIN(INITIAL);verbose("}");return('}');}
\{ {BEGIN(INITIAL);verbose("{");return('{');}
\^ {BEGIN(INITIAL);verbose("^");return('^');}
\.\^ {BEGIN(INITIAL);verbose("POWER");return(POWER);}
: {BEGIN(INITIAL);verbose(":");return(':');}
;\ |; {BEGIN(INITIAL);verbose(";");return(';');}
,\ |, {BEGIN(INITIAL);verbose(",");return(',');}
\[ {BEGIN(INITIAL);verbose("[");return('[');}
\] {BEGIN(QuoteSC);verbose("]");return(']');}
== {BEGIN(INITIAL);verbose("EQ");return(EQ);}
~= {BEGIN(INITIAL);verbose("NE");return(NE);}
\< {BEGIN(INITIAL);verbose("<");return('<');}
\> {BEGIN(INITIAL);verbose(">");return('>');}
\<= {BEGIN(INITIAL);verbose("LE");return(LE);}
\>= {BEGIN(INITIAL);verbose("GE");return(GE);}
\| {BEGIN(INITIAL);verbose("|");return('|');}
& {BEGIN(INITIAL);verbose("&");return('&');}
\|\| {BEGIN(INITIAL);verbose("LOR");return(LOR);}
&& {BEGIN(INITIAL);verbose("LAND");return(LAND);}
= {BEGIN(INITIAL);verbose("=");return('=');}
{newline} {BEGIN(INITIAL);
        no_line++;
ostringstream oss;
         oss <<"NEWLINE\n" <<no_line <<"> ";
         
        verbose(oss.str());return(NEWLINE);}
\.' {BEGIN(QuoteSC);verbose("TRANSPOSE");return(TRANSPOSE);}
' {BEGIN(QuoteSC);verbose("CTRANSPOSE");return(CTRANSPOSE);}
~ {BEGIN(INITIAL);verbose("~");return('~');}
@ {BEGIN(INITIAL);verbose("@");return('@');}

<INITIAL>'[^'\r\f\n]*' { yylval.source = yytext;verbose("TEXT"); return(TEXT);};

%%

