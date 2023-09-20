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
        float *x;

    public:
        A(float a) {
            x=new float[10];
            x[0]=a;
            for(int i=1; i<10; i++){
                x[i]=sin(100*x[i-1]);
            }
        }
        virtual float f()=0;
        float* getX(){
            return x;
        }
        string tostring(){
            cout << "[";
            for(int i=0; i<10; i++){
                cout << x[i] << " ";
            }
        }
};

class B : public A{
    public:
        B(float f) : A(f){}
        float f(){
            float* array=getX();
            float max=array[0];
            for(int i=0; i<10; i++){
                if(array[i] > max){
                    max = array[i];
                }
            }
            return max;
        }
        string tostring(){

        }
};

class C : public A{
    public:
        C(float f) : A(f){}
        float f(){
            float* array=getX();
            float media=0.0;
            for(int i=0; i<10; i++){
                media+=array[i];
            }
            return media/10;
        }
        int gte(float thr){
            float* array=getX();
            int c=0;
            for(int i=0; i<10; i++){
                if(array[1] > thr){
                    c++;
                }
            }
            return c;
        }
        string tostring(){

        }
};

class D{
    private:
        A &a;
        B b;
        C c;

    public:
        D(float seed){
            if(seed > 0.5)
                a=B(seed);
            else
                a=C(seed);
            
            b=B(seed/2);
            c=C(seed/3);
        }

};

int main(){
    return 0;
}