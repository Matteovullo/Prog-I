/* Memorizzare in un array bidimensionale 10 x 10 dei numeri casuali compresi tra zero e nove, 
stamparne il contenuto e dire quanti zeri sono memorizzati all’interno dell’array*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    double a[10][10];
    int c=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            a[i][j]=rand()% (9-0+1)+0;
            cout << a[i][j] << " ";
            if(a[i][j]==0) c++;
        }
        cout << endl;
    }
    cout << c;
}