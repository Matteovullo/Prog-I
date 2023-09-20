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
        A(short w, char c1, char c2){
            str=new char[w];
            for(int i=0; i<w; i++){
                str[i]=rand()%(c2-c1+1)+c1;
            }
            len=w;
        }
        virtual short f(short k)=0;

        protected:
            string extract(short k){
                string s="";
                if(k >= len){
                    for(int i=0; i<len; i++){
                        s+=str[i];
                    }
                }else{
                    for(int i=len-1; i>=k; i--){
                        s+=str[i];
                    }
                }
                return s;
            }

};

class B: public A{
    private:
        char z;

    public:
        B(short m, char c1, char c2): A(m, c1, c2){
            string s=extract(m/2+1);
            z=s[rand()%(m/2+1)];
        }
        short f(short k){
            short c;
            string s=extract(k);
            for(int i=0; i<k; i++){
                if(s[i] <= z)
                    c++;
            }
            return c;
        }
};

template <typename T>
class C: public A{
    private:
        T ss;

    public:
        C(short w, char c1, char c2): A(w, c1, c2){
            if(typeid(string)==typeid(ss))
                ss=extract(w/2+1);
            else
                ss=w;
        }
        short f(short k){
            string s=extract(k);
            for(int i=0; i<k; i++){
                if(s[i] >= (int)'A' && s[i] <= (int)'Z')
                return 1;
            }
            return 0;
        }
        T foo(short x){
            return pow(ss,x);
        }
};

int main(){

}