%{

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

#include "tds.cpp"


struct ref_info{
    string id;
    bool is_simple;
    string ref_source; 
};



int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s);

typedef struct tagYYSTYPE{
  string source;	
  //for colon expression;
  string start;
  string stride;
  string stop;
  //for multiple assignement
  ref_info ri;
  vector<ref_info> varg;
} YYST;

#define YYSTYPE YYST




%}

%token TEXT

%token END
%token FUNCTION

%token FOR

%token IF
%token ELSEIF
%token ELSE

%token NBRE
%token ID
%token NEWLINE
%token TIMES
%token DIVIDE
%token LDIVIDE
%token POWER
%token TRANSPOSE
%token CTRANSPOSE
%token EQ
%token NE
%token LE
%token LOR
%token LAND

%token LD
%token RD


%left LOR
%left LAND
%left '|'
%left '&'
%left EQ NE '<' '>' LE GE
%left ':'
%left '+' '-'
%left '*' '/' TIMES DIVIDE 
%right MOINSUNAIRE PLUSUNAIRE '~'
%left '^' POWER TRANSPOSE CTRANSPOSE
%%

S : input {
cout << endl<< $1.source << endl;
writeJavaFile($1.source);
YYACCEPT;}

input : scriptMFile {$$.source = $1.source;}
      //|functionMFile {$$.source = $1.source;}
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

f_output : LD RD {$$.source = "[]";}
         | LD f_out_arg_list RD {$$.source = "["+$2.source+"]";}
;
f_out_arg_list : ID {$$.source = $1.source;}
           | ID ',' f_out_arg_list {$$.source = $1.source +","+$3.source;}
	   | ID f_out_arg_list {$$.source = $1.source +","+$2.source;}
;

f_body : delimiter statement_list {$$.source = $2.source;} 
       | opt_delimiter {$$.source = "";} 
;*/

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
	  | for_command  { $$.source = $1.source+";\n";}
	  | if_command  { $$.source = $1.source+";\n";}
;
       

