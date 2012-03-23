%{

#include <string>
#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>

using namespace std;

#include "tds.cpp"

int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s);

typedef struct tagYYSTYPE{
  string source;	
  //for colon expression;
  string start;
  string stride;
  string stop;
} YYST;

#define YYSTYPE YYST


%}
%token END
%token FUNCTION

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

input : scriptMFile {
cout << endl<< $1.source << endl;
writeJavaFile($1.source);
YYACCEPT;}
//      | functionMFile {cout << endl<< $1.source << endl;YYACCEPT;}
;

scriptMFile : opt_delimiter {$$.source = "";}
            | opt_delimiter statement_list {$$.source = $2.source;}
;

/*functionMFile : empty_lines f_def_line f_body {$$.source = $2.source+"{\n"+$3.source+"}\n";}
              | f_def_line f_body {$$.source = $1.source+"{\n"+$2.source+"}\n";}
;

f_def_line : FUNCTION ID f_input {$$.source = "void "+$2.source + $3.source;}
           | FUNCTION f_output '=' ID f_input{$$.source = $2.source+"="+$4.source+$5.source;}
;

f_input : '('')' {$$.source = "()";}
        | '(' f_in_arg_list ')' {$$.source = "("+$2.source+")";}
;
f_in_arg_list : ID {$$.source = $1.source;}
           | ID ',' f_in_arg_list {$$.source = $1.source +","+$3.source;}
;

f_output : '['']' {$$.source = "[]";}
         | '[' f_out_arg_list ']' {$$.source = "["+$2.source+"]";}
;
f_out_arg_list : ID {$$.source = $1.source;}
           | ID ',' f_out_arg_list {$$.source = $1.source +","+$3.source;}
	   | ID f_out_arg_list {$$.source = $1.source +","+$2.source;}
;

f_body : delimiter statement_list {$$.source = $2.source;} 
       | opt_delimiter {$$.source = "";} 
;
*/

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

statement_list : statement opt_delimiter {$$.source = $1.source;}
               |statement delimiter statement_list {$$.source = $1.source+$3.source;}
;

statement : expr { $$.source = $1.source+";\n";}
          | assignement { $$.source = $1.source+";\n";}
;
       

expr : expr '+' expr {$$.source = "add("+$1.source+","+$3.source+")";}
     | expr '-' expr {$$.source = "minus("+$1.source+","+$3.source+")";}
     | expr '*' expr {$$.source = "mtimes("+$1.source+","+$3.source+")";}
     | expr TIMES expr {$$.source = "times("+$1.source+","+$3.source+")";}
     | expr '/' expr {$$.source = "mdivide("+$1.source+","+$3.source+")";}
     | expr DIVIDE expr {$$.source = "divide("+$1.source+","+$3.source+")";}
     | expr '^' expr {$$.source = "mpower("+$1.source+","+$3.source+")";}
     | expr POWER expr {$$.source = "power("+$1.source+","+$3.source+")";}
     | '(' expr ')' {$$.source = "("+$2.source+")";}
     | '-' expr %prec MOINSUNAIRE { $$.source = "uminus("+$2.source+")";}
     | colon_expr {$$.source = "colon("+$1.start+",matrixFromDouble(1),"+$1.stop+")";}
     | colon_expr1 {$$.source = "colon("+$1.start+","+$1.stride+","+$1.stop+")";}				     
     | matrix {$$.source = $1.source;}
     | NBRE { $$.source = "matrixFromDouble("+$1.source+")";}
     | ID { $$.source = $1.source;
		symrec sr;
		if(!(TDSget($1.source, &sr))){
			cerr << " Symbol "+$1.source+" not declared" << endl;		
		}
		}
	 | ID '(' ref_expr_list ')' {
          symrec sr;
		  if(!(TDSget($1.source, &sr))){
			cerr << " Symbol "+$1.source+" not declared" << endl;		
		  }
          if(sr.idtype == VAR) {
		  	$$.source = "subsref("+$1.source+","+$3.source+")";
          }else{
          	$$.source = $1.source+"(null,"+$3.source+")";
          }
		}      
