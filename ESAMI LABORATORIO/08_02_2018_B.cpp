#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>

#define DIM 30

using namespace std;

class A{
    private:
        string w;

    public:
        A(string s) {
            this->w=s;
        }
        int getSum(){
            int somma=0;
            for(int i=0; i<w.length(); i++){
                somma+=(int)(w[i]);
            }
            return somma+1;
        }
        virtual float* values()=0;
        virtual ostream &put(ostream &os){
        os << typeid(*this).name();
        os << "w=" << w;
        return os;
        }
};

ostream &operator<<(ostream &os, A &obj){
    return obj.put(os);
}

class B : public A{
    private:
        string s;
        int l;

    public:
        B(string s1, string s2, short n) : A(s1.substr(s.length()-n)+s2.substr(0, s2.length()-n)){
            this->s="";
            if(s1.length() < s2.length()){
                for(int i=0; i<s1.length(); i++){
                    if(i%2 == 0){
                        s+=isupper(s2[i]);
                    }else{
                        s+=islower(s1[i]);
                    }
                }
            }
            if(s2.length() < s1.length()){
                for(int i=0; i<s2.length(); i++){
                    if(i%2 == 0){
                        s+=toupper(s2[i]);
                    }else{
                        s+=tolower(s1[i]);
                    }
                }
            }
            this->l=s.length();
        }
        float* values(){
            float* array=new float[s.length()];
            for(int i=0; i<s.length(); i++){
                array[i]=((int)(s[i]))/(float)(getSum());
            }
            return array;
        }
        double res(){
            float* array=values();
            float somma=0.0;
            for(int i=0; i<s.length(); i++){
                somma+=array[i]*array[i];
            }
            return sqrt(somma);
        }
        ostream &put(ostream &os){
        A::put(os);
        os << ", s=" << s;
        return os;
        }
};

class C : public A{
    private:
        string t;
        int len;

    public:
        C(string s, int n, int k) : A(s.substr(0, n)+s.substr(s.length()-k)){
            this->t="";
            for(int i=0; i<s.length(); i++){
                if(isupper(s[i])){
                    t+=tolower(s[i]);
                }else{
                    t+=toupper(s[i]);
                }
            }
            this->len=t.length();
        }
        float* values(){
            float* array=new float[len];
            for(int i=0; i<len; i++){
                array[i]=(getSum()/(float)(len*(i+1)));
            }
            return array;
        }
        short moreThan05(){
            int c=0;
            float* array=values();
            for(int i=0; i<len; i++){
                if(array[i] >= 0.5){
                    c++;
                }
            }
            return c;
        }
        ostream &put(ostream &os){
        A::put(os);
        os << ", t=" << t;
        return os;
        }
};

int main(){
    srand(111222333);
    A* vett[DIM];
    for (int i = 0; i < DIM; i++){
        string str1 = "" ;
        string str2 = "" ;
        if(rand() % 2 == 0){
            short l1 = rand() % 5 + 3;
            short l2 = rand() % 5 + 6;
            for (int j = 0; j < l1; j++)
                str1 += ((char)( 'a' + rand() % 25));
            for (int j = 0; j < l2; j++)
                str2 += ((char)( 'a' + rand() % 25));
            short n = rand() % 3 + 1;
            vett[i] = new B(str1, str2, n);
        }
        else{
            for(int j = 0; j < 10; j++){
                int r = rand();
                if(r % 2 == 0)
                    str1 += ((char)( '0' + rand() % 9));
                else if(r % 3 == 0)
                    str1 += ((char)( 'a' + rand() % 25));
                else
                    str1 += ((char)( 'A' + rand() % 25));
            }
            vett[i] = new C(str1, rand() % 3 + 1, rand() % 6 + 1);
        }
    }

    cout << "PUNTO 1" << endl;
    for(int i=0; i<DIM; i++){
        cout << i << ")" << *vett[i]<< endl;
    }
    cout << "res() di 2+16" << dynamic_cast<B*>(vett[2])->res()+dynamic_cast<B*>(vett[16])->res();

    cout << "PUNTO 2" << endl;
    cout << "indici >= 5 : ";
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(C)){
            if(dynamic_cast<C*>(vett[i])->moreThan05() >= 5){
                cout << i << ", ";
            }
        }
    }

    cout << "PUNTO 3" << endl;
    int media=0;
    int max=INT_MIN;
    int min=INT_MAX;
    for(int i=0; i<DIM; i++){
        if(typeid(*vett[i]) == typeid(B)){
            if(dynamic_cast<B*>(vett[i])->getSum() > max){
                max = dynamic_cast<B*>(vett[i])->getSum();
            }
            if(dynamic_cast<B*>(vett[i])->getSum() > min){
                min = dynamic_cast<B*>(vett[i])->getSum();
            }
            media+=dynamic_cast<B*>(vett[i])->getSum();
        }
    }

    cout << "max=" << max << ", min=" << min << ", media=" << media;

    return 0;
}