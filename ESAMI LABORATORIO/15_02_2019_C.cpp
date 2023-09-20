#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>

#define DIM 50

using namespace std;

class A{
    private:
        char* str;
        short len;

    public:
        A(short m) {
            this->len=m;
            str=new char[len];
            for(int i=0; i<len; i++){
                str[i]=rand()%('z'-'a'+1)+'a';
            }
        }
        virtual double const elab(short a)=0;
        short const getLen(){
            return len;
        }
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        os << ", str= ";
        for(int i=0; i<getLen(); i++){
            os << get(i);
        }
        os << ", ";
        return os;
        }

    protected:
        char const get(short i){
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
        short* map(){
            string s="AEIOUaeiou";
            short* array=new short[getLen()];
            for(int i=0; i<getLen(); i++){
                if(s.find(get(i)) != string::npos){
                    array[i]=1;
                }else{
                    array[i]=0;
                }
            }
            return array;
        }

    public:
        B(short m, int x) : A(m){
            this->p=x;
        }
        double const elab(short a){
            int somma=0;
            short* array=map();
            for(int i=0; i<getLen(); i++){
                somma+=array[i];
            }
            return somma/(double)p;
        }
        ostream &put(ostream &os){
        A::put(os);
        os << "p=" << p << ", elab(3)=" << elab(3) << endl;        
        return os;
        }
        B &operator ++(int){
			B aux = *this;
			p++;		   //prefisso per oggetti B
			return *this;
		}   
};

class C : public A{
    private:
        char x;

    public:
        C(short n, char c) : A(n){}
        double const elab(short r){
            int c=0;
            for(int i=r%getLen(); i<getLen(); i++){
                if(get(i) >= x){
                    c++;
                }
            }
            return c/(double)(getLen());
        }
        string const g(char c){
            string s="";
            s+=x;
            s+=c;
            return s;
        }
        ostream &put(ostream &os){
        A::put(os);
        os << "x=" << x << "elab(3)=" << elab(3) << endl;
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

    //PUINTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }
    
    //PUNTO 2
    int media=0;
    string s="";
    int c=0;
    for(int i=0; i<DIM; i++){
        media+=vett[i]->elab(3);
        c++;
        if(typeid(vett[i])==typeid(C)){
            string p=dynamic_cast<C*>(vett[i])->g('h');
            s+=p;
        }
    }

    cout << "Avg=" << media/(double)c << ", concat=" << s << endl;;

    //PUNTO 3
    cout<< *vett[0]<<endl;	
	B *ptr_b = dynamic_cast<B*>(vett[0]);      
	(*ptr_b)++;
	cout<<*ptr_b<<endl;

    return 0;
}