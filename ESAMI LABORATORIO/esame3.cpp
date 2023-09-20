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

class D{
    private:
        double z;

    public:
        D(double z){
            this->z=z;
        }
        double getZ(){
            return z;
        }
};

class A{
    protected:
        int x;

    public:
        A(int x) {
            this->x=x;
        }
        virtual int f()=0;
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    protected:
        int y;
        D d;

    public:
        B(int x, int y, double z) : A(x){
            d=D(z);
            this->y=y;
        }
        int f(){
            return x*x;
        }
        int f(D obj){
            return obj.getZ()+d.getZ();
        }
        ostream &put(ostream &os){
        A::put(os);
        return os;
        }
};

class C : public B{
    public:
        C(int x, int y, double z) : B(x, y, z){}
        int f(){
            return 7*y;
        }
        ostream &put(ostream &os){
        A::put(os);
        return os;
        }
};

int main(){
    
    Random r = new Random(6353433);
    A[] vett = new A[100];
    for (int i = 0; i < vett.length; i++){
        int x = r.nextInt(10);
        int y = r.nextInt(100);
        int z = r.nextInt(30);
        if (r.nextInt(2) == 1)
            vett[i] = new B(x, y, z);
        else
            vett[i] = new C(x, y, z);
    }
    return 0;
}