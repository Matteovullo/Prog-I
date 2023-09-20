#include <iostream>
#include <cmath>
#include <climits>
#include <typeinfo>
#include <cstdlib>
#define DIM 50

using namespace std;

class A{
    private:
        char* s;
        short len;

    public:
        A(short m){
            s=new char[m];
            for(int i=0; i<m; i++){
                s[i]=rand()%('z'-'a'+1)+'a';
            }
            len=m;
        }
        virtual double elab(short a)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os){
            os << typeid(*this).name() << ", s=";
            for(int i=0; i<len; i++){
                os << s[i];
            }
            return os;
        }

    protected:
        char get(short i){
            return s[i%len];
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        int p;

    public:
        B(short m, int x): A::A(m){
            p=x;
        }
        double elab(short a){
            int C=0, V=0;
            for(int i=0; i<A::getLen(); i++){
                switch(A::get(i)){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':{
                        V++;
                        break;
                    }
                    default: {
                        C++;
                        break;
                    }
                }
            }
            return V/(double)(C+1);
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", p=" << p << ", elab(3)=" << elab(3);
            return os;
        }
        B &operator ++(int){
			B aux = *this;
			p++;
			return *this;
		}  

    protected:
        bool test(){
            for(int i=0; i<4; i++){
               switch(A::get(i)){
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':{
                        return true;
                    }
                } 
            }
            return false;
        }
};

class C: public A{
    private:
        char x;

    public:
        C(short n, char c): A::A(n){
            c=x;
        }
        double elab(short r){
            int c=0;
            for(int i=r; i<A::getLen(); i++){
                if(A::get(i) >= x){
                    c++;
                }
            }
            return c/(double)A::getLen();
        }
        string g(char c){
            string s="";
            for(int i=0; i<A::getLen(); i++){
                s+=A::get(i);
            }
            s+=c;
            return s;
        }
        ostream& put(ostream& os){
            A::put(os);
            os << ", x=" << x << ", elab(3)=" << elab(3);
            return os;
        }
};

int main(){
    srand(111222333);

    A* vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 1 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, rand() % 10 + 1);
        else
            vett[i] = new C(n, (char)(rand() % ((int)'z' - (int)'a' + 1) + (int)'a'));
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << "PUNTO 2" << endl;
    double somma=0;
    string concat="";
    for(int i=0; i<DIM; i++){
        somma+=vett[i]->elab(3);
        if(typeid(C)==typeid(*vett[i])){
            concat+=(dynamic_cast<C*>(vett[i]))->g('h');
        }
    }
    cout << "Avg= " << somma/(double)DIM << ", ";
    cout << "concat=" << concat << endl;

    //PUNTO 3
    cout << "PUNTO 3" << endl;
    cout << "0): " << *vett[0] << endl;	
	B *ptr_b = dynamic_cast<B*>(vett[0]);    
	(*ptr_b)++;
	cout<<"0): " << *ptr_b<<endl;
}