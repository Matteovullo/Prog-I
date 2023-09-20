#include <iostream>
#include <cmath>
#include <climits>
#include <typeinfo>
#include <cstdlib>
#define DIM 50

using namespace std;

class A{
    private:
        double *arr;
        short len;

    public:
        A(short m){
            len=m;
            arr=new double[len];
            for(int i=0; i<len; i++){
                arr[i]=0 + ((double)rand() / RAND_MAX) * (1 - 0 + 1);
            }
        }
        virtual double f(short a)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", arr=[";
            for(int i=0; i<len; i++){
                os << arr[i] << " ";
            }
            os << "]";
            return os;
        }
        int operator()(int i1, int i2){
            int somma=0;
            for(int i=i1; i<=i2; i++){
                somma+=A::get(i);
            }
            return somma;
        }

    protected:
        double get(short i){
            return arr[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        double p;

    protected:
        double foo(short s, int k){
            double somma=0.0;
            for(int i=s%A::getLen(); i<A::getLen(); i++){
                somma+=A::get(i);
            }
            return k*somma;
        }

    public:
        B(short m): A::A(m){
            int media=0;
            for(int i=0; i<A::getLen(); i++){
                media+=A::get(i);
            }
            p=media/(double)A::getLen();
        }
        double f(short a){
            return (log(foo(a, (2*a))))/p;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", p=" << p << ", f(3)=" << f(3);
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
                x=log(1+(sin(n)*sin(n)));
        }
        T g(T k){
            return 2*x*(k+1);
        }
        double f(short r){
            return g(r);
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", x=" << x << ", f(3)=" << f(3);
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
            vett[i] = new B(n);
            break;
        case 1:
            vett[i] = new C<double>(n);
            break;
        case 2:
            vett[i] = new C<short>(n);
        }
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "Punto II: " << endl;
	int max=INT_MIN;
	int somma=0;
    int c=0;
	
	for(int i=0;i<DIM;i++){
        if((vett[i])->f(3) > max) max=(vett[i])->f(3);
		if(typeid(*vett[i])==typeid(C<double>)){
			somma+=(dynamic_cast<C<double>*>(vett[i]))->g(5);
            c++;
		}
	}

    cout << "Max= " << max << ", avg=" << somma/(double)c; 

    cout << "PUNTO 3" << endl;
    cout << "vett[10]=" << *vett[10] << endl;
    cout << "vett[10](0, 0)=" << (*vett[10])(0, 0) << endl;
}