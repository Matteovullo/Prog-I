#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    protected:
        int x;

    public:
        A(int x) {
            this->x=x;
        }
        virtual int const f()=0;

        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        char b;


    public:
        B(int i, char c) : A(i){
            this->b=c;
        }
        int const f(){
            if(A::x % 2 == 0){
                return ((int)b);
            }else{
                return 2*((int)b);
            }
        }
        B &operator ++(int){
			B aux = *this;
			A::x++;		  
			return *this;
		}   

        ostream &put(ostream &os){
        A::put(os);
        os << ": x=" << x << " b=" << b << " f()=" << f();
        return os;
        }
};

template <class T>
class C : public A{
    private:
        T c;

    public:
        C(int i, T t) : A(i){
            this->c=t;
        }
        int const f(){
            return (int(x)+(int(c)*20));
        }
        T const f(double eps){
            if(typeid(T)==typeid(char)){
                int i=(int)c;
                return (char)(i+1);
            }else{
                return (T)(f()+eps);
            }
        }

        ostream &put(ostream &os){
        A::put(os);
        os << ": x=" << x << " c=" << c << " f()=" << f() << " f(0.03)=" << f(0.03);
        return os;
        }
};

int main(){
    srand(328832748);
    A* vett[DIM];
    for(int i=0; i<DIM; i++){
        int x=1+rand()%100;
        int c='a'+rand()%26;
        switch(rand()%3){
            case 0: vett[i]=new B(x, c); break;
            case 1: vett[i]=new C<double>(x, rand()/(double)RAND_MAX); break;
            case 2: vett[i]=new C<char>(x, c+1);
        }
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    int max=INT_MIN;
    string concat="";
    for(int i=0; i<DIM; i++){
        if(vett[i]->f() > max){
            max=vett[i]->f();
        }
        if(typeid(C<char>)==typeid(*vett[i])){
            concat+=(char)((dynamic_cast<C<char>*>(vett[i]))->f(0.03));
        }
    }

    cout << "punto 1: max=" << max << endl;
    cout << "punto 2: conc=" << concat << endl;

    //PUNTO 3
    cout<< *vett[2]<<endl;	
	B *ptr_b = dynamic_cast<B*>(vett[2]);     
	(*ptr_b)++;
	cout<<*ptr_b<<endl;

    return 0;
}