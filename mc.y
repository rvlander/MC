%{

#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

int yylex(void);
void yyerror (char const *s);


typedef struct tagYYSTYPE{
  string *source;	
  //for colon expression;
  string *start;
  string *stride;
  string *stop;
} YYST;

#define YYSTYPE YYST



%}


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

input : scriptMFile {cout << endl<< *$1.source << endl;YYACCEPT;}
;

scriptMFile : opt_delimiter {$$.source = new string();}
            | opt_delimiter statement_list {$$.source = new string(*$2.source);}
;

opt_delimiter :
	      |delimiter
;
delimiter :null_line
          |empty_lines
          |null_lines empty_lines
;
null_lines : null_line
           | null_lines null_line
;
null_line :','
          |';'
          |empty_lines ','
          |empty_lines ';'
;
empty_lines : NEWLINE
            | empty_lines NEWLINE
;

statement_list : statement opt_delimiter {$$.source = new string(*$1.source);}
               |statement delimiter statement_list {$$.source = new string(*$1.source+*$3.source);}
;

statement : expr { $$.source = new string(*$1.source+";\n");}
;
       

expr : expr '+' expr {$$.source = new string("add("+*$1.source+","+*$3.source+")");}
     | expr '-' expr {$$.source = new string("minus("+*$1.source+","+*$3.source+")");}
     | expr '*' expr {$$.source = new string("mtimes("+*$1.source+","+*$3.source+")");}
     | expr TIMES expr {$$.source = new string("times("+*$1.source+","+*$3.source+")");}
     | expr '/' expr {$$.source = new string("mdivide("+*$1.source+","+*$3.source+")");}
     | expr DIVIDE expr {$$.source = new string("divide("+*$1.source+","+*$3.source+")");}
     | expr '^' expr {$$.source = new string("mpow("+*$1.source+","+*$3.source+")");}
     | expr POWER expr {$$.source = new string("pow("+*$1.source+","+*$3.source+")");}
     | '(' expr ')' {$$.source = new string("("+*$2.source+")");}
     | '-' expr %prec MOINSUNAIRE { $$.source = new string("muminus("+*$2.source+")");}
     | colon_expr { 
$$.source = new string("colon("+*$1.start
  +",1,"+*$1.stop+")");}
     | colon_expr1 {$$.source = new string("colon("+*$1.start
  +","+*$1.stride+","+*$1.stop+")");}				     
     | NBRE { $$.source = new string(*$1.source);}
     | ID { $$.source = new string(*$1.source);}     
;



colon_expr :   expr ':' expr {  
  $$.start = new string(*$1.source);
  $$.stride = new string(*$3.source);
  $$.stop = new string(*$3.source);
}
;

colon_expr1 : colon_expr ':' expr {
$$.start = new string(*$1.start);
$$.stride = new string(*$1.stride);
$$.stop = new string(*$3.source);
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
