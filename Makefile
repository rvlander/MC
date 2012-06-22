PROJECT_DIR = /home/rvlander/MC
CPP = g++
OBJ_DIR=build


all : compile lmsrj
	
lmsrj : lmsrj.cpp
	${CPP} $^ -o $@

compile : ${OBJ_DIR}/mc.tab.c ${OBJ_DIR}/lex.yy.c tds.cpp
	${CPP} -I${PROJECT_DIR}  ${OBJ_DIR}/mc.tab.c -o $@

${OBJ_DIR}/mc.tab.c : mc.y
	bison mc.y --report=state --report-file=logs/mc.output -o $@

${OBJ_DIR}/lex.yy.c : mc.lex
	flex mc.lex
	mv lex.yy.c ${OBJ_DIR}

clean:
	rm ${OBJ_DIR}/mc.tab.c ${OBJ_DIR}/lex.yy.c
	rm compile
	rm lmsrj
	
