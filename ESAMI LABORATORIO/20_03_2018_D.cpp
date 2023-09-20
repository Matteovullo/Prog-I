#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 50

using namespace std;

class A{
    private:
        string sa;

    public:
        A(string s1, string s2) {
            this->sa="";
            string vocali="AEIOUaeiou";
            for(int i=0; i<s1.length(); i++){
                if(vocali.find(s1[i]) != string::npos){
                    this->sa+=s1[i];
                }
            }
            for(int i=0; i<s2.length(); i++){
                if(isupper(s2[i])){
                    this->sa+=s2[i];
                }
            }
        }
        virtual bool v(char c, short n)=0;
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        os << ": sa=" << sa;
        return os;
        }

    protected:
        short num(char c){
            bool found=false;
            for(int i=0; i<sa.length(); i++){
                if(sa[i] == c){
                    found=true;
                }
                if(found == true){
                    c++;
                }
            }
            return -1;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        int *vec;
        short len;

    public:
        B(string w, short k) : A(w.substr(0, k), w.substr(k, w.length()-1)){
            vec=new int[w.length()];
            this->len=w.length();
            for(int i=0; i<len; i++){
                vec[i]=(int)w[i];
            }
        }
        bool v(char c, short n){
            if(num(c) >= n){
                return true;
            }else{
                return false;
            }
        }
        ostream &put(ostream &os){
        A::put(os);
        os << " { vec=[";
        for(int i=0; i<len; i++){
            os << vec[i] << " ";
        }
        os << "], len=" << len << "}" << endl;
        return os;
        }
};

class C : public A{
    private:
        float y;
        string diff;

    public:
        C(string s1, string s2) : A(s1, s2){
        }
        bool v(char c, short n){
            if(diff[c] >= n){
                return true;
            }else{
                return false;
            }
        }
        float f(){
            return log(y);
        }
        ostream &put(ostream &os){
        A::put(os);
        os << " { y = " << y << ", diff=" << diff << "}" << endl;
        return os;
        }
};

int main(){
    srand(111222333);
    A *vett[DIM];

    string s1, s2;
    short l1, l2;
    short k;

    for (int i = 0; i < DIM; i++){
        if (rand() % 2 == 0){
            s1 = "";
            l1 = rand() % 10 + 5;
            k = rand() % (l1 / 2) + 1;

            for (int j = 0; j < l1; j++)
                s1 += ((rand() % 2) ? (char)(rand() % 25 + 'a') : (char)(rand() % 25 + 'A'));

            vett[i] = new B(s1, k);
        }
        else{
            s1 = "";
            s2 = "";
            l1 = rand() % 20 + 6;
            l2 = rand() % 20 + 6;
            for (int j = 0; j < l1; j++)
                s1 += (rand() % 2 ? (char)(rand() % 25 + 'a') : (char)(rand() % 25 + 'A'));

            for (int k = 0; k < l2; k++)
                s2 += (rand() % 2 ? (char)(rand() % 25 + 'a') : (char)(rand() % 25 + 'A'));

            vett[i] = new C(s1, s2);
        }
    }

    //PUNTO 1
    cout << "PUNTO 1" << endl;
    for(int i = 0; i < DIM; i++) {
        cout << i << ")" << *vett[i] << endl;
    }

    //PUNTO 2
    cout << "Indici= ";
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            if(dynamic_cast<B*>(vett[i])->v('b', 2)){
                cout << i << " ";
            }
        }
        if(typeid(*vett[i]) == typeid(C)){
            if(dynamic_cast<C*>(vett[i])->v('b', 2)){
                cout << i << " ";
            }
        }
    }
    cout << endl;

    //PUNTO 3
    float media=0.0;
    int c=0;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            c++;
            media += dynamic_cast<C*>(vett[i])->f();
        }
    }

    cout << "Avg(f())=" << media/c << endl;

    return 0;
}