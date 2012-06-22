/* 
 * File:   tds.h
 * Author: rvlander
 *
 * Created on 22 juin 2012, 13:26
 */



#ifndef TDS_H
#define	TDS_H

#include<string>
using namespace std;



enum IDType {FUNC,VAR};

struct symrec {
	IDType idtype;
	string source;
};

bool TDSget(string symbol, symrec * out);
bool TDSinsert(string symbol, symrec sr);
int TDSremove(string symbol);






#endif	/* TDS_H */

