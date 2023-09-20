#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>

#define DIM 50

using namespace std;

class A{
    protected:
        string x;

    public:
        A(string s) {
            this->x=s;
        }
        string getX(){
            return x;
        }
        virtual string select()=0;
        bool moreThan3(){
            for(int i=0; i<x.length(); i++){
                char c=x[i];
                for(int j=0; j<x.length(); i++){
                    if(i!=j && c==x[j]){
                        c++;
                    }
                    if(c==3){
                        return true;
                    }
                }
            }
            return false;
        }

        virtual ostream &put(ostream &os){
        os << "{ " << " x=" << "'" << x << "'";
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        string y;
        float f;

    public:
        B(string s, float f) : A(s){
            A::x="";
            for(int i=0; i<10; i++){
                A::x+=s[i];
            }
            if(A::x.length() > 10){
                for(int i=10; A::x.length(); i++){
                    x+=s[i];
                }
            }
            this->f=f;
        }
        char extract(){
            stringstream ss;
            ss << f;
            string s=ss.str();
            char h[s.length()];
            for(int i=0; i<s.length(); i++){
                h[i]=s[i];
            }
            return y[atoi(h)];
        }
        string select(){
            string s="";
            string vocali="AEIOUaeiou";
            for(int i=0; i<x.length(); i++){
                if(vocali.find(x[i]) != string::npos){
                    s+=x[i];
                }
            }
            for(int i=0; i<x.length(); i++){
                if(vocali.find(x[i]) != string::npos){
                    s+=y[i];
                }
            }
            return s;
        }

        ostream &put(ostream &os){
        os << y;
        return os;
        }
};

class C : public A{
    private:
        short *b;
        short n;

    public:
        C(string s) : A(s){
            x="";
            for(int i=0; i<10; i++){
                x+=s[i];
            }
            this->n=s.length();
            b=new short[n];
            for(int i=0; i<n; i++){
                b[i]=(short)(s[i]%5);
            }
        }
        string select(){
            string s="";
             for(int i=0; i<n; i++){
                s+=x[b[i]];
             }
             return s;
        }

        ostream &put(ostream &os){
        A::put(os);
        os << " b=[ ";
        for(int i=0; i<n; i++){
            os << b[i] << " ";
        }
        os << "] }";
        return os;
        }
};

int main(){
    srand(111222333);
    A* vett[DIM];
    for (int i = 0; i < DIM; i++){
        string str = "";
        for (int j = 0; j < 20; j++)
            str += (char)('a' + rand() % 12);
        if (rand() % 2 == 1)
            vett[i] = new B(str, (float)rand() / RAND_MAX);
        else
            vett[i] = new C(str);
    }

    //PUNTO 1
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }
    
    //PUNTO 2
    int c=0;
    cout << "1) ";
    for(int i=0; i<DIM; i++){
        if (vett[i]->moreThan3()){
            cout << i << " ";
        }
    }
    cout << endl;

    string s="";
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i])==typeid(B)){
            s+=dynamic_cast<B*>(vett[i])->extract();
        }
    }

    cout << "2)" << s;

    return 0;
} 