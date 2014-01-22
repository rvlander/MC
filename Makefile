PROJECT_DIR = `pwd`
CPP = g++
OBJ_DIR=build
SRC=tds.cpp main.cpp


all : compile lmsrj
	
lmsrj : lmsrj.cpp
	${CPP} $^ -o $@

compile : ${OBJ_DIR}/mc.tab.c ${OBJ_DIR}/lex.yy.c ${SRC}
	${CPP} -I${PROJECT_DIR}  ${OBJ_DIR}/mc.tab.c ${SRC} -o $@

${OBJ_DIR}/mc.tab.c : mc.y
	bison mc.y --report=state --report-file=logs/mc.output -o $@

${OBJ_DIR}/lex.yy.c : mc.lex
	flex -o ${OBJ_DIR}/lex.yy.c mc.lex

clean:
	rm ${OBJ_DIR}/mc.tab.c ${OBJ_DIR}/lex.yy.c
	rm compile
	rm lmsrj
	
