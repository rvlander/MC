%{

#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

int yylex(void);
void yyerror (char const *s);




%}

%union{
  string *source;	
  //for colon expression;
  string *start;
  string *stride;
  string *stop;
}

%token NBRE
%token ID
%token NEWLINE
%token TIMES
%token DIVIDE
%token POWER

%left ':'
%left '+' '-'
%left '*' '/' TIMES DIVIDE 
%right MOINSUNAIRE
%left '^' POWER
%%

input : instrs {cout << endl<< *$<source>1 << endl;YYACCEPT;}
;

instrs : instr instrs {$<source>$ = new string(*$<source>1+*$<source>2);}
	|             {$<source>$ = new string("");}
;

instr : instr_in ';' { $<source>$ = new string(*$<source>1);}
      | instr_in NEWLINE{ $<source>$ = new string(*$<source>1);}
;

instr_in : expr { $<source>$ = new string(*$<source>1+";\n");}
 	 | {$<source>$ = new string("");}
;
       

expr : expr '+' expr {$<source>$ = new string("add("+*$<source>1+","+*$<source>3+")");}
     | expr '-' expr {$<source>$ = new string("minus("+*$<source>1+","+*$<source>3+")");}
     | expr '*' expr {$<source>$ = new string("mtimes("+*$<source>1+","+*$<source>3+")");}
     | expr TIMES expr {$<source>$ = new string("times("+*$<source>1+","+*$<source>3+")");}
     | expr '/' expr {$<source>$ = new string("mdivide("+*$<source>1+","+*$<source>3+")");}
     | expr DIVIDE expr {$<source>$ = new string("divide("+*$<source>1+","+*$<source>3+")");}
     | expr '^' expr {$<source>$ = new string("mpow("+*$<source>1+","+*$<source>3+")");}
     | expr POWER expr {$<source>$ = new string("pow("+*$<source>1+","+*$<source>3+")");}
     | '(' expr ')' {$<source>$ = new string("("+*$<source>2+")");}
     | '-' expr %prec MOINSUNAIRE { $<source>$ = new string("muminus("+*$<source>2+")");}
     | colon_expr { 
$<source>$ = new string("colon("+*$<start>1
  +",1,"+*$<stop>1+")");}
     | colon_expr1 {$<source>$ = new string("colon("+*$<start>1
  +","+*$<stride>1+","+*$<stop>1+")");}				     
     | NBRE { $<source>$ = new string(*$<source>1);}
     | ID { $<source>$ = new string(*$<source>1);}     
;



colon_expr :   expr ':' expr { 
  cout << *$<source>1 << ":" << *$<source>3 << endl; 
  $<start>$ = new string(*$<source>1);
	cout << *$<start>$ << endl;
  $<stride>$ = new string(*$<source>3);
	cout << *$<start>$ << endl;
  $<stop>$ = new string(*$<source>3);
cout << *$<start>$ << ":" << *$<stop>$ << endl;
}
;

colon_expr1 : colon_expr ':' expr {
$<start>$ = new string(*$<start>1);
$<stride>$ = new string(*$<stride>1);
$<stop>$ = new string(*$<source>3);
}
;
       
%%
#include "lex.yy.c"

void
yyerror (char const *s){
   printf("%s\n",s);
}

int main(int argc, const char ** argv){
 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 if(externalfile){
	fid = fopen(argv[1],"r");
 	yyrestart(fid);
}
 int res = yyparse();
 if(externalfile){
fclose(fid);
}

 return res;
}
