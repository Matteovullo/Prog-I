#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#define DIM 50

using namespace std;

class A{
    private:
        char *str;
        short len;

    public:
        A(short m, string source){
            str= new char[m];
            for(int i=0; i<m; i++){
                int r=rand()% (source.length()-0+1)-0;
                str[i]=source[r];
            }
            len=m;
        }
        virtual char fun(short i) = 0;
        short getLen() const {return this->len;}

        virtual ostream& put(ostream& os) {
            string s = "";
            for(int i = 0; i < this->len; i++) {
                s += str[i];
            }
            return os << typeid(*this).name() << ", str = " << s;  
        }
        string operator()(int i1, int i2){
            string s="";
            for(int i=i1; i<i2; i++){
                s+=str[i];
            }
            return s;
        }
    
    protected:
        char get(short i){
            return str[i%this->len];
        }

};

ostream& operator << (ostream& s, A& obj) {
    return obj.put(s);
}

class B: public A{
    private:
        short p;
    
    public:
        B(short m, string source): A(m, source){
            this->p = 1;
            for(int i = 0; i < m; i++) {
                switch(toupper(A::get(i))) {
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U': {
                        this->p += 1;
                        break;
                    }
                }
            }
        }
        char fun(short i){
            string s="AEIOUaeiou";
            for(int j=i; i<getLen(); j++){
                if(s.find(get(j)) == string::npos){
                    return get(i);
                }
            }
            return 'X';
        }
};

class C: public A{
    private:
        char x;
    
    public:
        C(short n, string source, char y): A(n, source){
            x=y;
        }
        char fun(short i){
            for(int j=i; j<getLen(); j++){
                if(get(j) > x){
                    return get(j);
                }
            }
            return x;
        }
        string g(char c){
            string h="";
            h+=x;
            for(int i=0; i<getLen(); i++){
                h+=get(i);
            }
            h+=c;
            return h;
        }
};

int main(){
    srand(111222333);
    A* vett[DIM];

    string S = "supercalifragilistichespiralidoso";

    for (int i = 0; i < DIM; i++) {
        short n = 3 + rand() % 10;
        if (rand() % 2 == 0)
            vett[i] = new B(n, S);
        else
            vett[i] = new C(n, S, (char)(rand() % ('z' - 'a' + 1) + 'a'));
    }

    //Punto (1)
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i];
    }

    cout << "PUNTO 2" << endl;
    string s="";
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i])==typeid(C)){
            s += (dynamic_cast<C*>(vett[i]))->g('h');
        }
    }
    cout << "concat=" << s << endl;

    cout << "PUNTO 3" << endl;
    cout << "vett[5]" << *vett[5] << endl;
    cout << "vett[5](1,3)" << (*vett[5])(1,3) << endl;
}