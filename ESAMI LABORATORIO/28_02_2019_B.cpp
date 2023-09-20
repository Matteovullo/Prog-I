#include <iostream>
#include <climits>
#include <string>
#include <cstdlib>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:
        char *ptr;
        short len;

    public:
        A(short m, char c){
            len=m;
            ptr=new char[len];
            for(int i=0; i<len; i++){
                if('a' > c)
                    ptr[i]=rand()%('a'- c +1)+c;
                else
                    ptr[i]=rand()%(c- 'a' +1)+'a';
            }
        }
        virtual string elab(short a, char c)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << " ptr=[";
            for(int i = 0; i < len; i++)
            os << ptr[i] << "";
            os << "]";
            return os;
        }
	    char &operator[](short indice){
     		return ptr[indice]; 
    	}

    protected:
        char get(short i){
            return ptr[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        double x;

    public:
        B(short m, char c, int y): A::A(m, c){
            x=y;
        }
        double foo(short s){
            return (sin(x+s))/(log(x+s));
        }
        string elab(short a, char c){
            string s="";
            for(int i=0; i<A::getLen(); i++){
                if(abs(A::get(i)-x) <= a)
                    s+=A::get(i);
            }
            return s;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", x=" << x << ", elab(5, z)=" << elab(5, 'z');
            return os;
        }
};

template <class T>
class C: public A{
    private:
        T y;

    public:
        C(short n, double k, char c) : A(n, c){
            if(typeid(y) == typeid(short))
                y=round(100*k);
            else
                y=k;
        }
        string elab(short a, char c){
            string s="";
            if(A::getLen() >= a){
                for(int i=0; i<a; i++){
                    s+=c;
                }
            }else{
                for(int i=0; i<A::getLen(); i++){
                    s+=A::get(i);
                }
            }
            return s;
        }
        double g(short w){
            return sin(w+y);
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", y=" << y ;
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
            vett[i] = new B(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 1:
            vett[i] = new C<double>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
            break;
        case 2:
            vett[i] = new C<short>(n, (double)rand() / RAND_MAX, rand() % ('z' - 'a' + 1) + 'a');
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "Punto 2 " << endl;
	int media1=0, media2=0, c1=0, c2=0;
	
	for(int i=0;i<DIM;i++){
        if(typeid(*vett[i])==typeid(B)){
			media1+=(dynamic_cast<B*>(vett[i]))->foo(5);
		}
        if(typeid(*vett[i])==typeid(C<short>)){
			media2+=(dynamic_cast<C<short>*>(vett[i]))->g(5);
		}
	}

    cout << "Avg(foo(5))=" << media1/(double)c1 << endl;
    cout << "Avg(g(5))=" << media2/(double)c2 << endl;
    
    cout << "PUNTO 3"<<endl;
  	cout << "*vett[0]: " << *vett[1] << endl;
  	(*vett[1])[0]=0.9; 
  	cout << *vett[1]; 
}