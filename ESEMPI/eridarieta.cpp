#include <iostream>
using namespace std;

class A{
    public:
        virtual int foo()=0;
};

class B : public A{
    int x;

    public:
        B(int x){
            this->x=x;
        }
        int foo(){
            return x;
        }
};

int main(){
    A* a=new B(10);
    cout << ((B*)a)->foo() << endl;
    cout << static_cast<B*>(a)->foo() << endl;
    B* pp=dynamic_cast<B*>(a);
    if(pp){
        cout << pp->foo() << endl;
    }
    if(typeid(B)==typeid(*a)){
        
        cout << dynamic_cast<B*>(a)->foo() << endl;
    }

}