expr : expr '+' expr {$$.source = "add("+$1.source+","+$3.source+")";}
     | expr '-' expr {$$.source = "minus("+$1.source+","+$3.source+")";}
     | expr '*' expr {$$.source = "mtimes("+$1.source+","+$3.source+")";}
     | expr TIMES expr {$$.source = "times("+$1.source+","+$3.source+")";}
     | expr '/' expr {$$.source = "mrdivide("+$1.source+","+$3.source+")";}
     | expr '\\' expr {$$.source = "mldivide("+$1.source+","+$3.source+")";}
     | expr DIVIDE expr {$$.source = "rdivide("+$1.source+","+$3.source+")";}
     | expr LDIVIDE expr {$$.source = "ldivide("+$1.source+","+$3.source+")";}
     | expr '^' expr {$$.source = "mpower("+$1.source+","+$3.source+")";}
     | expr POWER expr {$$.source = "power("+$1.source+","+$3.source+")";}
     | expr EQ expr {$$.source = "eq("+$1.source+","+$3.source+")";}
     | expr NE expr {$$.source = "ne("+$1.source+","+$3.source+")";}
     | expr '<' expr {$$.source = "lt("+$1.source+","+$3.source+")";}
     | expr '>' expr {$$.source = "gt("+$1.source+","+$3.source+")";}
     | expr LE expr {$$.source = "le("+$1.source+","+$3.source+")";}
     | expr GE expr {$$.source = "ge("+$1.source+","+$3.source+")";}
     | expr '|' expr {$$.source = "or("+$1.source+","+$3.source+")";}
     | expr '&' expr {$$.source = "and("+$1.source+","+$3.source+")";}
     | expr LOR expr {$$.source = "lor("+$1.source+","+$3.source+")";}
     | expr LAND expr {$$.source = "land("+$1.source+","+$3.source+")";}
     | expr TRANSPOSE {$$.source = "transpose("+$1.source+")";}
     | expr CTRANSPOSE {$$.source = "ctranspose("+$1.source+")";}
     | '(' expr ')' {$$.source = "("+$2.source+")";}
     | '-' expr %prec MOINSUNAIRE { $$.source = "uminus("+$2.source+")";}
     | '+' expr %prec PLUSUNAIRE { $$.source = $2.source;}
     | '~' expr { $$.source = "not("+$2.source+")";} 
     | colon_expr {$$.source = "colon("+$1.start+",matrixFromDouble(1),"+$1.stop+")";}
     | colon_expr1 {$$.source = "colon("+$1.start+","+$1.stride+","+$1.stop+")";}				     
     | matrix {$$.source = $1.source;}
     | NBRE { $$.source = "matrixFromDouble("+$1.source+")";}
     | TEXT { $$.source = $1.source }
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
              |LD ID RD '=' expr {
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
            |  LD ID '('ref_expr_list ')' RD '=' expr{
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
            | LD output_ref_list RD '=' ID  '(' ref_expr_list ')' {
   symrec sr;
   if(!TDSget($5.source,&sr)){
	cerr << "symbol undefined" << endl; 
   } else if(sr.idtype != FUNC){
        cerr << "Too many output arguments : " + $5.source + " is not a function !" << endl;
   }
   ostringstream oss;
   oss << "MCJOutputArg[] oa = new MCJOutputArg[" << $2.varg.size() << "];\n";
   for(int i=0;i<$2.varg.size();i++){
	ref_info ri = $2.varg[i];	
	oss << "oa[" << i << "]= new MCJOutputArg();\n";	
	/*if(!ri.is_simple){
		oss << "double[][] " << ri.id << i << ";\n";
		oss << "oa[" << i << "].val=" << ri.id <<i<< ";\n";	
	} else {
	   oss << "oa[" << i << "].val=" << ri.id << ";\n";
        }*/
	symrec sr;
	if(!TDSget(ri.id,&sr)){
 	oss << "double[][] " << ri.id <<";"<< endl;
 	sr.idtype = VAR;
 	if(!TDSinsert(ri.id,sr)){
  		cerr << "pas possible assignement" << endl;
 	}
}
   	
	 
   }
   oss << $5.source << "(oa," + $7.source +")";
	
   for(int i=0;i<$2.varg.size();i++){
	ref_info ri = $2.varg[i];	
	if(!ri.is_simple){
		oss << ";\nsubsasgn(" <<ri.id <<"," << ri.ref_source <<"," << "oa[" << i <<"].val" << ")";
	}else{
		oss << ";\n"<< ri.id <<"=" << "oa[" << i <<"].val";	
	}
   }
	
   $$.source = oss.str();

}
;  
    

output_ref_list :  out_ref ',' out_ref  { $$.varg.push_back($1.ri); $$.varg.push_back($3.ri);}
		 |  output_ref_list ',' out_ref { 
for(int i=0;i<$1.varg.size();i++){
	$$.varg.push_back($1.varg[i]);
}
$$.varg.push_back($3.ri);
}
;

out_ref  :  ID { 
ref_info rinf;
rinf.id = $1.source;
rinf.is_simple = true;
$$.ri = rinf	
}
         |  ID '('ref_expr_list ')'{ 
ref_info rinf;
rinf.id = $1.source;
rinf.is_simple = false;
rinf.ref_source = $3.source;
$$.ri = rinf
}
;

for_command : FOR ID '=' expr NEWLINE  statement_list END {
$$.source  = " double[][] fortemp =" + $4.source +";\n";
$$.source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
$$.source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
$$.source += "double[][] "+ $2.source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
$$.source += $6.source;
$$.source += "}\n}\n";
}
            | FOR ID '=' expr statement_list END {
$$.source  = " double[][] fortemp =" + $4.source +";\n";
$$.source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
$$.source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
$$.source += "double[][] "+ $2.source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
$$.source += $5.source;
$$.source += "}\n}\n";
}
;

if_command : if_block else_if_list else_block END {$$.source =$1.source+$2.source+$3.source;}
;  

if_block : IF expr NEWLINE statement_list NEWLINE {$$.source = "if(any("+$2.source+")){"+$4.source+"}";}
;

else_if_list: {$$.source ="";}
            | elseif_block else_if_list {$$.source = $1.source + $2.source;}
;

elseif_block : ELSEIF expr NEWLINE statement_list NEWLINE {$$.source = "else if(any("+$2.source+")){"+$4.source+"}";}
;

else_block : {$$.source ="";}
            |ELSE NEWLINE statement_list NEWLINE {$$.source = "else{"+$3.source+"}";}
;

 

   
%%
#include "lex.yy.c"

void yyerror (char const *s){
   printf("%s\n",s);
}

int main(int argc, const char ** argv){

symrec sri;
sri.idtype = FUNC;

TDSinsert("numel",sri);
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
	outfile << "import static org.mc.mcfunctions.MCJFunctions.*;" << endl;
	outfile << "import org.mc.mcfunctions.MCJOutputArg;" << endl;
	outfile << "import static org.mc.mcjavautils.MCJUtils.*;" << endl;
	outfile << "import static org.mc.mcjavacore.MCJBaseFunctions.*;" << endl;
	outfile << "public class MatCode{" << endl;
	outfile << "public static void main(String args[]) throws Exception{" << endl;	
	outfile << source << endl;
	
	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		if ((it->second).idtype == VAR){		
			outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
			outfile << "System.out.println();" <<endl;
		}			
	}

    outfile << "}\n}" << endl;
	outfile.close();	
}
