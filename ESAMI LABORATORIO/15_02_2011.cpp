#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <typeinfo>
#include <string>
#include <sstream>
#include <climits>
#include <random>

#define DIM 50

using namespace std;

class D{
    private:
        char x;

    public:
        D(char c){
            this->x=c;
        }
        char getX(){
            return x;
        }
        string tostring(){}
};

class E : public D{
    private:
        char y;

    public:
        E(char c1, char c2) : D(c1){
            this->y=c1;
        }
        string coppia(){
            string s="";
            s+=getX();
            s+=y;
            return s;
        }
        string tostring(){}
};

class A{
    private:
        int x;

    public:
        A(int i) {
            this->x=i;
        }
        int getX(){
            return x;
        }
        virtual float f(byte)=0;
        string tostring(){

        }
};

class B : public A{
    private:
        D obj;

    public:
        B(int i, char c1, char c2) : A(i){
            obj=E(c1, c2);
        }
        string f(){
            return obj.coppia()+(char)(getX());
        }
        float f(byte){
            return x+byte;
        }
        string tostring(){}
};

class C : public A{
    private:
        int* a;

    public:
        C(int p) {
            Random r=new Random(p)
        }

        ostream &put(ostream &os){
        A::put(os);

        //...

        return os;
        }
};

int main(){
    return 0;
}