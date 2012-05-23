CPP = g++


all : compile lmsrj
	
lmsrj : lmsrj.cpp
	${CPP} $^ -o $@

compile : mc.tab.c lex.yy.c tds.cpp
	${CPP} mc.tab.c -o $@

mc.tab.c : mc.y
	bison mc.y --report=state

lex.yy.c : mc.lex
	flex mc.lex

clean:
	rm mc.tab.c lex.yy.c

clear : clean
	rm compile 
