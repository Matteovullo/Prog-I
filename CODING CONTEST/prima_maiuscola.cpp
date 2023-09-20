#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void fun(string a, string b, string c){

    if(a.empty() != 1)
        a[0]=(char)isupper(a[0]);

    if(b.empty() != 1)
        b[0]=(char)isupper(b[0]);

    if(c.empty() != 1)
        c[0]=(char)isupper(c[0]);

    cout << a << " " << b << " " << c << endl;
    
}

int main(){
    string a="ottone";
    string b="agrippa"; 
    string c="emidio";

    fun(a,b,c);
}