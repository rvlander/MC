%{

#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <vector>

#include <dirent.h>

using namespace std;

#include "tds.cpp"


struct ref_info{
    string id;
    bool is_simple;
    string ref_source; 
};



int yylex(void);
void yyerror (char const *s);
void writeJavaFile(const string &s, bool);
int searchFunction(const string &id);

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
} YYST;

#define YYSTYPE YYST

ofstream outfile;

vector<string> to_compile;

int in_matrix =0;


%}

%token TEXT

%token END
%token FUNCTION

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

S : input {
cout << endl<< $1.source << endl;
writeJavaFile($1.source,$$.ismain);
YYACCEPT;}

input : scriptMFile {$$.source = $1.source;$$.ismain= true}
        |functionMFile {$$.source = $1.source;$$.ismain=false}
;

scriptMFile : opt_delimiter {$$.source = "";}
            | opt_delimiter statement_list {$$.source = $2.source;}
;

functionMFile : empty_lines f_all {$$.source = $2.source}
              | f_all {$$.source = $1.source}
;

f_all : f_def_line f_body {$$.source = $1.source+" throws Exception{\n";

$$.source += "double[][] nargin = matrixFromDouble(iargs.length);\n";

for(int i=0;i<$1.ivarg.size();i++){
ostringstream oss;
oss << i;
string li = oss.str();
$$.source += "double[][] " + $1.ivarg[i].id +"= new double[0][0];\nif(nargin[0][0]>"+li+")"+$1.ivarg[i].id+ "= iargs["+oss.str()+"];\n";
}

for(int i=0;i<$1.varg.size();i++){
$$.source += "double[][] " + $1.varg[i].id +"= new double[0][0];\n";
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

f_body : delimiter statement_list {$$.source = $2.source;} 
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

statement_list : statement opt_delimiter {$$.source = $1.source;}
               |statement delimiter statement_list {$$.source = $1.source+$3.source;}
;

statement : expr { $$.source = $1.source+";\n";}
          | assignement { $$.source = $1.source+";\n";}
	  | for_command  { $$.source = $1.source+";\n";}
	  | if_command  { $$.source = $1.source+";\n";}
          | while_command  { $$.source = $1.source+";\n";}

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
			int t = searchFunction($1.source);
			if(t != false) {
				sr.idtype = FUNC;
                              if(!TDSinsert($1.source,sr)){
  cerr << "pas possible assignement" << endl;
 }
			}else {
			cerr << " Symbol "+$1.source+" not declared" << endl;
				YYERROR;                         
			}		
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

matrix : '[' {in_matrix++} rows ']' {in_matrix--; $$.source = $3.source ;}
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
                | expr MSPACE { $$.source = $1.source ;}
                |row_with_commas expr ',' { $$.source = "horzcat("+$1.source+","+$2.source+")";}
                |row_with_commas expr MSPACE { $$.source = "horzcat("+$1.source+","+$2.source+")";}
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

for_command : FOR ID '=' expr opt_delimiter  statement_list END {
$$.source  = " double[][] fortemp =" + $4.source +";\n";
$$.source += " for(int posdfo=0;posdfo<fortemp.length;posdfo++){ \n";
$$.source += " for(int sdfgsdfgdf=0;sdfgsdfgdf<fortemp[0].length;sdfgsdfgdf++){ \n";
$$.source += "double[][] "+ $2.source + " = matrixFromDouble(fortemp[posdfo][sdfgsdfgdf]);\n";
$$.source += $6.source;
$$.source += "}\n}\n";
}

if_command : if_block else_if_list else_block END {$$.source =$1.source+$2.source+$3.source;}
;  

if_block : IF expr opt_delimiter statement_list {$$.source = "if(any("+$2.source+")){"+$4.source+"}";}
;

else_if_list: {$$.source ="";}
            | elseif_block else_if_list {$$.source = $1.source + $2.source;}
;

elseif_block : ELSEIF expr opt_delimiter statement_list {$$.source = "else if(any("+$2.source+")){"+$4.source+"}";}
;

else_block : {$$.source ="";}
            |ELSE opt_delimiter statement_list {$$.source = "else{"+$3.source+"}";}
;

while_command: WHILE expr opt_delimiter statement_list END 
{$$.source = "while(any("+$2.source+")){"+$4.source+"}";}
;
 

   
%%
#include "lex.yy.c"

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

}

void writeJavaFile(const string &source, bool ismain){
	
 
	
	
	if(ismain) outfile << "public static void main(String args[]) throws Exception{" << endl;	
	outfile << source << endl;
	
	if(ismain){
	map<string,symrec>::iterator it;
	for (it = tds.begin(); it != tds.end(); it++){
		if ((it->second).idtype == VAR){		
			outfile << "System.out.println(\""+it->first+"=\");"+"\nprintMatrix("+it->first +");"<<endl;
			outfile << "System.out.println();" <<endl;
		}			
	}
	outfile << "}" << endl;
	}
}
void writeJavaFileFooter(){
    	outfile << "}" << endl;	
}


int searchFunction(const string &id){
	int res =0;
	DIR * pdir;
	struct dirent *pdirent;

	string target = id+".m";

	pdir = opendir("./exemples/");

 	if(pdir == NULL){
		cerr << "Le rértoire courant n'a pu être ouvert!" << endl;	
	}

	while((pdirent = readdir(pdir)) != NULL){
		if(target.compare(pdirent->d_name)==0){
			res =1;	
			string path = "./exemples/" + target;
			to_compile.push_back(path);	
		}	
	}

	return res;
}


int main(int argc, const char ** argv){

symrec sri;
sri.idtype = FUNC;

TDSinsert("size",sri);
 int externalfile=0;
 externalfile = argc>1;	
 FILE *fid;

 to_compile.push_back(argv[1]);



	outfile.open("MatCode.java",fstream::out);

	if (!outfile.is_open()){
		cerr << "can't open file" << endl;	
	}

writeJavaFileHeader("MatCode");


cout << "Begin compiling ..." << endl;

 
while(!to_compile.empty()){
	string comp = to_compile.back();
	to_compile.pop_back();
	cout << "Compiling " << comp << endl;
	fid = fopen(comp.c_str(),"r");
	cout << "File opened" << endl; 	
	yyrestart(fid);
 	yyparse();
cout << "File parsed" << endl;
	fclose(fid);
cout << "File closed" << endl;
}
writeJavaFileFooter();
outfile.close();

 return 0;
}

