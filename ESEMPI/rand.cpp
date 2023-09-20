#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    //srand(111222333444);
    srand(time(0));
    for(int i=0; i<10; i++){
        cout << rand() << endl;
    }
}