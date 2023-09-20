#include <iostream>
#include <string>

using namespace std;

string fun(string a, string b, string c, int N){
    int c=0;

    if(a.empty() != true && b.empty() != true && c.empty() != true){
    for(int i=0; i<N; i++){
        if(a[i] != b[i] || a[i] != b[i] || b[i] != c[i])
            return -1;
        else
            c++;
    }
    if(c==N)
        string h=a;
        string o=b;
    }

        return 
    }
}