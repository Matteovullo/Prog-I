#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:
        int *vec;
        short len;

    public:
        A(short m, int a, int b) {
            this->len=m;
            vec=new int [len];
            for(int i=0; i<len; i++){
                if(a<b)
                    vec[i]=rand()%(b-a+1)+a;
                else
                    vec[i]=rand()%(a-b+1)+b;
            }
        }
        virtual double foo(short a)=0;
        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", vec=[";
        for(int i=0; i<getLen(); i++){
            os << get(i) << " ";
        }
        os << "], ";
        return os;
        }
        short getLen(){
            return len;
        }
        int operator()(int i1, int i2){
            int somma=0;
            for(int i=i1; i<=i2; i++){
                somma+=A::get(i);
            }
            return somma;
        }

    protected:
        int get(short i){
            return vec[i%len];
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int p;

    protected:
        int prod(short s){
            int prodotto=1;
            for(int i=s%getLen(); i<getLen(); i++){
                prodotto*=get(i);
            }
            return prodotto;
        }
    public:
        B(short m, int x, int y) : A(m, x, y){
            this-> p = get(rand() % getLen());
        }
        double foo(short a){
            return prod(a)/(double)p;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << "p=" << p << ", foo(3)=" << foo(3);
        return os;
        }
};

template <class T>
class C : public A{
    private:
        T x;

    public:
        C(short n, int a, int b) : A::A(n, a, b){
            if(typeid(x)==typeid(double))
                this->x=n;
            else                
                this->x = log(1 + (sin(n)*sin(n)));
        }
        T g(T k){
            return 2*x*(k+1);
        }
        double foo(short r){
            return g(r);
        }

        ostream &put(ostream &os){
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
            vett[i] = new B(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 1:
            vett[i] = new C<double>(n, rand() % 5 + 1, rand() % 10 + 5);
            break;
        case 2:
            vett[i] = new C<short>(n, rand() % 5 + 1, rand() % 10 + 5);
        }
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int max=INT_MIN;
    int media=0;
    int c=0;
    for(int i=0; i<DIM; i++){
        if(vett[i]->foo(3) > max){
            max = vett[i]->foo(3);
        }
        if(typeid(vett[i])==typeid(C<double>)){
            c++;
            media+=dynamic_cast<C<double>*>(vett[i])->g(5);
        }
    }

    cout << "Max(foo(3))=" << max << ", Avg(g(5))=" << media/(double)c << endl;;

    //PUNTO 3
    cout << "vett[10]=" << *vett[10] << endl;
    cout << "vett[10](0, 0)=" << (*vett[10])(4, 8) << endl;
    return 0;
}