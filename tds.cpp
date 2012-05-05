/*#include<map>
#include<iostream>
#include<string>
using namespace std;*/

enum IDType {FUNC,VAR};

struct symrec {
	IDType idtype;
	string source;
};

map<string,symrec> tds;

bool TDSget(string symbol, symrec * out){ 
	map<string,symrec>::iterator it;
	it = tds.find(symbol);
	bool res = it != tds.end();	
	if(res)
		*out = it->second;
	return res;
}

bool TDSinsert(string symbol, symrec sr){
	pair<map<string,symrec>::iterator,bool> ret;
	ret = tds.insert(pair<string,symrec>(symbol,sr));
	return ret.second;
}

int TDSremove(string symbol){
	int ret;
	ret = tds.erase(symbol);
	return ret;
}

/*int main(){
	symrec sr,sr1;	
	bool sm = TDSget("toto",&sr);
	if(!sm){
		cout << "toto not found endl" << endl;	
	}

	sr.source = "vasyfranky";
	TDSinsert("toto",sr);
	sm = TDSget("toto",&sr1);
	if(!sm){
		cout << "toto not found endl" << endl;	
	}else {
		cout << "toto contains :" + sr1.source << endl;
	}
TDSinsert("toto",sr);

}*/
