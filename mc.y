%{

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <errno.h>
#include <map>
#include <fstream>
#include <vector>

#include <libgen.h>
#include <dirent.h>

using namespace std;

#include "tds.h"
#include "compiler.h"

#define ROUGE "\\033[1;31m" 
#define VERT "\\033[1;32m" 
#define NORMAL "\\033[0;39m"
#define BLEU "\\033[1;34m" 


/*ROSE="\\033[1;35m" BLEU="\\033[1;34m" BLANC="\\033[0;02m" BLANCLAIR="\\033[1;08m" JAUNE="\\033[1;33m" CYAN="\\033[1;36m"*/


struct ref_info{
    string id;
    bool is_simple;
    string ref_source; 
};

bool isIn(string s,vector<ref_info> &varg){
	bool res = false;
	for(int i=0;i<varg.size();i++){
	   res = res | s.compare(varg[i].id)==0;	
	}	
	return res;
}



int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s, bool);
int searchFunction(const string &id);
void replaceEnds(const string &var_name,int out_ref,string &source);

typedef struct tagYYSTYPE{
  //type of programm
  bool ismain;
  string source;	
  //for colon expression;
  string start;
  string stride;
  string stop;
  //for multiple assignement
  ref_info ri;
  vector<ref_info> varg;
  vector<ref_info> ivarg;
  //better delcaration
  vector<string> to_declare;
  //used by ref_exprlist (outer var name)
  int out_ref=0;

} YYST;

#define YYSTYPE YYST

ofstream outfile;

vector<string> to_compile;

int in_matrix =0;

bool testing = false;

string class_name;

int aonumber=0;
int fornumber=0;

bool need_declare;

int no_line=1;


%}

%token TEXT

%token EXEND
%token END
%token FUNCTION

%token RETURN

%token FOR

%token IF
%token ELSEIF
%token ELSE
%token WHILE

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
%token MSPACE


//%token VARARGIN


%left LOR
%left LAND
%left '|'
%left '&'
%left EQ NE '<' '>' LE GE
%left ':'
%left '+' '-'
%left '*' '/' TIMES DIVIDE '\\' LDIVIDE
%right MOINSUNAIRE PLUSUNAIRE '~'
%left '^' POWER TRANSPOSE CTRANSPOSE
%%

prog : input_list {YYACCEPT;};

input_list : S
	    | input_list S; 

S : input {
//cout << endl<< $1.source << endl;
writeJavaFile($1.source,$$.ismain);
}

input : scriptMFile {$$.source = $1.source;$$.ismain= true;}
        |functionMFile {$$.source = $1.source;$$.ismain=false;}
;

scriptMFile : opt_delimiter {$$.source = "";}
            | opt_delimiter statement_list {
for(int i=0;i<$2.to_declare.size();i++){
	$$.source += "double[][] "+$2.to_declare[i]+" = new double[0][0];\n";
}
$$.source += $2.source;}
;

functionMFile : empty_lines f_all opt_end{$$.source = $2.source;}
              | f_all opt_end{$$.source = $1.source;}
;
opt_end : 
        | END opt_delimiter
;

f_all : f_def_line f_body {$$.source = $1.source+" throws Exception,Throwable{\n";


symrec sr;
sr.idtype =VAR;
$$.source += "double[][] nargin = matrixFromDouble(iargs.length);\n";
//$$.source += "double[][][] varargin = iargs;\n";
for(int i=0;i<$1.ivarg.size();i++){
ostringstream oss;
oss << i;
string li = oss.str();
$$.source += "double[][] " + $1.ivarg[i].id +"= new double[0][0];\nif(nargin[0][0]>"+li+")"+$1.ivarg[i].id+ "= iargs["+oss.str()+"];\n";
//cout << $1.ivarg[i].id<< endl;
TDSremove($1.ivarg[i].id);
}

for(int i=0;i<$1.varg.size();i++){
if(!isIn($1.varg[i].id,$1.ivarg)){
$$.source += "double[][] " + $1.varg[i].id +"= new double[0][0];\n";
TDSremove($1.varg[i].id);
}
//cout << "#" << $1.varg[i].id<< endl;
}
$$.source += $2.source+"\n";
$$.source += "if(oargs !=null){\n";
for(int i=0;i<$1.varg.size();i++){
ostringstream oss;
oss << i;
$$.source += "if(oargs.length>"+oss.str()+")"+ $1.varg[i].ref_source +"=" + $1.varg[i].id+";\n";
}
$$.source += "}\n";
$$.source +=  "return "+$1.varg[0].id+";\n}\n";}
;

