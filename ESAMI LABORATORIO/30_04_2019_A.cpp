#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>

#define DIM 50

using namespace std;

class A{
    private:
        char *str;
        short len;

    public:
        A(short m, string source) {
            this->len=m;
            str=new char[len];
            for(int i=0; i<len; i++){
                int c=rand()%((source.length()-1)-0+1)+0;
                str[i]=source[c];
            }
        }
        virtual char func(short i)=0;
        short getLen(){
            return len;
        }

        virtual ostream &put(ostream &os){
        os << typeid(*this).name() << ", str = ";
        for(int i=0; i<getLen(); i++){
            os << get(i);
        }
        os << " ,";
        return os;
        }

    protected:
        char get(short i){
            return str[i%len];
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        short p;

    public:
        B(short m, string source) : A(m, source){
            int c=0;
            string s="AEIOUaeiou";
            for(int i=0; i<getLen(); i++){
                if(s.find(get(i)) != string::npos){
                    c++;
                }
            }
            this->p=c;
        }
        char func(short i){
            string s="QWRTYPSDFGHJKLZXCVBNMqwrtypsdfghjklzxcvbnm";
            for(int j=i; j<getLen(); j++){
                if(s.find(get(j)) != string::npos){
                    return get(j);
                }
            }
            return 'X';
        }

        ostream &put(ostream &os){
        A::put(os);
        os << "p=" << p << ", func(3)=" << func(3);
        return os;
        }
};

class C : public A{
    private:
        char x;

    public:
        C(short n, string source, char y) : A(n, source){
            this->x=y;
        }
        char func(short i){
            for(int j=i; j<getLen(); j++){
                if(get(j) >= x){
                    return get(j);
                }
            }
            return x;
        }
        string g(char c){
            string s="";
            s+=x;
            for(int i=0; i<getLen(); i++){
                s+=get(i);
            }
            s+=c;
            return s;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << "x=" << x << ", func(3)=" << func(3);
        return os;
        }
};

int main(){
    srand(111222333);
    A* vett[DIM];
    string S = "supercalifragilistichespiralidoso" ;
    for (int i = 0; i < DIM; i++){
        short n = 3 + rand() % 10;
        if(rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z'-'a'+1)+'a'));
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    string concat="";
    

    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i])==typeid(C)){
            concat += (dynamic_cast<C*>(vett[i])->g('h'));
            //cout << (dynamic_cast<C*>(vett[i])->g('h')) << endl;
        }
    }

    cout << "concat = " << concat;

    return 0;
}