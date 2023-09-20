#include <iostream>
using namespace std;

int main(){
    int h=5;
    int g=8;
    const int* ptr=&h;
    cout << *ptr << endl;
    ptr=&g;
    //*ptr=5;

    int* const ptr2=&h;
    *ptr2=7;
    cout << *ptr2 << endl;
    int y=9;
    //ptr2=&y;

    const int* const ptr3=&h;
    //*ptr3=5;
    //ptr3=&y;


    int a[5]={1, 2, 3, 4, 5};
    cout << a << endl;
    cout << *a << endl;

    char c[]="ciao";
    cout << c << endl;
    cout << *c <<  endl;
    cout << *(c+1) << endl;

    int *b=new int[5];
    for(int i=0; i<5; i++) b[i]=i;
    cout << b << endl;
    cout << *b << endl;

    int *p=a;
    cout << p << endl;
    cout << *p << endl;
    p++;
    cout << p << endl;
    cout << *p << endl;

    int r=5;
    int *t=&r;
    int **f=&t;
    cout << &r << endl;
    cout << &t << endl;
    cout << f << endl;
    cout << *f << endl;
    cout << **f << endl;
}