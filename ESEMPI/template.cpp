#include <iostream>
using namespace std;

template<typename T>
T somma(T a, T b){
    return a+b;
}

template<typename T>
T somma(T a, T b, T c){
    return a+b+c;
}

template<class C>
class A{
    C x;

    public:
        A(C x){
            this->x=x;
        }
        template<class Y>
        Y foo(Y a){
            return a+x;
        }
        //int f(int y) const{
        //     x++;
        //     return x;
        //}
};

int somma(int a, int b){
    cout << "1" << endl;
    return a+b;
}

int somma(int a, double b){
    cout << "2" << endl;
    return a+(int)b;
}

int main(){
    //cout << somma<int>(5, 5) << endl;
    //cout << somma<int>(5, 10, 5) << endl;
    //A<int> a(5);
    //cout << a.foo<double>(5.5) << endl;
    //cout << a.f(5) << endl;

    
    /*int x[4] = {1, 2, 3, 4};

    cout << *(x) << endl;
    cout << *(x+1) << endl;
    cout << *(x+2) << endl;
    cout << *(x+3) << endl;
    cout << *(x+4) << endl;
    cout << x[4] << endl;

    x[4]=6;
    *(x+4)=10;

    cout << *(x+4) << endl;
    cout << x[4] << endl;

    cout << sizeof(string) << endl;
    cout << sizeof("123456789") << endl;*/


    somma(2.5, 2.5);

    char a[]="ciao";
    char b[]={'c', 'i', 'a', 'o', '\0'};
    char c[]={'c', 'i', 'a', 'o', 0};
    char d[50]="ciao"; 
    cout << a << " " << b << " " << c << " " << d << " " << endl;

    string s="ciao";
    const char *e=s.c_str();
    cout << e << endl;

}