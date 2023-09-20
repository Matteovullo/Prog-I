#include <iostream>
using namespace std;

int main(){
    int **x=new int*[4];
    for(int i=0; i<4; i++) x[i]=new int(i);
    cout << x << endl;
    cout << *(*x) << endl;
    cout << *(*(x+1)) << endl;

    int *y[3];
    for(int i=0; i<3; i++) y[i]=&i;
    cout << *y << endl;
    cout << *(*y+1) << endl;

    int v[5]={0, 1, 2, 3, 4};
    for(int i: v){
        cout << i << endl;
    }

    for(int i=0; i<5; i++){
        if(i%2==0) continue;
        cout << v[i] << endl;
    }

    for(int i=0; i<5; i++){
        if(i==3) break;
        cout << v[i] << endl;
    }
    
    int i=0;
    etichetta:
        cout << v[i] << endl;
        i++;
        if(i<5) goto etichetta;

    int h=5;
    switch (h){
        case 5:
            cout << "è 5" << endl;
    }

    
}