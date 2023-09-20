#include<iostream>
#include<cstdarg>
#include<string>

using namespace std;

string concat(int nCount, ...) {
    string out = "";

    va_list list;
    va_start(list, nCount);

    for(int i=0; i<nCount; i++) {
        out += va_arg(list, char*);
    }
    
    va_end(list);
    return out;
}

int sum(int nCount, ...) {
    int s=0;

    va_list list;
    va_start(list, nCount);

    //cout << "nCount: " << nCount << endl;
    

    for(int i=0; i<nCount; i++) {
        s+=va_arg(list, int);
    }

    va_end(list);

    return s;
}

int main() {
    cout << sum(2, 1,3) << endl;
    cout << sum(5, 4, 5, 1, -1 , 0) << endl;

    cout << concat(3, "Hello", " ", "World");
}