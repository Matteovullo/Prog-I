#include <iostream>
using namespace std;

class A{
    private:
        int x;

    public:
        A(){
            x=0;
        }
        A(int x){
            this->x=x;
        }
        A(A& obj) : x(obj.x){}
};

int main(){
    A obj;
    A obj2(10);
    obj=obj2;
    A obj3=obj;
    A pbj4(obj);
}