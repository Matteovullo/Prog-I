#include <iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        A(int x) {this->x=x;}
        virtual void f(){
            cout << "ddr" << endl;
        }
};

class B{
    private:
        //static int y;
    public:
        B(){}
        static int f(){
            int g=5;
            return g;
        }
};

//int B::y=0;

int main(){
    /*int x=5;
    int &ref=x;

    cout << &x << " " << &ref << endl;
    cout << x << " " << ref << endl;
    ref++;
    cout << &x << " " << &ref << endl;
    cout << x << " " << ref << endl;*/

    B b;
}