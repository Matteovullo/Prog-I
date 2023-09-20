#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 50

using namespace std;

class A{
    private:


    public:
        A() {}

        virtual ostream &put(ostream &os){
        os << typeid(*this).name(); //...

        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:


    public:
        B() {}

        ostream &put(ostream &os){
        A::put(os);

        //...

        return os;
        }
};

class C : public A{
    private:


    public:
        C() {}

        ostream &put(ostream &os){
        A::put(os);

        //...

        return os;
        }
};

int main(){
    return 0;
}