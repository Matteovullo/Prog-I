#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:
        double *ptr;
        short len;

    public:
        A(short m) {
            this->len=m;
            ptr=new double [len];
            for(int i=0; i<len; i++){
                ptr[i]=rand()/(double)RAND_MAX;
            }
        }
        virtual double f(short i)=0;
        short getLen(){
            return len;
        }

        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        os << ", ptr=";
        for(int i=0; i<getLen(); i++){
            os << get(i) << " ";
        }
        return os;
        }
        double &operator[](short indice){
     		return ptr[indice]; 
    	}

    protected:
        double get(short i){
            return ptr[i%len];
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int p;

    public:
        B(short m, int y) : A(m){
            this->p=y;
        }
        double f(short i){
            double somma=0.0;
            for(int j=i; j>=0; j--){
                somma+=get(j);
            }
            return somma/p;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ", p=" << p << "f(3)=" << f(3) << endl;;
        return os;
        }
};

class C : public A{
    private:
        char x;

    public:
        C(short n, char c) : A(n){
            this->x=c;
        }
        double f(short i){
            double somma=0.0;
            for(int j=0; j<getLen(); j++){
                somma+=get(j);
            }
            return get(i)/somma;
        }
        string g(char c){
            string s="";
            s+=x;
            s+=c;
            return s;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ", x=" << x << ", f(3)=" << f(3) << endl;
        return os;
        }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10);
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int c=0;
    double media=0;
    int count=0;
    string s="";
    for(int i=0; i<DIM; i++){
        media+=vett[i]->f(3);
        c++;
        if(typeid(vett[i])==typeid(C)){
            string l=dynamic_cast<C*>(vett[i])->g('h');
            s+=l;
        }

    }
    cout << "Avg(f(3))=" << media/(double)c << ", concat=" << s;
    cout << endl;

    //PUNTO 3
  	cout<<1<<") "<<*vett[1]<<"\n";
  	(*vett[1])[2]=0.9; 
  	cout<<1<<") "<<*vett[1]<<"\n";

    return 0;
}