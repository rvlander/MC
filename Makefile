CPP = g++


all : compile

compile : mc.tab.c lex.yy.c
	${CPP} mc.tab.c -o compile

mc.tab.c : mc.y
	bison mc.y --report=state

lex.yy.c : mc.lex
	flex mc.lex

clean:
	rm mc.tab.c lex.yy.c

clear : clean
	rm compile 
