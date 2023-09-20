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
        char *str;
        short len;

    protected:
        char get(short i){
            return str[i%len];
        }

    public:
        A(short m, string source){
            len=m;
            str=new char[len];
            string s="";
            for(int i=0; i<source.length(); i++){
                if(source[i]=='a' || source[i]=='e' || source[i]=='i' ||source[i]=='o' || source[i]=='u' || source[i]=='A' || source[i]=='E' || source[i]=='I' || source[i]=='O' ||source[i]=='U'){
                    s+=source[i];
                }
            }
            for(int i=0; i<source.length(); i++){
                if(source[i]!='a' || source[i]!='e' || source[i]!='i' ||source[i]!='o' || source[i]!='u' || source[i]!='A' || source[i]!='E' || source[i]!='I' || source[i]!='O' ||source[i]!='U'){
                    s+=source[i];
                }
            }
            for(int i=0; i<len; i++){
                str[i]=s[i];
            }
        }
        virtual string fun(short k)=0;
        short getLen(){
            return len;
        }
        virtual ostream& put(ostream& os) {
            string s = "";
            for(int i = 0; i < len; i++) s += str[i];
            os << typeid(*this).name() << ", str = " << s << ", ";
            return os;
        }
        string operator()(int i1, int i2){
            string s="";
            for(int i=i1; i<=i2; i++){
                s+=A::get(i);
            }
            return s;
        }
};

ostream& operator<<(ostream& os, A& obj){
    return obj.put(os);
}

class B: public A{
    private:
        short q;

    public:
        B(short m, string source): A::A(m ,source){
            q=1+(rand()%A::getLen());
        }
        string fun(short k){
            string s="";
            string inversa="";
            for(int i=getLen(); i>=0; i--){
                s+=A::get(i);
            }
            for(int i=0; i<k; i++){
                inversa+=s[i];
            }
            return inversa;
        }
        virtual ostream& put(ostream& os){
            A::put(os);
            os << ", q=" << q << ", fun(3)=" << fun(3);
            return os;
        }
};

class C: public A{
    private:
        char y;

    public:
        C(short n, string source, char y): A::A(n, source){
            this->y=y;
        }
        string fun(short k){
            string s="";
            string inversa="";
            for(int i=A::getLen(); i>=0; i--){
                inversa+=A::get(i);
            }
            for(int i=k; i<A::getLen(); i++){
                s+=inversa[i];
            }
            return s;
        }
        string g(char c){
            string s="";
            s+=y;
            for(int i=0; i<A::getLen(); i++){
                s+=A::get(i);
            }
            s+=c;
            return s;
        }
        virtual ostream& put(ostream& os){
            A::put(os);
            os << ", y=" << y << ", fun(3)=" << fun(3);
            return os;
        }
};

int main(){
    srand(111222333);
    string S;

    short fa = 3;
    A* vett[DIM];

    for (int i = 0; i < DIM; i++){
        short n = 10 + rand() % 10;
        S = "";
        for (int k = 0; k < 20; k++)
            S += rand() % ('z' - 'a' + 1) + 'a';
        if (rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i] << endl;
    }

    cout << "PUNTO 2" << endl;
    string s="";
    int j=0;
    for(int i=DIM-1; i>=0; i--){
        if(typeid(*vett[i])==typeid(C)){
            cout <<"j=" << j << ", g('X')=" << (dynamic_cast<C*>(vett[i]))->g('X') << endl;
            break;
        }
    }

    cout << "PUNTO 3" << endl;
    cout << "*vett[5]=" << *vett[5] << endl;
    cout << "vett[5](1, 3)=" << (*vett[5])(1, 3) << endl;
}