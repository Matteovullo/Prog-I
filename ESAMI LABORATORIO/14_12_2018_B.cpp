#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class C{
    private:
        float x;

    public:
        C(float x){
            this->x=x;
        }
        virtual double f()=0;
        float getX(){
            return x;
        }
        virtual ostream &put(ostream &os){
        os << x;
        return os;
        }
};

ostream &operator<<(ostream &os, C &obj){
    return obj.put(os);
}


class D : public C{
    private:
        char c;

    public:
        D(float x) : C(x){
            int i=(int)'a';
            this->c=i+1;
        }
        double f(){
            return sin(getX())*sin(getX());
        }
        char getC(){
            return c;
        }
        ostream &put(ostream &os){
        os << c;
        return os;
        }
};

class E : public C{
    private:
        int n;

    public:
        E(float x) : C(x){
            this->n=rand();
        }
        double f(){
            return cos(getX())*cos(getX());
        }
        int getN(){
            return n;
        }
};

class A{
    protected:
        C* obj1;
        C* obj2;

    public:
        A(float x){
            obj1=new D(x);
            obj2=new E(x);
        }
        double g(){
            return (obj1->f())+(obj2->f());
        }
        virtual ostream &put(ostream &os){
        os << "[ ";
        dynamic_cast<D*>(obj1)->put(os);
        os << " ],";
        os << "[ " ;
        dynamic_cast<E*>(obj2)->put(os);
        os << " ],";
        os << " g()=" << g();
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    public:
        B(float x) : A(x){}
        string st(){
            string s="";
            for(int i=0; i<dynamic_cast<E*>(obj2)->getN(); i++){
                s+=dynamic_cast<D*>(obj1)->getC();
            }
            char l[100];
            sprintf(l, "", g());
            string final="";
            int i=0;
            while(l[i] != '0'){
                final+=l[i];
                i++;
            }
            return s+final;
        }
        ostream &put(ostream &os){
        A::put(os);
        os << " st()=" << st();
        return os;
        }
};

int main(){
    srand(11111111);
    A *vett[DIM];
    for (int i = 0; i < DIM; i++){
        if (rand() % 2 == 1)
            vett[i] = new A((float)rand() / INT_MAX);
        else
            vett[i] = new B((float)rand() / INT_MAX);
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int sommatoria=0;
    int sommatoria2=0;
    for(int i=0; i<DIM; i++){
        sommatoria+=vett[i]->g();
        if(typeid(*vett[i])==typeid(B)){
            string s=dynamic_cast<B*>(vett[i])->st();
            for(int j=0; j<s.length(); j++){
                sommatoria2+=(int)(s[i]);
            }
        }
    }

    cout << "sum1=" << sommatoria << endl;
    cout << "sum2=" << sommatoria2 << endl;


}