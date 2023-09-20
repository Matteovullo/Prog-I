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
        char *base;
        short len;

    public:
        A(short m){
            len=m;
            base=new char[len];
            for(int i=0; i<len; i++){
                base[i]=rand()%('z'- 'a' +1)+'a';
            }
        }
        virtual string extract(short x)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os) {
            os << typeid(*this).name() << ": base=[";
            for(int i = 0; i < len; i++)
            os << base[i] << "";
            os << "]";
            return os;
        }

    protected:
        char get(short i){
            return base[i%len];
        }
};

class B: public A{
    public:
         string str;
         double k;

    public:
        B(short m, double p): A::A(m){
            string s="";
            for(int i=0; i<A::getLen(); i++){
                s+=A::get(i);
            }
            str=s;
        }
        double foo(short s){
            return (sin(k+s))/(log(s+1));
        }
        string extract(short x){
            string s="";
            for(int i=0; i<x; i++){
                s+=rand()%(A::getLen()-0+1)+0;
            }
            return s;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", str=" << str << ", k=" << k << ", extract(3)=" <<extract(3);
            return os;
        }
};

class C: public A {
    private:
        int y;

    public:
        C(short n, int k): A::A(n){}
        string extract(short x){
            string vocali="AEIOUaeiou", s="";
            for(int i=0; i<A::getLen(); i++){
                if(vocali.find(A::get(i)) == string::npos){
                    s+=A::get(i);
                }
            }
            return s;
        }
        short g(short w){
            return sin(w+y);
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", y=" << y << ", extract(3)=" << extract(3);
            return os;
        }
        C &operator++(){
			y++;		   
			return *this;
		}  
};

int main(){
    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        switch (rand() % 2){
        case 0:
            vett[i] = new C(n, rand() % 20 + 1);
            break;
        case 1:
            vett[i] = new B(n, rand() / (double)RAND_MAX);
            break;
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << vett[i] << endl;
    }

    cout << "Punto 2 " << endl;
	int media1=0, media2=0, c1=0, c2=0;

    for(int i=0;i<DIM;i++){
        if(typeid(*vett[i])==typeid(B)){
			media1+=(dynamic_cast<B*>(vett[i]))->foo(5);
            c1++;
		}
        if(typeid(*vett[i])==typeid(C)){
			media2+=(dynamic_cast<C*>(vett[i]))->g(5);
            c2++;
		}
	}

    cout << "Avg(foo(5))=" << media1/(double)c1 << "Avg(g(5)" << media2/(double)c2 << endl;

    cout << "Punto 3: " << endl;
		cout<< "*vett[0]: " << vett[0]<<endl;	
		C *ptr_c = dynamic_cast<C*>(vett[0]);     
		++(*ptr_c);
		cout << ptr_c <<endl;
}

