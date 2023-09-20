#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <climits>

#define DIM 50

using namespace std;

class A{
    private:
        char *str;
        short len;

    public:
        A(short m){
            len=m;
            str=new char[m];
            for(int i=0; i<len; i++){
                str[i]=rand()%(( int ) 'z' - (int) 'a' + 1) + (int) 'a';
            }
        }
        virtual double const elab(short a)=0;
        short getLen(){
            return len;
        }

        virtual ostream &put(ostream &os){
            os << typeid(*this).name();
            os << ", w= ";
            for(int i=0; i<len; i++){
                os << str[i];
            }
            return os;
        }

    protected:
        short const get(short i){
            return str[i%len];
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int p;

    protected:
        short* const map(){
            short* array=new short[A::getLen()];
            string vocali="AEIOUaeiou";
            for(int i=0; i<A::getLen(); i++){
                if(vocali.find(A::get(i)) != string::npos)
                    array[i]=0;
                else 
                    array[i]=1;
            }
            return array;
        }

    public:
        B(short m, int x): A::A(m){
            p=x;
        }
        double const elab(short a){
            short somma=0;
            short* array=map();
            for(int i=0; i<A::getLen(); i++){
                somma+=array[i];
            }
            return somma/(double)p;
        }

        ostream &put(ostream &os){
            A::put(os);
            os << ", p=" << p << ", elab(3)=" << elab(3);
            return os;
        }

        B &operator ++(int){
			B aux = *this;
			p++;
			return *this;
		}   
};

class C : public A{
    private:
        char x;

    public:
        C(short n, char c): A::A(n){
            x=c;
        }
        double const elab(short r){
            int c=0;
            for(int i=r%A::getLen(); i<A::getLen(); i++){
                if(A::get(i) >= x){
                    c++;
                }
            }
            return c/(double)A::getLen();
        }
        string const g(char c){
            string s="";
            s+=x;
            s+=c;
            return s; 
        }

        ostream &put(ostream &os){
            A::put(os);
            os << ", x=" << x << ", alab(3)=" << elab(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A *vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10 + 1);
        else
            vett[i] = new C(n, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }
    cout << endl;

    //PUNTO 2
    cout << "PUNTO 2" << endl;
    double media=0;
    string s="";
    for(int i=0; i<DIM; i++){
        media+=vett[i]->elab(3);
        if(typeid(*vett[i])==typeid(C)){
            s+=(dynamic_cast<C*>(vett[i]))->g('h');
        }
    }

    cout << "Avg=" << media/DIM << ", concat= " << s << endl;
    cout << endl;

    //PUNTO 3
    cout << "PUNTO 3" << endl;
    cout << "0): " << *vett[0] << endl;
    B *ptr_b = dynamic_cast<B*>(vett[0]); 
	(*ptr_b)++;
	cout << "0): " << *vett[0] << endl;
}