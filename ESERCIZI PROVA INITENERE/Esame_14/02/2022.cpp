#include <iostream>
using namespace std;

int fun(double ***a, int m, int n; short k; double q){
    int c=0;
    int h=0;
    int s=0;
    double sommma=0;
    int len=0;
    for(int i=0; i<=m-n; i++){
        h=0;
        for(int j=0;j<n; j++){
            s=j;
            somma=0;
            len=0;
            for(int l=j; l<k; l++){
                if(a[h][s]){
                    somma+=*a[h][s];
                    len++;
                }
                h++;
                s++;
            }
            if(somma/len > q) c++;
            h=i+1;
            s=j+1;
        }
    }
}