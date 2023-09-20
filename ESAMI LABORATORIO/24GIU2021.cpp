#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>

using namespace std;

#define DIM 50

class A
{
private:
    double *vec;
    short len;

public:
    A(short m, int a, int b)
    {
        this->len = m;
        vec = new double[len];
        srand(time(0));
        for (int i = 0; i < m; i++)
        {
            if (a < b)
                vec[i] = rand() % (b - a + 1) + a;
            else
                vec[i] = rand() % (a - b + 1) + b;
        }
    }
    short getLen()
    {
        return len;
    }
    virtual double foo(short a) = 0;

    virtual ostream& put(ostream& os) = 0;

    int operator()(int i1, int i2){
        int somma=0;
        for(int i=i1; i<=i2; i++){
            somma+=vec[i];
        }
        return somma;
    }

protected:
    int get(short i)
    {
        return vec[i % len];
    }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B : public A
{
private:
    int p;

protected:
    int prod(short s)
    {
        int prodotto = 1;
        for (int i = s; i < getLen(); i++)
        {
            prodotto *= get(i);
        }
        return prodotto;
    }

public:
    B(short m, int x, int y) : A(m, x, y)
    {
        p = get(rand() % getLen());
    }
    double foo(short a)
    {
        return prod(a) / (double)p;
    }

    ostream& put(ostream& os){
        os << typeid(B).name() << "; vec=[";
        for(int i=0; i<getLen(); i++){
            os << get(i) << " ";
        }
        os << "], p=" << p << ", foo(3)=" << foo(3);
        return os;
    }
};

template <typename T>
class C : public A
{
private:
    T x;

public:
    C(short n, int a, int b) : A(n, a, b)
    {
        if (typeid(x) == typeid(short))
            x = n;
        else
            x = log(1 + pow(sin(n), 2));
    }
    T g(T k)
    {
        return 2 * x * (k + 1);
    }
    double foo(short r)
    {
        return g(r);
    }

    ostream& put(ostream& os){
        os << typeid(C<T>).name() << "; vec=[";
        for(int i=0; i<getLen(); i++){
            os << get(i) << " ";
        }
        os << "], p=" << x << ", foo(3)=" << foo(3);
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

    //PUNTO 1
    for(int i=0; i<DIM; i++){
        cout<< *vett[i] << endl;
    }

    //PUNTO 2
    double max=INT_MIN;
    double media=0;
    int count=0;
    for(int i=0; i<DIM; i++){
        if(max < vett[i]->foo(3)){
            max=vett[i]->foo(3);
        }
        if(typeid(C<double>)==typeid(*vett[i])){
            media=((C<double>*)(vett[i]))->g(5);
            count++;
        }
    }
    cout<< "Max= " << max << ", Avg= " << media/count << endl;

    //PUNTO 3
    cout<< "vett[10]=" << *vett[10] << endl;
    cout<< "vett[10](4, 8)=" << (*vett[10])(4, 8) << endl;
}