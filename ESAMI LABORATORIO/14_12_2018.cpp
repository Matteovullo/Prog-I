#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#define DIM 50

using namespace std;

class A{
    protected:
        double* ptr;
        short len;

    public:
        A(short n){
            this->len=n;
            ptr=new double[len];
            for(int i=0; i<len; i++){
                ptr[i]=0 + ((double)rand() / RAND_MAX) * (1 - 0 + 1);
            }
        }
        virtual double const foo(short a)=0;
        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << ", ptr=[";
            for(short i = 0; i < len; i++) {
                os << ptr[i] << " ";
            }
            os << "], ";
            return os;
        }
        double &operator[](short indice){
     		return ptr[indice]; 
    	}
};

ostream& operator<<(ostream& os, A& obj) {
    return obj.put(os);
}

class B: public A{
    private:
        double alpha;
        double extract(short s){
            return ptr[s%len]/alpha;
        }

    public:
        B(short m, double d): A::A(m){
            alpha=d;
        }
        double const foo(short b){
            return log(1+extract(b));
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "alpha=" << alpha << ", foo(3)=" << foo(3);
            return os;
        }
};

template <class T>
class C: public A{
    private:
        T x;

    public:
        C(short n): A::A(n){
            if(typeid(x)==typeid(short))
                x=g(n);
            else
                log(1+n);
        }
        double const foo(short r){
            return g(r*x);
        }
        T const g(T k){
            return 3*k;
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "x=" << x << ", foo(3)=" << foo(3) << ", g(5)=" << g(5);
            return os;
        }
};

int main(){
    srand(328832748);

    A* vett[DIM];
    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 5;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, n / 100.0);
            break;
        case 1:
            vett[i] = new C<double>(n);
            break;
        case 2:
            vett[i] = new C<int>(n);
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
    for(int i = 0; i < DIM; i++){
        if(vett[i]->foo(5) > max) max = vett[i]->foo(5);
        if(typeid(*vett[i]) == typeid(C<double>)) {
            somma_g += ((C<double>*)vett[i])->g(5);
            count++;
        }
    }
    cout << "Max = " << max << ", " << "avg = " << somma_g/count;

    //PUNTO 3
    cout << endl << *vett[10] << endl;
    cout << "(*vett[10])[0] = " << (*vett[10])[0] << endl;
    cout << "(*vett[10])[1] = " << (*vett[10])[1] << endl;
}