#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <typeinfo>
#include <string>
#define DIM 50

using namespace std;

class A{
    private:
        double *vec;
        short len;
    
    public:
        A(short w, double a, double b){
            len=w;
            vec=new double[len];
            for(int i=0; i<len; i++){
                vec[i] = a + ((double)rand() / RAND_MAX) * (b - a + 1);
            }
        }
        virtual double foo(short a)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", vec=[";
            for(short i = 0; i < len; i++) {
                os << vec[i] << " ";
            }
            os << "], ";
            return os;
        }
        double &operator[](int i) {
            return vec[i%len];
         }

    protected:
        double get(short i){
            return vec[i%len];
        }
};

ostream& operator<<(ostream& os,A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int p;

    protected:
        double prod(short s, double v){
            int somma=0;
            for(int i=s; i<A::getLen(); i++){
                somma+= A::get(i);
            }
            return somma*v;
        }

    public:
        B(short m, short x, short y): A::A(m, x, y){
            int x_1=10*x;
            int y_1=100*y;
            p=rand()%(y_1-x_1+1)+x_1;
        }
        double foo(short a){
            return log(prod(a, a/2.0));
        }
        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "p=" << p << ", foo(3)=" << foo(3);
            return os;
        }

};

template<class T>
class C : public A {
    private:
        T y;

    public:
        C(short n, double x, double y) : A(n, x, y) {
            if(typeid(T) == typeid(short)) {
                this->y = n;
            }
            else {
                this->y = 1 + pow(cos(n), 2);
                //this->y = 1 + cos(n) * cos(n);
            }
        }

        double g(double k) {
            return 2.0*y*(k + 1);
        }

        double foo(short r) {
            return g(r);
        }

        virtual ostream& put(ostream& os) {
            A::put(os);
            os << "y=" << y << ", foo(3)=" << foo(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for(int i=0; i<DIM; i++) {
	    short n=5+rand()%5;
	    switch(rand()%3) {
	    case 0: 
	    vett[i]= new B(n, rand()%5 + 1, rand()%10 + 5);
	    break;
	    case 1:
	    vett[i]= new C<double>(n, rand()%5 + 1, rand()%10 + 5);
	    break;
	    case 2: 
	    vett[i]= new C<short>(n, rand()%5 + 1, rand()%10 + 5);
	    }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    cout << endl << "PUNTO 2" << endl;
    double max = -1;
    double somma_g = 0;
    int count = 0;
    for(int i = 0; i < DIM; i++) {
        if(vett[i]->foo(3) > max) max = vett[i]->foo(3);
        if(typeid(*vett[i]) == typeid(C<double>)) {
            somma_g += ((C<double>*)vett[i])->g(0.5);
            count++;
        }
    }
    cout << "Max = " << max << ", " << "avg = " << somma_g/count;

    cout << "PUNTO 3" << endl;
    cout << endl << *vett[10] << endl;
    cout << "(*vett[10])[0] = " << (*vett[10])[0] << endl;
    (*vett[10])[0] = 4.5;
    cout << "(*vett[10])[0] = " << (*vett[10])[0] << endl;

}