f_def_line : FUNCTION ID f_input {$$.source = "double[][] "+$2.source + $3.source;}
           | FUNCTION f_output '=' ID f_input{$$.source = "public static double[][] "+$4.source+$5.source;
$$.varg=$2.varg;
$$.ivarg=$5.ivarg;
}
;

f_input : '('')' {$$.source = "(MCJOutputArg[] oargs,double[][][] iargs)";}
        | '(' f_in_arg_list ')' {$$.source = "(MCJOutputArg[] oargs,double[][][] iargs)";$$.ivarg = $2.ivarg;}
;
f_in_arg_list : ID {$$.source = "double[][] "+$1.source;
symrec sr;
if(!TDSget($1.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info ri;
ri.id = $1.source;
$$.ivarg.push_back(ri);
}
           | f_in_arg_list ',' ID {
symrec sr;
if(!TDSget($3.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($3.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source = $1.source +", double[][] "+$3.source;
ref_info ri;
ri.id = $3.source;
$$.ivarg.push_back(ri);
}
;

f_output : LD RD {}
         | LD f_out_arg_list RD {$$.varg = $2.varg;}
         | ID {
symrec sr;
if(!TDSget($1.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info rinf;
rinf.id = $1.source;	
rinf.ref_source = "oargs[0].val";
$$.varg.push_back(rinf);
}
;
f_out_arg_list : ID {
symrec sr;
if(!TDSget($1.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
ref_info rinf;
rinf.id = $1.source;	
rinf.ref_source = "oargs[0].val";
$$.varg.push_back(rinf);
}
           |f_out_arg_list ',' ID { 
symrec sr;
if(!TDSget($3.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($3.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
int n = $1.varg.size();
//cerr << &$$ << " " << &$1 << endl;
//cerr << "nb o args"<< $$.varg[0].id << endl;
/*for(int i=0;i<n;i++){
cerr << "i = "<< i << endl;
	$$.varg.push_back($1.varg[i]);
}*/
//cerr << "nb o args "<< $$.varg.size() << endl;
ostringstream oss;
oss << "oargs[" << n <<"].val";
$3.ri.ref_source = oss.str();
$3.ri.id= $3.source;
$$.varg.push_back($3.ri);
//cerr << "nb o args "<< $$.varg.size() << endl;

}
	   | f_out_arg_list ID{

symrec sr;
if(!TDSget($2.source,&sr)){
 sr.idtype = VAR;
 if(!TDSinsert($2.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}

int n = $1.varg.size(); 
/*for(int i=0;i<n;i++){
	$$.varg.push_back($1.varg[i]);
}*/
ostringstream oss;
oss << "oargs[" << n <<"].val";
$2.ri.ref_source = oss.str();
$2.ri.id= $2.source;
$$.varg.push_back($2.ri);
}
;

f_body : delimiter statement_list {
$$.source ="";
for(int i=0;i<$2.to_declare.size();i++){
	$$.source += "double[][] "+$2.to_declare[i]+" = new double[0][0];\n";
	TDSremove($2.to_declare[i]);
}
$$.source +="label:do{\n";
$$.source +=  $2.source;
$$.source += "}while(false);";
} 
       | opt_delimiter {$$.source = "";} 
;

opt_delimiter :
	      |delimiter              
;

delimiter :null_lines
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

statement_list : statement opt_delimiter {$$.source = $1.source;$$.to_declare = $1.to_declare;}
               |statement delimiter statement_list {$$.source = $1.source+$3.source;
	$$.to_declare = $1.to_declare;
        for(int i=0;i<$3.to_declare.size();i++){
		$$.to_declare.push_back($3.to_declare[i]);
	}
/*for(int i=0;i<$$.to_declare.size();i++){
		cout << $$.to_declare[i] << endl;
	}*/
}
;

statement : expr { $$.source = $1.source+";\n";}
          | assignement { $$.source = $1.source+";\n";$$.to_declare = $1.to_declare;}
	  | for_command  { $$.source = $1.source+";\n";$$.to_declare = $1.to_declare;}
	  | if_command  { $$.source = $1.source+";\n";$$.to_declare = $1.to_declare;}
          | while_command  { $$.source = $1.source+";\n";$$.to_declare = $1.to_declare;}
	  | RETURN  { $$.source = "break label;\n";}

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
     | EXEND { $$.source = "end" ;}
     | TEXT {
int tn = $1.source.size();
$1.source[0] = '"';
$1.source[tn-1] = '"'; 
$$.source = "matrixFromText("+$1.source+")" ;
}
     |'@' ID {
int tn = $2.source.size();
$2.source.insert(0,"\"");
$2.source.append("\""); 
$$.source = "matrixFromText("+$2.source+")" ;
}
     | ID { $$.source = $1.source;
		symrec sr;
		if(!(TDSget($1.source, &sr))){
			cerr << " Symbol "+$1.source+" not declared" << endl;		
		}
		}
	 | ID '('  ref_expr_list ')' {	  
                symrec sr;
		if(!(TDSget($1.source, &sr))){
                        int t = searchFunction($1.source);
			if(t != false) {
                                sr.idtype = FUNC;
                                if(!TDSinsert($1.source,sr)){
                                        cerr << "pas possible assignement" << endl;
                                }
			}else {
                                cerr << " Symbol "+$1.source+" not declared" << endl;
				sr.idtype = FUNC;  
			}		
                }
                if(sr.idtype == VAR) {
                        $$.source = "subsref("+$1.source+","+$3.source+")";
			replaceEnds($1.source,$3.out_ref,$$.source);
                }else{
                        $$.source = $1.source+"(null,"+$3.source+")";
                }
	}
         
        | ID '{' ref_index '}'{
                symrec sr;
		if(!(TDSget($1.source, &sr))){
                        cerr << " Symbol "+$1.source+" not declared" << endl;		
                }
                if(sr.idtype == VAR) {
                    if($3.source =="null")
                        $$.source = $1.source;
                    else{
                        $$.source = "cell_subsref("+$1.source+","+$3.source+")";
			replaceEnds($1.source,1,$$.source);
                    }
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
              | comma_ref_list {$$.source = "new double[][][]{"+ $1.source+"}";$$.out_ref = $1.out_ref;}
//              | VARARGIN {$$.source = "iargs";}
;

comma_ref_list : ref_index {$$.source = $1.source;$$.out_ref = 1;}
               | ref_index ',' comma_ref_list {$$.source = $1.source + "," + $3.source;$$.out_ref = 2;}
;

matrix : '[' {in_matrix++;} rows ']' {in_matrix--; $$.source = $3.source ;}
;

rows : {$$.source = "new double[0][0]";}
     | row { $$.source = $1.source;}
     | rows ';' { $$.source = $1.source;}
     | rows ';' row { $$.source = "vertcat("+$1.source+","+$3.source+")";}
     | rows NEWLINE
     | rows NEWLINE row { $$.source = "vertcat("+$1.source+","+$3.source+")";}
;

row : expr { $$.source = $1.source ;}
    | row_with_commas { $$.source = $1.source ;}
    | row_with_commas expr { $$.source = "horzcat("+$1.source+","+$2.source+")";}
;

row_with_commas : expr ',' { $$.source = $1.source ;}
                | expr MSPACE { $$.source = $1.source ;}
                |row_with_commas expr ',' { $$.source = "horzcat("+$1.source+","+$2.source+")";}
                |row_with_commas expr MSPACE { $$.source = "horzcat("+$1.source+","+$2.source+")";}
;

assignement : ID '=' expr {
$$.source = "";
symrec sr;
if(!TDSget($1.source,&sr)){
 $$.to_declare.push_back($1.source);
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
 $$.to_declare.push_back($1.source);
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $1.source + " = subsasgn("+$1.source + "," + $3.source +","+$6.source+")";
replaceEnds($1.source,$3.out_ref,$$.source);
}
            
            | ID '{'expr '}'  '=' expr{
$$.source = "";
symrec sr;
if(!TDSget($1.source,&sr)){
 $$.to_declare.push_back($1.source);
 sr.idtype = VAR;
 if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $1.source+"[(int)" + $3.source +"]" + " = " + $6.source; 
//replaceEnds($1.source,$3.out_ref,$$.source);
}
              |LD ID RD '=' expr {
$$.source = "";
symrec sr;
if(!TDSget($2.source,&sr)){
 $$.to_declare.push_back($1.source);
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
 $$.to_declare.push_back($1.source);
 sr.idtype = VAR;
 if(!TDSinsert($2.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}
$$.source += $2.source + " = subsasgn("+$2.source + "," + $4.source +","+$8.source+")";
replaceEnds($2.source,$4.out_ref,$$.source);
} 
            | LD output_ref_list RD '=' ID  '(' ref_expr_list ')' {
	$$.to_declare = $2.to_declare;
   symrec sr;
   if(!TDSget($5.source,&sr)){
	int t = searchFunction($5.source);
			if(t != false) {
				sr.idtype = FUNC;
                              if(!TDSinsert($5.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
			}else {
			cerr << " Symbol "+$5.source+" not declared" << endl;
				//YYERROR;                         
			}	 
   } else if(sr.idtype != FUNC){
        cerr << "Too many output arguments : " + $5.source + " is not a function !" << endl;
   }
   ostringstream oss;
   oss  << "MCJOutputArg[] oa" <<aonumber <<";"<<endl;
   oss << "oa"<<aonumber<<" = new MCJOutputArg[" << $2.varg.size() << "];\n";
   for(int i=0;i<$2.varg.size();i++){
	ref_info ri = $2.varg[i];	
	oss << "oa"<<aonumber<<"[" << i << "]= new MCJOutputArg();\n";	
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
   oss << $5.source << "(oa"<<aonumber<<"," + $7.source +")";
	
   for(int i=0;i<$2.varg.size();i++){
	ref_info ri = $2.varg[i];	
	if(!ri.is_simple){
		oss << ";\nsubsasgn(" <<ri.id <<"," << ri.ref_source <<"," << "oa"<<aonumber<<"[" << i <<"].val" << ")";
	}else{
		oss << ";\n"<< ri.id <<"=" << "oa"<<aonumber<<"[" << i <<"].val";	
	}
   }
	
   $$.source = oss.str();
   aonumber++;

}
;  
    

output_ref_list :  out_ref ',' out_ref  { $$.varg.push_back($1.ri); $$.varg.push_back($3.ri);
symrec sr;
if(!TDSget($1.ri.id,&sr)){
$$.to_declare.push_back($1.ri.id);
sr.idtype = VAR;
TDSinsert($1.ri.id,sr);

}
if(!TDSget($3.ri.id,&sr)){
$$.to_declare.push_back($3.ri.id);
sr.idtype = VAR;
TDSinsert($3.ri.id,sr);
}}
		 |  output_ref_list ',' out_ref { 

/*for(int i=0;i<$1.varg.size();i++){
	$$.varg.push_back($1.varg[i]);
}*/
$$.varg.push_back($3.ri);
$$.to_declare = $1.to_declare;
symrec sr;
if(!TDSget($3.ri.id,&sr)){
$$.to_declare.push_back($3.ri.id);
sr.idtype = VAR;
TDSinsert($3.ri.id,sr);
}
}
;

out_ref  :  ID { 
ref_info rinf;
rinf.id = $1.source;
rinf.is_simple = true;
$$.ri = rinf;	
}
	|  '~' { 
ref_info rinf;
rinf.id = "ignored_arg";
rinf.is_simple = true;
$$.ri = rinf;
}
         |  ID '('ref_expr_list ')'{ 

// là aussi 
ref_info rinf;
rinf.id = $1.source;
rinf.is_simple = false;
rinf.ref_source = $3.source;
$$.ri = rinf;
}
;

for_command : FOR ID  {



symrec sr;
need_declare = false;
if(!TDSget($2.source,&sr)){
 need_declare = true;
 sr.idtype = VAR;
 if(!TDSinsert($2.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
}}
'=' expr opt_delimiter  statement_list END {

$$.to_declare = $7.to_declare;
ostringstream oss;
oss << fornumber;
$$.source  = "double[][] fortemp"+oss.str()+" =" + $5.source +";\n";
$$.source += " for(int posdfo=0;posdfo<fortemp"+oss.str()+".length;posdfo++){ \n";
$$.source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp"+oss.str()+"[0].length;sdfgsdfgdf++){ \n";

if(need_declare) $$.source += "double[][] ";
$$.source += $2.source + " = matrixFromDouble(fortemp"+oss.str()+"[posdfo][sdfgsdfgdf]);\n";
$$.source += $7.source;
$$.source += "}\n}\n";

if(TDSremove($2.source) !=1){
	cerr << "problème de varaible dans al boucle interne" <<endl;
};

fornumber++;

}

if_command : if_block else_if_list else_block END {
$$.to_declare = $1.to_declare;
for(int i=0;i<$2.to_declare.size();i++){
	$$.to_declare.push_back($2.to_declare[i]);
}
for(int i=0;i<$3.to_declare.size();i++){
	$$.to_declare.push_back($3.to_declare[i]);
}
$$.source =$1.source+$2.source+$3.source;}
;  

if_block : IF expr opt_delimiter statement_list {
$$.to_declare = $4.to_declare;
$$.source = "if(any("+$2.source+")){"+$4.source+"}";}
;

else_if_list: {$$.source ="";}

            | elseif_block else_if_list {
$$.to_declare = $1.to_declare;
for(int i=0;i<$2.to_declare.size();i++){
	$$.to_declare.push_back($2.to_declare[i]);
}
$$.source = $1.source + $2.source;}
;

elseif_block : ELSEIF expr opt_delimiter statement_list {
$$.to_declare = $4.to_declare;
$$.source = "else if(all("+$2.source+")){"+$4.source+"}";}
;

else_block : {$$.source ="";}
            |ELSE opt_delimiter statement_list {
$$.to_declare = $3.to_declare;
$$.source = "else{"+$3.source+"}";}
;

while_command: WHILE expr opt_delimiter statement_list END 
{$$.to_declare = $4.to_declare;
$$.source = "while(any("+$2.source+")){"+$4.source+"}";}
;
 

   
%%
#include "lex.yy.c"


void replaceEnds(const string &var_name,int out_ref,string &source){
if(out_ref == 2){
			//renplacer end par A.lentght et A[0].length
		         int pos = source.find("end");
				if(pos !=-1){	
			 source.erase(pos,3);
			 string rep = "matrixFromDouble("+var_name+".length)"; 
			 source.insert(pos,rep);
}
			 pos = source.find("end");
				if(pos !=-1){	
			 source.erase(pos,3);
			 string rep = "matrixFromDouble("+var_name+"[0].length)"; 
			 source.insert(pos,rep);
}
			}else if(out_ref == 1){
			int pos =1;
			while(pos!=-1){			

			pos = source.find("end");
			if(pos !=-1){	
			 source.erase(pos,3);
			 string rep = "numel("+var_name+")"; 
			 source.insert(pos,rep);
			}
			}
			
		}
}

void yyerror (char const *s){
   printf("%s\n",s);
}


void writeJavaFileHeader(const string &classname){
outfile << "import static org.mc.mcjavacore.MCJOperators.*;" << endl;
	outfile << "import static org.mc.mcfunctions.MCJFunctions.*;" << endl;
	outfile << "import org.mc.mcfunctions.MCJOutputArg;" << endl;
	outfile << "import static org.mc.mcjavautils.MCJUtils.*;" << endl;
	outfile << "import static org.mc.mcjavacore.MCJBaseFunctions.*;" << endl;
	outfile << "public class "<<classname<<"{" << endl;
	outfile << "static final double[][] pi = matrixFromDouble(Math.PI);" << endl;
	//outfile << "static double[][] fortemp;" << endl;

}

string root_file;
vector<string> readtestHeader(string path){
char ligne[1024];
string ll;
ifstream fp(path.c_str());
vector<string> args;
    int posi, posf;
    bool stop = false;

    //reading header %A,B,C
    fp.getline(ligne, 1024);
    ll = ligne;
    ll.erase(0, 1);

    posi = 0;
    posf = 0;
    while (!stop) {
        posf = ll.find(",", posi);
        //cout << posf << endl;
        if (posf == -1)
            stop = true;
        else {
            args.push_back(ll.substr(posi, posf -posi));
            posi = posf + 1;
        }
    }
    args.push_back(ll.substr(posi, ll.size()));
    return args;
}

void includeTesting(){
char ligne[1024];
string lpath = root_file +".java.in";
ifstream fp(lpath.c_str());
while(fp.getline(ligne,1024)){
       string ll(ligne);
       outfile << ligne <<endl;
    }
vector<string> vs = readtestHeader(root_file);

outfile <<"System.out.println(\""<< BLEU <<"Testing : "<< root_file <<" "<< NORMAL <<"\");"<< endl;
outfile <<"boolean res;\nString color;"<< endl;
for(int i=0;i<vs.size();i++){	
	outfile << "res = all(eq("<< vs[i]<< "," << vs[i] <<"_matlab_result" <<"));" <<endl;
	outfile << "color = res?\""<<VERT << "\":\"" << ROUGE <<"\";"<< endl;
	outfile <<"System.out.println(\"   "<< vs[i]<< " test (true is ok): \"+color+res+\""<< NORMAL <<"\");"<< endl;
}

    
}

void writeJavaFile(const string &source, bool ismain){
	
 
	
	
	if(ismain) outfile << "public static void main(String args[]) throws Exception,Throwable{" << endl;	
	outfile << source << endl;
	
	if(ismain){
	if(!testing){
/*	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		if ((it->second).idtype == VAR){		
			outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
			outfile << "System.out.println();" <<endl;
		}			
	}*/
	}
	else{
		includeTesting();	
	}
	outfile << "}" << endl;
	}
}
void writeJavaFileFooter(){
    	outfile << "}" << endl;	
}


/******************/
vector<string> les_path;

bool isBuiltin(string path){
     ifstream fp(path.c_str());

     char ligne[1024];

     int res = false;

     while(fp.getline(ligne,1024)&& !res){
	string ll(ligne);
        int r = ll.find("Built-in");   
	//cout << "find result  : " << r << endl;  
	if(r!=-1){
		cout << "Built-in function "<< path <<endl;	
		res = true;
	} 

     } 
	return res;
}

int searchFunction(const string &id){
	int res =0;
	DIR * pdir;
	struct dirent *pdirent;

	string target = id+".m";
       

	int n = les_path.size();
	int i=0;	
	
	while (res ==0 && i<n){

	string lepath = les_path[i];
	pdir = opendir(lepath.c_str());

 	if(pdir == NULL){
		//cout << strerror(errno) << endl;	
	}else{

	while(res==0 && (pdirent = readdir(pdir)) != NULL){
		if(target.compare(pdirent->d_name)==0){
			res =1;	
			string path = lepath+ "/" + target;

			if(!isBuiltin(path)){
				cout << path << " not built-in "<< endl;
				to_compile.push_back(path);
			
			}	
		}	
	}
	
}
closedir(pdir);
	i++;
	}
	
	if(!res){
		cout << "function "<< id << " not found !" << endl;	
	} 

	return res;
}

void readPathFile(string path_file){
     ifstream fp(path_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        // cout << "added :" << ll << endl;
        les_path.push_back(ligne);     

     } 
     
     char p[1024];
     strcpy(p,root_file.c_str());
     char * base = dirname(p);
     string ss(base);
     les_path.push_back(ss);
}

void readFunctionFile(string func_file){
     ifstream fp(func_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        symrec sri;
	sri.idtype = FUNC;
	TDSinsert(ll,sri);   

     } 
}

void readGlobalsFile(string globals_file){
     ifstream fp(globals_file.c_str());

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        symrec sri;
	sri.idtype = VAR;
	TDSinsert(ll,sri);   

     } 
}

void includeBeforeHeader(const char * filepath){
     ifstream fp(filepath);

     char ligne[1024];

     while(fp.getline(ligne,1024)){
	string ll(ligne);
        outfile<< ll <<endl;

     } 
}

void compile(const char * matlab_src, const char * output_dir, const char * header_file, bool test,bool v) {

    testing = test;
    verb=v;
    
    FILE * fid;
    
    
    root_file = matlab_src;

    to_compile.push_back(root_file);

    readPathFile("/home/rvlander/These/MatlabCompiler/MC/path_file");
    readFunctionFile("/home/rvlander/These/MatlabCompiler/MC/func_file");
    readFunctionFile("/home/rvlander/These/MatlabCompiler/MC/globals_file");

    int pos = root_file.find_last_of(".");
    class_name = root_file.substr(0, pos);

    string outf = class_name + ".java";
    if(output_dir != NULL){
        char p[1024];
        strcpy(p,outf.c_str());
        char * base = basename(p);
        outf = string(output_dir) +"/"+base;
    }
    outfile.open(outf.c_str(), fstream::out);

    if (!outfile.is_open()) {
        cerr << "can't open file : "<< outf << endl;
    }


    pos = class_name.find_last_of("/");
    if (header_file != NULL) {
        includeBeforeHeader(header_file);
    }
    writeJavaFileHeader(class_name.substr(pos + 1, class_name.npos - pos));


    cout << "Begin compiling ..." << endl;


    while (!to_compile.empty()) {
        string comp = to_compile.back();
        to_compile.pop_back();
        //cout << "Compiling " << comp << endl;
        fid = fopen(comp.c_str(), "r");
       // cout << "File opened" <<fid  << endl; 	
        in_matrix = 0;
        yyrestart(fid);
        no_line=1;
      //  verbose("1> ");
        yyparse();
       // cout << "File parsed" << endl;
        fclose(fid);
        //cout << "File closed" << endl;
    }
    writeJavaFileFooter();
    outfile.close();

}


/*int main(int argc, const char ** argv){



 FILE *fid;
 root_file = argv[1];
 
 
 
 
 

 to_compile.push_back(argv[1]);
 
	readPathFile("path_file");
	readFunctionFile("func_file");
readFunctionFile("globals_file");

	int pos = root_file.find_last_of(".");
	class_name = root_file.substr(0,pos);

	string outf = class_name +".java";
	outfile.open(outf.c_str(),fstream::out);

	if (!outfile.is_open()){
		cerr << "can't open file" << endl;	
	}


pos = class_name.find_last_of("/");
if(argc>2){
    includeBeforeHeader(argv[2]);
}
writeJavaFileHeader(class_name.substr(pos+1,class_name.npos-pos));


cout << "Begin compiling ..." << endl;

 
while(!to_compile.empty()){
	string comp = to_compile.back();
	to_compile.pop_back();
	cout << "Compiling " << comp << endl;
	fid = fopen(comp.c_str(),"r");
	//cout << "File opened" << endl; 	
	in_matrix =0;
	yyrestart(fid);
 	yyparse();
//cout << "File parsed" << endl;
	fclose(fid);
//cout << "File closed" << endl;
}
writeJavaFileFooter();
outfile.close();

 return 0;
}*/

