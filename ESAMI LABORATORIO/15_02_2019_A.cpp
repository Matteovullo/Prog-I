#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#define DIM 50

using namespace std;

class A {
    private:
        double* w;
        short len;
    
    public:
        A(short m) {
            this->len = m;
            this->w = new double[len];
            for(int i = 0; i < len; i++) {
                w[i] = ((double)rand() / RAND_MAX) * (1 - 0 + 1);
            }
        }

        virtual double const foo(short a) = 0;

        short const getLen() {
            return len;
        }

        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << ", w=[";
            for(short i = 0; i < len; i++) {
                os << w[i] << " ";
            }
            os << "], ";
            return os;
        }

        double& operator[](int i) {
            return w[i % len];
        }

    protected:
        double get(short i) {
            return w[i % len];
        }
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B: public A{
    private:
        int p;

    protected:
        double const sum(short s){
            double somma=0.0;
            for(int i=s; i<A::getLen(); i++){
                somma+=A::get(i);
            }
            return somma;
        }
    public:
        B(short m, int x): A::A(m){
            p=x;
        }
        double const foo(short a){
            return sum(a)/p;
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "p=" << p << ", foo(3)=" << foo(3);
            return os;
        }
};

template <class T>
class C: public A{
    private:
        T x;

    public:
        C(short n): A::A(n){
            if(typeid(n)==typeid(short))
                x=n;
            else
                x=log(1+pow(sin(n), 2));
        }
        T const g(T k){
            return 2*x*(k+1);
        }
        double const foo(short r){
            return g(r);
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "x=" << x << ", foo(3)=" << foo(3);
            return os;
        }
};

int main(){
    srand(111222333);
    A* vett[DIM];
    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 10 + 1);
            break;
        case 1:
            vett[i] = new C<double>(n);
            break;
        case 2:
            vett[i] = new C<short>(n);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << endl << "PUNTO 2" << endl;
    double max = -1;
    double somma_g = 0;
    int count = 0;
    for(int i = 0; i < DIM; i++) {
        if(vett[i]->foo(3) > max) max = vett[i]->foo(3);
        if(typeid(*vett[i]) == typeid(C<double>)) {
            somma_g += (dynamic_cast<C<double>*>(vett[i]))->g(5);
            count++;
        }
    }
    cout << "Max = " << max << ", " << "avg = " << somma_g/count;

    //PUNTO 3
    cout << endl << *vett[0] << endl;
    cout << "Index=4, newValue=-1" << endl;
    (*vett[0])[4]=-1; 
  	cout <<*vett[0];
}