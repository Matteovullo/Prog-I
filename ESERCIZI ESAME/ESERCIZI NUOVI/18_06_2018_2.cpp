#include <iostream>

using namespace std;

int fun(string *A, int n){
    string max=A[0];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(A[j].length() > max.length()){
                max=A[j];
            }
        }
    }
    int e;
    int f=0;
    for(int i=0; i<n; i++){
        string s=A[i];
        if(s.length() == max.length()){
            for(int h=0; h<s.length(); h++){
                char c=s[h];
                for(int j=0; j<max.length(); j++){
                    if(c == max[j]){
                        e++;
                    }
                    if(c == '?' && max[j] == '?'){
                        e++;
                    }
                    if(c == '?' && max[j] != '?'){
                        e++;
                    }
                    if(c != '?' && max[j] == '?'){
                        e++;
                    }
                }
            }
        }
        if(e == max.length())
            f++;
    }

    return f;
}

int main(){
    string *A=new string [3];
    A[0]="ciao";
    A[1]="c??ossdsvtb";
    A[2]="a";

    cout << fun(A, 3);
}