/*

*/

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int fun(double ***a, int m, int n, short k, double q){
    int c=0;
    int h=0;
    int s=0;
    double somma=0;
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
            if(len == k && somma/(double)len > q) c++;
            h=i+1;
        }
    }
    return c;
}

int main(){
	int m=4;
	int n=2;
	double ***b=new double **[n];
	for(int i=0; i<m; i++){
		b[i]=new double *[n];
		for(int j=0; j<n; j++){
			b[i][j]=new double(2);
		}
	}
	
	cout<<fun(b,4,2,2,1.0);
}
