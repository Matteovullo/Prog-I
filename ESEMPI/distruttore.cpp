#include <iostream>
using namespace std;

class A{
    int **x;
    int n;

    public:
        A(int n){
            this->n=n;
            x=new int*[n];
            for(int i=0; i<n; i++){
                x[i]=new int[n];
                for(int j=0; j<n; j++){
                    x[i][j]=i;
                }
            }
        }
        ~A(){
            for(int i=0; i<n; i++){
                delete[] x[i];
            }
            delete[] x;
        }
};

class B{
    int *x;

    public:
        B(){
            *x=0;
        }
        ~B(){
            delete x;
        }
};

int main(){
    A *a=new A(10);
    delete a;

    B* b=new B();
    delete b;
}