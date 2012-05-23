/* 
 * File:   lmsrj.cpp
 * Author: rvlander
 *
 * Created on 23 mai 2012, 10:57
 */

#include<string>
#include<iostream>
#include<fstream>
#include<vector> 

using namespace std;

/*
 * 
 */

void readMFile(char * path) {
    ifstream fp(path);
    char ligne[1024];
    string ll,lcmd;
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

    
    while(fp.getline(ligne,1024)){
       ll = ligne;
       cout << ligne <<endl;
    }
    
    lcmd = args[0];
    for (int i = 1; i < args.size(); i++) {
        lcmd+=","+args[i];
    }

    string spath(path);
    lcmd = "exportVar('"+spath+".java.in'," +lcmd+");";
    cout << lcmd << endl;
}

int main(int argc, char** argv) {
    char* mscript = argv[1];

    readMFile(mscript);

    return 0;
}

