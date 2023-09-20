#include <iostream>

using namespace std;

int main (){
	/*int x[5] {-1, 7, 0, 6};

cout << x[4]<<endl;*/

/*int x[10] {};

for (int i=10; i>0; i--){
    x[i]=10-i;
    cout<<x[i]<<endl;
}*/

int x[2][2] {};

for (int i=0; i<2; i++)
    for (int j=0; j<2; j++){
        x[i][j] = i*j;
        cout<<x[i][j]<<endl;
    }
}