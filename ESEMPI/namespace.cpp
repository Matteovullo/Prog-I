#include<iostream>
using namespace std;

namespace S{
    class A{
        int x;

        public:
            A(){
                x=0;
            }
    };

    int* foo(int *x){
        (*x)++;
        return x;
    }
}

int main(){
int y=5;
int *x=&y;
using namespace S;
using S::A;
int *ptr=S::foo(x);
cout << *ptr << endl;
}