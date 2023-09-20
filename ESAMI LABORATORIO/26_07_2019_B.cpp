#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <cmath>
#define DIM 50

using namespace std;

class A{
    private:
        int *vec;
        short len;

    public:
        A(short m, int a, int b){
            len=m;
            vec=new int[len];
            for(int i=0; i<len; i++){
                if(b>a)
                    vec[i]=rand()%(b-a+1)+a;
                else
                    vec[i]=rand()&(a-b+1)+b;
            }
        }
        virtual double foo(short a)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", vec=[";
            for(int i=0; i<A::getLen(); i++){
                os << vec[i] << " ";
            }
            os << "], ";
            return os;
        }
        int operator()(int i1, int i2){
            int somma=0;
            for(int i=i1; i<=i2; i++){
                somma+=vec[i];
            }
            return somma;
        }

        protected:
            int get(short i){
                return vec[i%len];
            }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int p;

    protected:
        int prod(short s){
            int prodotto;
            for(int i=s; i<A::getLen(); i++){
                prodotto*=A::get(i);
            }
            return prodotto;
        }
    public:
        B(short m, int x, int y): A::A(m, x, y){
            p=get(rand()%A::getLen());
        }
        double foo(short a){
            return prod(a)/(double)(p);
        }
        virtual ostream& put(ostream& os){
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
        C(short n, int a, int b): A(n, a, b){
            if(typeid(x)==typeid(short))
                x=n;
            else
                x=log(1+pow(sin(n), 2));
        }
        T g(T k){
            return 2*x*(k+1);
        }
        double foo(short r){
            return g(r);
        }
        virtual ostream& put(ostream& os){
            A::put(os);
            os << "x=" << x << ", foo(3)=" << foo(3); 
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        switch (rand() % 3){
        case 0:
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    int max=INT_MIN;
    int media=0;
    int count=0;
    for(int i=0; i<DIM; i++){
        if(vett[i]->foo(3) > max) max=vett[i]->foo(3);
        if(typeid(C<double>) == typeid(*vett[i])){
            //media+=(dynamic_cast<(C<double*>)>(vett[i]))->g(5);
            media += ((C<double>*)(vett[i]))->g(5);
            count++;
        }
    }
    cout << "Max= " << max << ", Avg=" << media/(double)count << endl;
    
    cout << "PUNTO 3" << endl;
    cout << "vett[10]=" << *vett[10] << endl;
    cout << "vett[10](4, 8)=" << (*vett[10])(4, 8) << endl;

}