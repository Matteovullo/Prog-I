#include <iostream>
using namespace std;

class A{
    int x;

    public:
        A(){
            x=0;
        }
        A(int x){
            this->x=x;
        }
        friend ostream& operator<<(ostream& os, A& obj);
        friend A operator-(A obj1, A obj2);
        A operator+(A obj){
            return A(obj.x+x);
        }
        A &operator++(){
            x++;
            return *this;
        }
        A operator++(int){
            A a=*this;
            x++;
            return a;
        }
        friend A& operator--(A&);
        friend A operator--(A&, int);
        A operator=(A& obj){
            x=obj.x;
            return *this;
        }
};

class B{
    double x;

    private:
        B(int x){
            this->x=x;
        }
        operator A(){
            return A((int)x);
        }
};

ostream& operator<<(ostream& os, A& obj){
    os << "x=" << obj.x << endl;;
}

A operator-(A obj1, A obj2){
    return A(obj1.x-obj2.x);
}

A &operator--(A& obj){
    obj.x--;
    return obj;
}

A operator--(A& obj, int){
    A a=obj;
    obj.x--;
    return a;
}