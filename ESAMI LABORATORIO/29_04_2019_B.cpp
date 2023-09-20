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
                vec[i]=rand()%(b-a+1)+a;
            }
        }
        virtual double foo(short a)=0;
        short getLen(){
            return len;
        }
        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", vec=[";
        for(int i=0; i<getLen(); i++){
            os << get(i) << " ";
        }
        os << "], ";
        return os;
        }
        int &operator[](short indice){
     		return vec[indice]; 
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
        B(short m, int a, int b) : A(m, a, b){
            this->p=get(rand()%(getLen()-0+1)+0);
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
        C(short n, int a, int b) : A(n, a, b){
            if(typeid(n)==typeid(double)){
                this->x=n;
            }else{
                this->x=log(1+(pow(sin(n), 2)));
            }
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
    int c=0;
    int media=0;
    int max=INT_MIN;
    for(int i=0; i<DIM; i++){
        if(vett[i]->foo(3) > max){
            max=vett[i]->foo(3);
        }
        if(typeid(vett[i])==typeid(C<double>)){
            media+=dynamic_cast<C<double>*>(vett[i])->g(5);
            c++;
        }
    }

    cout << "max= " << max << ", Avg(g(5))=" << media/(double)c;

    //PUNTO 3
    cout<<1<<") "<<*vett[1]<<"\n";
  	(*vett[1])[2]=2; 
  	cout<<1<<") "<<*vett[1]<<"\n";
    return 0;
}