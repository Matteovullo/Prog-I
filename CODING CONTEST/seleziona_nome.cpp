#include <iostream>

using namespace std;

string fun(string a, string b, string c, char A, char B){
    string c="";
    string d="";
    string f="";
    char final=a.substr(a.length()-1, 1);
    char start=a.substr(a.length()-1, 1);
    if(start == A || final == A && t != B || a.substr(0,1) != B){
        c=a;
    }

    if(b.substr(a.length()-1, 1) == A || b.substr(0,1) == A && b.substr(a.length()-1, 1) == B || b.substr(0,1) == B){
        d=b;
    }

    if((c.substr(a.length()-1, 1) == A || c.substr(0,1) == A) && (c.substr(a.length()-1, 1) == B || c.substr(0,1) == B)){
        f=c;
    }


}