;



colon_expr :   expr ':' expr {  
  $$.start = $1.source;
  $$.stride = $3.source;
  $$.stop = $3.source;
}
;

colon_expr1 : colon_expr ':' expr {
$$.start = $1.start;
$$.stride = $1.stride;
$$.stop = $3.source;
}
;


ref_index :':'  {$$.source = "null";}
          | expr {$$.source = $1.source;}
;

ref_expr_list : {$$.source = "null";}
			  | comma_ref_list {$$.source = "new double[][][]{"+ $1.source+"}";}
;

comma_ref_list : ref_index {$$.source = $1.source;}
               | ref_index ',' comma_ref_list {$$.source = $1.source + "," + $3.source;}
;

matrix : '[' rows ']' { $$.source = $2.source ;}
;

rows : {$$.source = "new double[0][0]";}
     | row { $$.source = $1.source;}
     | rows ';' { $$.source = $1.source;}
     | rows ';' row { $$.source = "vertcat("+$1.source+","+$3.source+")"}
     | rows NEWLINE
     | rows NEWLINE row { $$.source = "vertcat("+$1.source+","+$3.source+")"}
;

row : expr { $$.source = $1.source ;}
    | row_with_commas { $$.source = $1.source ;}
    | row_with_commas expr { $$.source = "horzcat("+$1.source+","+$2.source+")";}
;

row_with_commas : expr ',' { $$.source = $1.source ;}
                |row_with_commas expr ',' { $$.source = "horzcat("+$1.source+","+$2.source+")";}
;

/*assignment : reference '=' expr {$$.source = new string(*$1.source +"="+*$2.source);}
           | s_assignee_matrix '=' expr {$$.source = new string(*$1.source +"="+*$2.source);}
           | m_assignee_matrix '=' reference {$$.source = new string(*$1.source +"="+*$2.source);}
;*/

//assignement simplifier!!!
assignement : ID '=' expr {
$$.source = "";
symrec sr;
if(!TDSget($1.source,&sr)){
 $$.source += "double[][] ";
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $1.source + "=" + $3.source;
}
            | ID '('ref_expr_list ')'  '=' expr{
$$.source = "";
symrec sr;
if(!TDSget($1.source,&sr)){
 $$.source += "double[][] " + $1.source +" ;\n";
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $1.source + " = subsasgn("+$1.source + "," + $3.source +","+$6.source+")";
}
              |'[' ID ']' '=' expr {
$$.source = "";
symrec sr;
if(!TDSget($2.source,&sr)){
 $$.source += "double[][] ";
 sr.idtype = VAR;
 if(!TDSinsert($2.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $2.source + "=" + $5.source;
}
            |  '[' ID '('ref_expr_list ')' ']' '=' expr{
$$.source = "";
symrec sr;
if(!TDSget($2.source,&sr)){
 $$.source += "double[][] " + $2.source +" ;\n";
 sr.idtype = VAR;
 if(!TDSinsert($2.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $2.source + " = subsasgn("+$2.source + "," + $4.source +","+$8.source+")";
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

void writeJavaFile(const string &source){
	ofstream outfile;
	outfile.open("MatCode.java",fstream::out);

	if (!outfile.is_open()){
		cerr << "can't open file" << endl;	
	}
 
	
	
	outfile << "import static org.mc.mcjavacore.MCJOperators.*;" << endl;
	outfile << "import static org.mc.mcjavautils.MCJUtils.*;" << endl;
	outfile << "import static org.mc.mcjavacore.MCJBaseFunctions.*;" << endl;
	outfile << "public class MatCode{" << endl;
	outfile << "public static void main(String args[]) throws Exception{" << endl;	
	outfile << source << endl;
	
	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
		outfile << "System.out.println();" <<endl;			
	}

    outfile << "}\n}" << endl;
	outfile.close();	
}
