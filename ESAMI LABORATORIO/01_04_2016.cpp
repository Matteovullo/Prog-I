#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 30

using namespace std;

class Mydouble{
    private:
        double x;

    public:
        Mydouble(float _x) : x(_x){}
        int trunc(){
            return x;
        }
        Mydouble operator^(Mydouble &op){
            return Mydouble(pow(x, op.x));
        }
        bool operator>(Mydouble &op){
            return x>op.x;
        }
        ostream &put(ostream &os) const{
            os << x;
            return os;
        }
};

ostream &operator<<(ostream &os,const Mydouble &obj){
    return obj.put(os);
}

class A{
    private:
        float w;

    protected:
        static int const dim=4;
        Mydouble *mat[dim][dim];

    public:
        A(double _w) : w(_w) {
            for(int i=0; i<dim; i++){
                for(int j=0; j<dim; j++){
                    mat[i][j]=new Mydouble((w*10)+i+j);
                }
            }
        }
        virtual double f() const=0;
        virtual ostream &put(ostream &os) {
        os << typeid(*this).name();
        os << " w=" << w;
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    public:
        B(double _w) : A(_w) {}
        double f() const{
            int somma=0;
            for(int i=0; i<dim; i++){
                somma+=mat[0][i]->trunc();
            }
            return somma;
        }
        ostream &put(ostream &os) {
        A::put(os);
        os << " f()=" << f();
        return os;
        }
};

template <class T>
class C : public A{
    private:
        T c;

    public:
        C(double _w, T _c) : A(_w){
            this->c=_c;
        }
        double f() const{
            int c=0;
            Mydouble a(5.0);
            for(int i=0; i<dim; i++){
                for(int j=0; j<dim; j++){
                    if(*mat[i][j] > a){
                        c++;
                    }
                }
            }
            return c;
        }
        Mydouble f(T p){
            if(typeid(p)==typeid(double)){
                return Mydouble(p);
            }else{
                return (*mat[0][0])^(*mat[dim-1][dim-1]);
            }
        }
        ostream &put(ostream &os){
        A::put(os);
        os <<" c=" << c << " f()=" << f() << "f(3)=" << f(3);
        return os;
        }
};

int main(){
    srand(328832748);
    A* vett[DIM];
	for(int i=0; i<DIM; i++){
		double x=rand()/(double)RAND_MAX;
        
		rand();
		switch(rand()%3) {
			case 0: vett[i] = new B(x);
					break;
			case 1: vett[i] = new C<double>(x,rand()/(double)RAND_MAX);
					break;
			case 2: vett[i] = new C<int>(x,(int)(x*10));
		}
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    double somma=0.0;
    for(int i=0; i<DIM; i++){
        somma+=vett[i]->f();
    }
    cout << "punto 1:sum=" << somma << endl;

    //PUNTO 3
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i])==typeid(C<int>)){
            Mydouble j=dynamic_cast<C<int>*>(vett[i])->f(3);
            cout << "punto 2: f(3)=" << j << " di indice " << i << endl;
            break;
        }
    }

    return 0;
}